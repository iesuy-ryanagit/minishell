/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:16:54 by ryanagit          #+#    #+#             */
/*   Updated: 2023/09/23 17:26:35 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		d_size;
	size_t		s_size;

	i = 0;
	s_size = ft_strlen(src);
	if (dst == NULL && dstsize == 0)
		return (dstsize + s_size);
	d_size = ft_strlen(dst);
	if (dstsize > d_size)
	{
		while (i < dstsize - d_size - 1 && src[i] != '\0')
		{
			dst[i + d_size] = src[i];
			i++;
		}
		dst[i + d_size] = '\0';
		return (d_size + s_size);
	}
	return (dstsize + s_size);
}

// #include <stdio.h>
// #include <string.h>
// int main() {
//     char *dest =NULL;
//     char *dest2 =NULL;
//     char src[] = "HAHA";
//     unsigned int size = 0;
//     unsigned int correct = strlcat(dest, src, size);
//     unsigned int result = ft_strlcat(dest2, src, size);
//     printf("正解: %u\n", correct);
//     printf("出力: %u\n", result);
// 	int i = 0;
// 	while (dest[i] || dest2[i])
// 	{
//     	printf("correct: %c\n", dest[i]);
//     	printf("output!: %c\n", dest2[i]);
// 		if(dest[i] - dest2[i] != 0)
// 			printf("!!!!!!Error Occured!!!!!!");
// 		i++;
// 	}
//     return 0;
// }