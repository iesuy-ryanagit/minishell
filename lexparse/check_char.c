/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:38:09 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/22 12:22:01 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"lex.h"

int	check_one(char c)
{
	if (c == '|')
		return (1);
	else
		return (0);
}

int	check_reduc_in(char c)
{
	if (c == '<' )
		return (1);
	else
		return (0);
}

int	check_reduc_out(char c)
{
	if (c == '>' )
		return (1);
	else
		return (0);
}

int	check_split(char c)
{
	if ((9 <= c && c <= 11) || c == 32)
		return (1);
	else
		return (0);
}

int	check_stop_word(char c)
{
	if (check_one(c) || check_reduc_in(c))
		return (1);
	else if (check_reduc_out(c) || check_split(c))
		return (1);
	else
		return (0);
}
