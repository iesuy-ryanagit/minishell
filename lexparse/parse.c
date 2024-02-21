/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotoyam <kmotoyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:30:03 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/20 15:42:08 by kmotoyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"lex.h"

void	classify_type_one(t_token *list, int flag)
{
	if (str_check_reduc_in(list->str))
		list->type = RED_IN;
	else if (str_check_reduc_out(list->str))
		list->type = RED_OUT;
	else if (str_check_chase(list->str))
		list->type = CHASE;
	else if (str_check_heredoc(list->str))
		list->type = HERE_DOC;
	else if (str_check_pipe(list->str))
		list->type = PIPE;
	else if (flag == 0 && (list->prev == NULL || list->prev->type < RED_IN))
		list->type = COMMAND;
	else
		list->type = OPTION;
}

void	make_branch_set_up(t_branch *branch, t_token *tmp)
{
	branch->command = malloc(sizeof(t_token *) * (get_count_pipe(&tmp) + 2));
	if (branch->command == NULL)
	{
		free(branch);
		free_token_list(branch, 3);
	}
}

void	make_branch_command(t_branch *branch)
{
	t_token		*tmp;
	size_t		i;
	int			flag;

	flag = 0;
	i = 0;
	tmp = *(branch->list);
	make_branch_set_up(branch, tmp);
	while (tmp != NULL)
	{
		if (tmp->type == COMMAND)
		{
			if (tmp->str == NULL)
				flag = 1;
			(branch->command)[i++] = tmp;
		}
		else if (flag == 1 && tmp->str != NULL)
		{
			tmp->type = COMMAND;
			(branch->command)[i++] = tmp;
			flag = 0;
		}
		tmp = tmp->next;
	}
	(branch->command)[i] = NULL;
}

void	classify_type_loop(t_token **list)
{
	int		flag;
	t_token	*tmp;

	tmp = *list;
	flag = 0;
	while (tmp)
	{
		classify_type_one(tmp, flag);
		if (tmp->type == COMMAND)
			flag = 1;
		if (tmp->type == PIPE)
			flag = 0;
		tmp = tmp ->next;
	}
}
