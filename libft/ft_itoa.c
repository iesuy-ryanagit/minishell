/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:42:12 by ryanagit          #+#    #+#             */
/*   Updated: 2023/09/25 09:50:24 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	get_digit(long n_l)
{
	int		d;

	d = 0;
	if (n_l < 0)
	{
		d = 1;
		n_l = n_l * -1;
	}
	if (n_l == 0)
		return (1);
	while (n_l > 0)
	{
		d++;
		n_l /= 10;
	}
	return (d);
}

char	*ft_itoa(int n)
{	
	long	n_l;
	int		d;
	int		i;
	char	*dst;

	n_l = n;
	i = 0;
	d = get_digit(n_l);
	dst = malloc(d + 1);
	if (dst == NULL)
		return (NULL);
	if (n_l < 0)
	{
		n_l = n_l * -1;
		dst[i] = '-';
		i++;
	}
	dst[d] = '\0';
	while (i < d--)
	{
		dst[d] = n_l % 10 + '0';
		n_l = n_l / 10;
	}
	return (dst);
}
