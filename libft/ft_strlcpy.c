/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:51:59 by ryanagit          #+#    #+#             */
/*   Updated: 2023/09/23 17:32:23 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (src[i] != '\0' && i < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (i == dstsize)
		dst[i - 1] = '\0';
	else
		dst[i] = '\0';
	return (src_len);
}

// #include <stdio.h>
// #include<string.h>
// int main()
// {
// 	char source[] = "coucou";
// 	char destination[20]=  "AAAAAAAAAA"; // 十分な大きさのバッファ
// 	char destination2[20]= "AAAAAAAAAA";
// 	int x = 6;
// 	unsigned int copied = ft_strlcpy(destination, source, x);
// 	unsigned int copied2 = strlcpy(destination2, source, x);
// 	printf("Output!: %u\n", copied);
// 	printf("Output!: %s\n", destination);
// 	printf("Correct: %u\n", copied2);
// 	printf("Correct: %s\n", destination2);
// 	return 0;
// }