/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotoyam <kmotoyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:59:59 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/20 15:41:45 by kmotoyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"lex.h"

t_env	*env_create_new(char *name, char *value)
{
	t_env	*d;

	d = (t_env *)malloc(sizeof(t_env) * 1);
	if (d == NULL)
		return (NULL);
	d->name = name;
	d->value = value;
	d->prev = NULL;
	d->next = NULL;
	return (d);
}

t_env	*env_last(t_env *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	env_add_back(t_env **lst, t_env *new)
{
	t_env	*tmp;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = env_last(*lst);
	if (tmp == NULL)
	{
		*lst = new;
		return ;
	}
	tmp->next = new;
	new->prev = tmp;
}

size_t	env_listren(t_env **lst)
{
	size_t		i;
	t_env		*tmp;

	if (lst == NULL || *lst == NULL)
		return (-1);
	tmp = *lst;
	i = 1;
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
