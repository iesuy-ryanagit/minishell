/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipehelp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:37:16 by kmotoyam          #+#    #+#             */
/*   Updated: 2024/02/21 12:54:35 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexparse/lex.h"
#include"../handle/handle.h"
#include"execve.h"

int	c_e_tp(t_token *list, int ty)
{
	t_token	*tmp;

	tmp = list;
	while (tmp && tmp->type != PIPE)
	{
		if ((int)tmp->type == ty)
			return (1);
		tmp = tmp->prev;
	}
	tmp = list;
	while (tmp && tmp->type != PIPE)
	{
		if ((int)tmp->type == ty)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	set_free(char *cmd_path, char **path, char **argv)
{
	free(cmd_path);
	double_free(path);
	double_free(argv);
}

void	process_not_found(char *str, t_command *com, int *in, int *out)
{
	if (com->cmd_path == NULL)
	{
		if (com->num != 0)
			close(in[0]);
		close(out[1]);
		close(out[0]);
		command_not_found_message(str);
		set_free(com->cmd_path, com->path, com->argv);
		free(com);
		exit(127);
	}
}

int	infile_last(t_token *list)
{
	int		i;

	i = 0;
	if (list == NULL)
		return (-1);
	while (list->prev && list->prev->type != PIPE)
		list = list->prev;
	while (list && list->type != PIPE)
	{
		if (list->type == HERE_DOC || list->type == RED_IN)
			i = list->type;
		list = list->next;
	}
	return (i);
}

char	*red_in_last(t_token *list)
{
	char	*str;

	str = NULL;
	if (list == NULL)
		return (NULL);
	while (list->prev && list->prev->type != PIPE)
		list = list->prev;
	while (list && list->type != PIPE)
	{
		if (list->type == RED_IN)
			str = list->next->str;
		list = list->next;
	}
	return (str);
}
