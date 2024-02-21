/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotoyam <kmotoyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:20:48 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/20 15:42:17 by kmotoyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"lex.h"
#include"../execve/execve.h"

size_t	exist_to_be_split(char c, char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	get_len(char *str, char *split, int start)
{
	size_t	i;
	size_t	count;

	i = start;
	count = 0;
	while (str[i] && exist_to_be_split(str[i], split) == 0)
	{
		i++;
		count++;
	}
	return (count);
}

t_token	*make_new_list(char *str, int start, int len)
{
	t_token	*new;

	new = token_create_new(str, start, len);
	new->type = OPTION;
	return (new);
}

void	insert_new_list(t_token *tmp, t_token *prev, t_token *post)
{
	tmp->prev = prev;
	tmp->next = post;
	if (tmp->prev && tmp->prev->next != tmp)
		tmp->prev->next = tmp;
	if (tmp->next && tmp->next->prev != tmp)
		tmp->next->prev = tmp;
}

void	split_token_add_back(t_token **list, t_token *new)
{
	t_token	*tmp;

	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	tmp = token_last(*list);
	if (tmp == NULL)
	{
		*list = new;
		return ;
	}
	tmp->next = new;
	new->prev = tmp;
}
