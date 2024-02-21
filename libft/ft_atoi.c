/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:57:16 by ryanagit          #+#    #+#             */
/*   Updated: 2023/09/25 09:49:34 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	check_num(char s)
{
	if (48 <= s && s <= 57)
		return (1);
	return (0);
}

static	int	escape_flow(char s, long long i)
{
	long long	dm;

	dm = LONG_MAX / 10;
	if (check_num(s) == 1)
	{
		if (i > dm || (i == dm && s > 55))
			return (1);
		else if (i < -1 * dm || ((i == -1 * dm) && s == 57))
			return (-1);
		else
			return (0);
	}
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int				f;
	long long		i;

	f = 1;
	i = 0;
	while (*str == 32 || (9 <= *str && *str <= 13))
		str++;
	if (*str == 43 || *str == 45)
	{
		f = 44 - *str;
		str++;
	}
	while (48 <= *str && *str <= 57)
	{
		i = i * 10 + (*str - 48) * f;
		str++;
		if (escape_flow(*str, i) != 0)
			break ;
	}
	if (escape_flow(*str, i) == 1)
			i = LONG_MAX;
	else if (escape_flow(*str, i) == -1)
			i = LONG_MIN;
	return ((int)i);
}
