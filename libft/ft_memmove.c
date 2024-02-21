/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:34:33 by ryanagit          #+#    #+#             */
/*   Updated: 2023/09/29 11:51:36 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	char			*dst_c;
	char			*src_c;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	dst_c = (char *)dst;
	src_c = (char *)src;
	if (dst > src)
	{
		while (0 < len)
		{
			dst_c[len - 1] = src_c[len - 1];
			len--;
		}
		return (dst);
	}
	while (i < len)
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
// 	char src[] = "thiß ß\xde\xad\xbe\xeftriñg will be øvérlapéd !\r\n";
// 	char src2[]= "thiß ß\xde\xad\xbe\xeftriñg will be øvérlapéd !\r\n";
// 	char dst1[300];
// 	char dst2[300];
// 	int size = 128*1024*1024;
// 	ft_memmove(dst1,src,size);
// 	memmove(dst2,src2,size);
// 	printf("%d",size);
// 	printf("%s\n",dst1);
// 	printf("%s\n",dst2);
// 	return (0);
// }