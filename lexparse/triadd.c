/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triadd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotoyam <kmotoyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:27:06 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/20 15:42:13 by kmotoyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"lex.h"

void	delete_null(t_branch *branch)
{
	t_token	*tmp;
	t_token	*save;
	int		flag;

	tmp = *(branch->list);
	while (tmp)
	{
		save = tmp;
		if (tmp->str == NULL)
		{
			if (tmp->type == COMMAND)
				flag = 1;
			if (tmp == *(branch->list))
				*(branch->list) = tmp->next;
			if (tmp->prev)
				tmp->prev->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = tmp->prev;
			free(tmp);
		}
		tmp = save->next;
	}
}

int	help_revive(t_token *tmp)
{
	if (tmp->prev == NULL || tmp->prev->type == 1 || tmp->prev->type == PIPE)
		return (1);
	else
		return (0);
}

void	revive_command(t_branch *branch)
{
	t_token	*tmp;
	int		flag;

	tmp = *(branch->list);
	flag = 1;
	while (tmp)
	{
		if (tmp->type == COMMAND)
				flag = 0;
		if (flag == 1 && tmp->type == OPTION && help_revive(tmp))
		{
			tmp->type = COMMAND;
			flag = 0;
		}
		if (tmp->type == PIPE)
			flag = 1;
		tmp = tmp->next;
	}
}
