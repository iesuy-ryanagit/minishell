/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:58:50 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/21 13:36:52 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"lex.h"

size_t	get_count_pipe(t_token **list)
{
	size_t	num;
	t_token	*tmp;

	num = 0;
	if (list == NULL)
		exit(EXIT_FAILURE);
	tmp = *list;
	while (tmp)
	{
		if (tmp->type == PIPE && tmp->next != NULL)
			num++;
		tmp = tmp->next;
	}
	return (num);
}

t_token	*get_pipe_next_command(t_token *tmp)
{
	while (tmp)
	{
		if (tmp->type == PIPE)
			return (tmp->next);
		tmp = tmp->next;
	}
	return (NULL);
}

t_token	**one_pipe_line(t_token **list)
{
	t_token			*tmp;
	t_token			**dbl;
	size_t			i;
	size_t			num;

	tmp = *list;
	i = 0;
	num = get_count_pipe(list) + 1;
	dbl = malloc(sizeof(t_token *) * (num + 1));
	while (i < num && tmp != NULL)
	{
		dbl[i] = tmp;
		i++;
		tmp = get_pipe_next_command(tmp);
	}
	dbl[i] = NULL;
	return (dbl);
}

size_t	get_count_infile(t_token **list)
{
	size_t	num;
	t_token	*tmp;

	num = 0;
	if (list == NULL)
		exit(1);
	tmp = *list;
	while (tmp)
	{
		if (tmp->type == RED_IN && tmp->next != NULL)
			num++;
		tmp = tmp->next;
	}
	return (num);
}

size_t	get_count_outfile(t_token **list)
{
	size_t	num;
	t_token	*tmp;

	num = 0;
	if (list == NULL)
		exit(1);
	tmp = *list;
	while (tmp)
	{
		if (tmp->type == RED_OUT && tmp->next != NULL)
			num++;
		tmp = tmp->next;
	}
	return (num);
}
