/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:42:31 by ryanagit          #+#    #+#             */
/*   Updated: 2023/09/30 15:31:05 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*c;
	size_t			i;

	i = 0;
	if (count == 0 || size == 0)
	{
		c = malloc(1);
		if (c == NULL)
			return (NULL);
		c[i] = 0;
		return (c);
	}
	if (count > SIZE_T_MAX / size)
		return (NULL);
	c = malloc(count * size);
	if (c == NULL)
		return (NULL);
	ft_bzero(c, count * size);
	return (c);
}
