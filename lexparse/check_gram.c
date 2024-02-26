/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_gram.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:22:02 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/26 15:38:53 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"lex.h"

int	check_reduc(t_branch *branch)
{
	t_token	*tmp;
	int		flag;

	tmp = *(branch->list);
	flag = 0;
	while (tmp)
	{
		if (flag == 1 && tmp->type != OPTION)
		{
			syntax_error_message(tmp->str);
			return (1);
		}
		if (tmp->type == RED_IN || tmp->type == RED_OUT)
			flag = 1;
		else if (tmp->type == HERE_DOC || tmp->type == CHASE)
			flag = 1;
		else
			flag = 0;
		tmp = tmp->next;
	}
	if (flag == 1)
		syntax_error_message("newline");
	return (flag);
}

int	check_pipe(t_branch *branch)
{
	t_token		*tmp;
	int			flag;

	tmp = *(branch->list);
	if (tmp->type == PIPE)
	{
		syntax_error_message(tmp->str);
		return (1);
	}
	flag = 0;
	while (tmp)
	{
		if (flag == 1 && tmp->type == PIPE)
		{
			syntax_error_message(tmp->str);
			return (1);
		}
		if (tmp->type == PIPE)
			flag = 1;
		else
			flag = 0;
		tmp = tmp->next;
	}
	return (flag * -1);
}

int	check_pipe_nomessage(t_branch *branch)
{
	t_token		*tmp;
	int			flag;

	tmp = *(branch->list);
	if (tmp->type == PIPE)
		return (1);
	flag = 0;
	while (tmp)
	{
		if (flag == 1 && tmp->type != COMMAND)
			return (1);
		if (tmp->type == PIPE)
			flag = 1;
		else
			flag = 0;
		tmp = tmp->next;
	}
	return (flag * -1);
}

int	wait_complete_valid(t_branch *branch)
{
	char	*add;

	while (check_pipe_nomessage(branch) == -1)
	{
		add = readline("> ");
		only_word_cut_roop(add, branch);
		classify_type_loop(branch->list);
	}
	if (check_pipe(branch) || check_reduc(branch))
		return (1);
	else
		return (0);
}

int	check_all(t_branch *branch)
{
	if (check_reduc(branch) == 1 || check_pipe(branch) == 1)
		return (1);
	else if (check_pipe(branch) == -1)
		return (wait_complete_valid(branch));
	return (0);
}
