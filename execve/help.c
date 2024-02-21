/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotoyam <kmotoyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:28:42 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/19 16:27:15 by kmotoyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"execve.h"
#include"../handle/handle.h"

void	help_judge_red(int i, t_token	*list)
{
	int		out_fd;

	if (i == CHASE)
	{
		out_fd = open(list->str, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (out_fd < 0)
		{
			ft_putstr_fd("ERROR", 2);
			exit(1);
		}
		if (access(list->str, W_OK) != 0)
		{
			permission_denied_message(list->str);
			exit(1);
		}
		dup2(out_fd, STDOUT_FILENO);
		close(out_fd);
	}
}

void	check_access(char *str, int fd)
{
	if (fd < 0)
	{
		ft_putstr_fd("minishell:", STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putstr_fd(" No such file or directory\n", STDERR_FILENO);
		exit(1);
	}
	if (access(str, F_OK) == -1)
	{
		ft_putstr_fd("minishell:", STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putstr_fd(" No such file or directory\n", STDERR_FILENO);
		exit(1);
	}
}

void	judge_red(int i, t_token *list)
{
	int		infile_fd;
	int		out_fd;

	if (i == RED_OUT)
	{
		out_fd = open(list->str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (out_fd < 0)
		{
			ft_putstr_fd("ERROR", 2);
			exit(1);
		}
		dup2(out_fd, STDOUT_FILENO);
		close(out_fd);
	}
	if (i == RED_IN)
	{
		infile_fd = open(list->str, O_RDONLY);
		check_access(list->str, infile_fd);
		close(infile_fd);
	}
	help_judge_red(i, list);
}

void	check_red(t_token *list)
{
	t_token	*tmp;

	tmp = list;
	while (list && list->type != PIPE)
	{
		if (list->prev != NULL)
		{
			judge_red(list->prev->type, list);
		}
		list = list->prev;
	}
	list = tmp;
	while (list && list->type != PIPE)
	{
		if (list->prev != NULL)
		{
			judge_red(list->prev->type, list);
		}
		list = list->next;
	}
}
