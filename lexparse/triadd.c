/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triadd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:27:06 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/26 15:38:11 by ryanagit         ###   ########.fr       */
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

void	only_word_cut_roop(char *str, t_branch *branch)
{
	size_t		i;
	size_t		len;

	i = 0;
	while (str[i])
	{
		while (check_split(str[i]) == 1)
			i++;
		if (str[i] == '\0')
			break ;
		len = word_real_length(&str[i]);
		token_add_back(branch, token_create_new(&str[i], 0, len));
		i = i + len;
	}
	free(str);
}
