/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_roop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:16:04 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/22 11:00:36 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"lex.h"
#include"../execve/execve.h"

int	che_close(char *str, char c)
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

size_t	word_real_length(char *str)
{
	size_t	i;
	char	*tmp;
	int		sqf;
	int		wqf;

	i = 0;
	sqf = 0;
	wqf = 0;
	while (str[i])
	{
		tmp = &str[i + 1];
		if (wqf % 2 == 0 && (ch_close(tmp, '\'') || sqf % 2) && str[i] == '\'')
			sqf++;
		if (sqf % 2 == 0 && (che_close(tmp, '\"') || wqf % 2) && str[i] == '\"')
			wqf++;
		if (sqf % 2 == 0 && wqf % 2 == 0 && check_stop_word(str[i]))
		{
			i = stop_word_case(&str[i], i);
			break ;
		}
		i++;
	}
	return (i);
}

size_t	get_num_command(t_token **branch)
{
	size_t	i;

	i = 0;
	if (branch == NULL)
		return (0);
	while (branch[i])
	{
		i++;
	}
	return (i);
}

void	word_cut_roop(char *str, t_branch *branch)
{
	size_t		i;
	size_t		len;

	i = 0;
	*(branch->list) = NULL;
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

void	re_make_branch_command(t_branch *branch)
{
	t_token		*tmp;
	size_t		i;

	i = 0;
	tmp = *(branch->list);
	free(branch->command);
	branch->command = malloc(sizeof(t_token *) * (get_count_pipe(&tmp) + 2));
	if (branch->command == NULL)
	{
		free(branch);
		free_token_list(branch, 3);
	}
	while (tmp != NULL)
	{
		if (tmp->type == COMMAND)
			(branch->command)[i++] = tmp;
		tmp = tmp->next;
	}
	(branch->command)[i] = NULL;
}
