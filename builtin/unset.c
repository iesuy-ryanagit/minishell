/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotoyam <kmotoyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:16:58 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/20 15:41:28 by kmotoyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../lexparse/lex.h"
#include"built.h"

t_env	*yet_env_exist(t_env **env, char *name)
{
	t_env	*tmp;

	if (env == NULL || *env == NULL)
		return (NULL);
	tmp = *env;
	while (tmp)
	{
		if (ft_strncmp(tmp->name, name, re_strlen(name)) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	delete_one_env(t_env **env, char *name)
{
	t_env	*todie;

	todie = yet_env_exist(env, name);
	if (todie->prev)
		todie->prev->next = todie->next;
	if (todie->next)
		todie->next->prev = todie->prev;
	free(todie->name);
	free(todie->value);
	free(todie);
}

void	built_unset(char **str, t_branch *list)
{
	size_t	i;

	i = 1;
	while (str[i])
	{
		if (yet_env_exist(list->env, str[i]) != NULL)
			delete_one_env(list->env, str[i]);
		i++;
	}
}

// void	built_export(char **str, t_branch *list)
// {
// 	size_t	i;

// 	printf("built_export");
// 	i = 1;
// 	if (str == NULL || *str == NULL)
// 		return ;
// 	while (str[i])
// 	{
// 		check_to_be_export(str[i]);
// 		base_export(str[i], list);
// 		i++;
// 	}
// }
