/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:06:44 by ryanagit          #+#    #+#             */
/*   Updated: 2023/09/23 14:21:45 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	char			*dst_c;
	char			*src_c;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	dst_c = (char *)dst;
	src_c = (char *)src;
	while (i < n)
	{
		dst_c[i] = src_c[i];
		i++;
	}
	return (dst);
}

// #include<stdio.h>
// #include<string.h>
// int main(void)
// {
// 	char *str=NULL;
// 	char *dst= NULL;
// 	char *dst2= NULL;
// 	printf("%s\n",memcpy(dst,str,0));
// 	printf("%s\n",ft_memcpy(dst2,str,0));
// }
