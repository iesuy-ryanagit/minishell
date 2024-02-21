/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotoyam <kmotoyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:59:59 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/20 15:42:07 by kmotoyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"lex.h"

t_token	*token_create_new(char *str, int start, int len)
{
	t_token	*d;

	d = (t_token *)malloc(sizeof(t_token) * 1);
	if (d == NULL)
		return (NULL);
	d->str = ft_substr(str, start, len);
	if (d->str == NULL)
	{
		free(d);
		return (NULL);
	}
	d->type = 0;
	d->prev = NULL;
	d->next = NULL;
	d->flag_to_split = 0;
	return (d);
}

t_token	*token_last(t_token *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	token_add_back(t_branch *branch, t_token *new)
{
	t_token	*tmp;

	if (new == NULL)
	{
		free_token_list(branch, 0);
		return ;
	}
	if (*(branch->list) == NULL)
	{
		*(branch->list) = new;
		return ;
	}
	tmp = token_last(*(branch->list));
	if (tmp == NULL)
	{
		*(branch->list) = new;
		return ;
	}
	tmp->next = new;
	new->prev = tmp;
}

size_t	token_listren(t_token **lst)
{
	size_t		i;
	t_token		*tmp;

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
