/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:28:42 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/19 18:29:44 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"execve.h"
#include"../handle/handle.h"

void	check_fd(int out_fd, t_token *list, t_branch *branch)
{
	if (out_fd < 0)
	{
		permission_denied_message(list->str);
		branch->exit_status = 1;
	}
	if (access(list->str, W_OK) != 0)
	{
		permission_denied_message(list->str);
		branch->exit_status = 1;
	}
}

int	help_judge_red_c(int i, t_token	*list, int fd_out, t_branch *branch)
{
	int		out_fd;

	if (i == CHASE)
	{
		out_fd = open(list->str, O_WRONLY | O_CREAT | O_APPEND, 0644);
		check_fd(out_fd, list, branch);
		return (out_fd);
	}
	return (fd_out);
}

int	judge_red_c(int i, t_token *list, int fd_out, t_branch *branch)
{
	int		out_fd;
	int		ret;

	ret = fd_out;
	if (i == RED_OUT)
	{
		out_fd = open(list->str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		check_fd(out_fd, list, branch);
		ret = out_fd;
		return (out_fd);
	}
	if (i == RED_IN)
	{
		out_fd = open(list->str, O_RDONLY);
		if (access(list->str, F_OK) == -1)
		{
			permission_denied_message(list->str);
			branch->exit_status = 1;
			return (-1);
		}
		close(out_fd);
		return (fd_out);
	}
	return (help_judge_red_c(i, list, fd_out, branch));
}

int	prev_check_red_c(t_token *list, int fd_out, t_branch *branch)
{
	int		ret;
	t_token	*tmp;

	tmp = list;
	ret = fd_out;
	while (list && list->type != PIPE)
	{
		if (list->prev != NULL)
		{
			ret = judge_red_c(list->prev->type, list, ret, branch);
			if (ret < 0)
				return (ret);
		}
		list = list->prev;
	}
	return (ret);
}

int	check_red_c(t_token *list, t_branch *branch, int fd_out)
{
	int		ret;
	t_token	*tmp;

	tmp = list;
	ret = prev_check_red_c(list, fd_out, branch);
	list = tmp;
	while (list && list->type != PIPE)
	{
		if (list->prev != NULL)
		{
			ret = judge_red_c(list->prev->type, list, ret, branch);
			if (ret < 0)
				return (ret);
		}
		list = list->next;
	}
	return (ret);
}
