/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_make.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:06:02 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/21 12:56:52 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"lex.h"

char	*env_get_name(char *str)
{
	size_t	i;
	char	*ret;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			break ;
		i++;
	}
	ret = malloc(i + 1);
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, str, i + 1);
	ret[i] = '\0';
	return (ret);
}

int	check_exist_equal(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*env_get_value(char *str)
{
	int		flag;
	size_t	i;
	char	*ret;

	i = 0;
	flag = 0;
	if (check_exist_equal(str) == 0)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '=')
		{
			break ;
		}
		i++;
	}
	ret = ft_strdup(&str[i + 1]);
	return (ret);
}

t_env	**make_env_list(char **str, t_branch *branch)
{
	size_t	i;
	char	*name;
	char	*value;
	t_env	**env;

	i = 0;
	env = malloc(sizeof(t_env **) * 1);
	if (env == NULL)
	{
		free(branch);
		exit(EXIT_FAILURE);
	}
	*env = NULL;
	while (str[i] && str[i + 1])
	{
		name = env_get_name(str[i]);
		value = env_get_value(str[i]);
		env_add_back(env, env_create_new(name, value));
		i++;
	}
	return (env);
}

// int	main()
// {
// 	extern char **environ;
// 	t_env		**env;

// 	env = make_env_list(environ);
// 	show_env(env);
// 	return (0);
// }
