/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:45:21 by ryanagit          #+#    #+#             */
/*   Updated: 2023/09/23 16:12:48 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	int				d;
	unsigned char	s1_u;
	unsigned char	s2_u;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		s1_u = s1[i];
		s2_u = s2[i];
		d = s1_u - s2_u;
		if (d == 0)
		{
			i++;
		}
		else
		{
			return (d);
		}
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h> 
// int main() {
//     char *str1 = NULL;
//     char *str2 = "YOASOBANAI";
// 	unsigned int i;
// 	i = 0;
// 	while(i < 10)
// 	{
//     	int correct = strncmp(str1, str2, i);
//     	int result = ft_strncmp(str1, str2, i);
// 		printf("i= %d\n", i);
//     	printf("Result 1: %d\n", correct);
//     	printf("Result 2: %d\n", result);
// 		i++;
// 	}
//     return 0;
// }