/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotoyam <kmotoyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:31:11 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/20 15:41:41 by kmotoyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"lex.h"

int	str_check_reduc_in(char *str)
{
	if (ft_strncmp(str, "<", 2) == 0)
		return (1);
	else
		return (0);
}

int	str_check_reduc_out(char *str)
{
	if (ft_strncmp(str, ">", 2) == 0)
		return (1);
	else
		return (0);
}

int	str_check_chase(char *str)
{
	if (ft_strncmp(str, ">>", 3) == 0)
		return (1);
	else
		return (0);
}

int	str_check_heredoc(char *str)
{
	if (ft_strncmp(str, "<<", 2) == 0)
		return (1);
	else
		return (0);
}

int	str_check_pipe(char *str)
{
	if (ft_strncmp(str, "|", 2) == 0)
		return (1);
	else
		return (0);
}
