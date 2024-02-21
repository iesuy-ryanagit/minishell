/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:56:50 by ryanagit          #+#    #+#             */
/*   Updated: 2023/09/21 19:08:50 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			i;
	size_t			j;
	char			*haystack_n;

	haystack_n = (char *)haystack;
	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return (haystack_n);
	while (i < len && haystack[i + j] != '\0')
	{
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			j++;
			if (needle[j] == '\0')
				return (&haystack_n[i]);
		}
		j = 0;
		i++;
	}
	return (NULL);
}

// #include<stdio.h>
// int	print_len(size_t t)
// {
// 	printf("%zu", t);
// 	return (0);
// }

// #include <stdio.h>
// #include <string.h>
// #include <stddef.h>
// char *ft_strstr(char *str, char *to_find);
// int main() {
//     char haystack[] = "aaabcabcd";
//     char needle[] = "coucou";
//    char *result =ft_strnstr(haystack, needle,-1); 
//    char *correct =strnstr(haystack, needle, -1); 
// 	printf("outp: %s\n", result);
// 	printf("true: %s\n", correct); 
//     return 0;
// }

// int main(void)
// {
// 	print_len(-1);
// 	return (0);
// }