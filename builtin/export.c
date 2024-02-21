/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotoyam <kmotoyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:16:58 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/20 15:41:24 by kmotoyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../lexparse/lex.h"
#include"built.h"

void	export_error_message(char *str)
{
	ft_putstr_fd("minishell: export: `", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("\': not a valid identifier", STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

int	check_ok_export(char c)
{
	if (ft_isalpha(c) || c == '_')
		return (1);
	else
		return (0);
}

int	check_to_be_export(char *str, t_branch *branch)
{
	size_t	i;

	i = 0;
	if (str[i] == '=')
	{
		export_error_message(str);
		branch->exit_status = 1;
		return (1);
	}
	while (str[i] && str[i] != '=')
	{
		if (check_ok_export(str[i]) == 0)
		{
			export_error_message(str);
			branch->exit_status = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

void	base_export(char *str, t_branch *list)
{
	char	*name;
	char	*value;
	t_env	*tmp;

	if (check_exist_equal(str) == 0)
	{
		if (yet_env_exist(list->env, str))
			return ;
		name = ft_strdup(str);
		env_add_back(list->env, env_create_new(name, NULL));
	}
	else
	{
		name = env_get_name(str);
		value = env_get_value(str);
		tmp = yet_env_exist(list->env, name);
		if (tmp == NULL)
			env_add_back(list->env, env_create_new(name, value));
		else
		{
			free(tmp->value);
			tmp->value = value;
			free(name);
		}
	}
}

int	built_export(char **str, t_branch *list, int fd)
{
	size_t	i;
	int		j;
	int		ret;

	ret = 0;
	i = 1;
	if (str == NULL || *str == NULL)
		return (0);
	if (str[1] == NULL)
		show_all_export(list, fd);
	while (str[i])
	{
		j = check_to_be_export(str[i], list);
		if (j == 0)
			base_export(str[i], list);
		else
			ret = 1;
		i++;
	}
	return (ret);
}
