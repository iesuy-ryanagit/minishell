/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:55:49 by ryanagit          #+#    #+#             */
/*   Updated: 2023/09/22 18:03:04 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_c;
	unsigned char	*s2_c;
	size_t			i;

	s1_c = (unsigned char *)s1;
	s2_c = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_c[i] - s2_c[i] == 0)
		{
			i++;
		}
		else
		{
			return (s1_c[i] - s2_c[i]);
		}
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h> 
// int main() {
// 	char s[] = {-128, 0, 127, 0};
// 	// char sCpy[] = {-128, 0, 127, 0};
// 	// char s2[] = {0, 0, 127, 0};
// 	char s3[] = {0, 0, 42, 0};
// 	unsigned int i;
// 	char *str1;
// 	char *str2;

// 	str1 = s;
// 	str2 = s3;
// 	i = 0;
// 	while(i < 10)
// 	{
//     	int correct = memcmp(str1, str2, i);
//     	int result = ft_memcmp(str1, str2, i);
// 		printf("i= %d\n", i);
//     	printf("Result 1: %d\n", correct);
//     	printf("Result 2: %d\n", result);
// 		i++;
// 	}
//     return 0;
// }