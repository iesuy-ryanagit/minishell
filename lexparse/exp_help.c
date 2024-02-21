/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotoyam <kmotoyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:04:29 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/20 15:41:55 by kmotoyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"lex.h"

int	ch_close(char *str, char c)
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

size_t	get_index_samequote(char *str, unsigned char c)
{
	size_t	i;

	i = 1;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

size_t	get_index_quoteordol(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' || str[i] == '\'' || str[i] == '\"')
			return (i);
		i++;
	}
	return (i);
}

void	free_success_end(t_branch *branch)
{
	free_list(branch->list);
	free(branch->command);
}
