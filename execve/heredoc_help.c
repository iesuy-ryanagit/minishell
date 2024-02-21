/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:22:56 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/21 12:54:29 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../handle/handle.h"
#include"../libft/libft.h"
#include"../lexparse/lex.h"
#include"execve.h"

size_t	count_del(t_token *list)
{
	t_token	*tmp;
	size_t	count;

	count = 0;
	tmp = list;
	while (tmp && tmp->type != PIPE)
	{
		if (tmp->type == HERE_DOC)
			count++;
		tmp = tmp->prev;
	}
	tmp = list;
	while (tmp && tmp->type != PIPE)
	{
		if (tmp->type == HERE_DOC)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

char	**get_all_del(t_token *list)
{
	t_token	*tmp;
	char	**ret;
	size_t	i;

	i = 0;
	ret = malloc(sizeof(char *) * (count_del(list) + 1));
	tmp = list;
	while (tmp->prev && tmp->prev->type != PIPE)
	{
		tmp = tmp->prev;
	}
	while (tmp && tmp->type != PIPE)
	{
		if (tmp->type == HERE_DOC)
		{
			ret[i++] = tmp->next->str;
		}
		tmp = tmp->next;
	}
	ret[i] = NULL;
	return (ret);
}

void	help_do_heredoc(char *line, int fd, char **del, size_t i)
{
	if (del[i + 1] == NULL)
	{
		ft_putstr_fd(line, fd);
		write(fd, "\n", 1);
	}
	free(line);
}

void	set_first_heredoc(char ***del, t_token *list, int pfd[2], t_branch *bra)
{
	if (pipe(pfd) < 0)
	{
		free(del);
		free_branch_end(bra, 10);
		exit(EXIT_FAILURE);
	}
	*del = get_all_del(list);
	signal(SIGINT, heredoc_handler);
	rl_event_hook = check_state;
	g_signal_handled = 0;
}

void	end_heredoc(char **del, int fd_close, char *line)
{
	if (g_signal_handled == 1)
		free(line);
	free(del);
	close(fd_close);
}
