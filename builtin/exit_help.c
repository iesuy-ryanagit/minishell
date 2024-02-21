/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotoyam <kmotoyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:18:30 by kmotoyam          #+#    #+#             */
/*   Updated: 2024/02/20 15:41:20 by kmotoyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"built.h"

int	check_over(char digit, long check, int i)
{
	int	count;

	count = digit - '0';
	if (count >= 8 && check == 1)
		return (1);
	else if (count >= 9 && check == -1)
		return (1);
	else if (i >= 19 && check == 1)
		return (1);
	else if (i >= 20 && check == -1)
		return (1);
	return (0);
}

int	check_digit(int i)
{
	if (i >= 19)
		return (1);
	return (0);
}

int	check_exit(long num, char *nptr, int i, long check)
{
	if (num >= LONG_MAX / 10)
	{
		if (check_over(nptr[i], check, i) == 1)
		{
			return (1);
		}
	}
	else
		return (check_digit(i));
	return (0);
}
