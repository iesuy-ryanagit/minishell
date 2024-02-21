/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:08:57 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/21 12:55:43 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../handle/handle.h"
#include"execve.h"

int	do_heredoc(t_token *list, t_branch *branch)
{
	char	**del;
	char	*line;
	int		pfd[2];
	size_t	i;

	set_first_heredoc(&del, list, pfd, branch);
	i = 0;
	while (1)
	{
		line = readline("> ");
		if (line == NULL || g_signal_handled == 1)
			break ;
		if (ft_strncmp(line, del[i], ft_strlen(del[i])) == 0)
		{
			free(line);
			i++;
			if (del[i] == NULL)
				break ;
		}
		else
			help_do_heredoc(line, pfd[1], del, i);
	}
	end_heredoc(del, pfd[1], line);
	return (pfd[0]);
}

int	judge_here(int i, t_token	*list, t_branch *branch)
{
	int		infile_fd;

	if (i == HERE_DOC)
	{
		infile_fd = do_heredoc(list, branch);
		return (infile_fd);
	}
	else
		return (STDIN_FILENO);
}

int	check_heredoc(t_token *list, t_branch *branch)
{
	int		flag;
	int		ret;
	t_token	*tmp;

	tmp = list;
	flag = 1;
	ret = 0;
	while (list && list->type != PIPE)
	{
		if (list->prev != NULL && list->prev->type != PIPE)
			if (list->prev->type == HERE_DOC)
				return (judge_here(list->prev->type, list, branch));
		list = list->prev;
	}
	list = tmp;
	while (list && list->type != PIPE)
	{
		if (list->prev != NULL)
			if (list->prev->type == HERE_DOC)
				return (judge_here(list->prev->type, list, branch));
		list = list->next;
	}
	return (STDIN_FILENO);
}
