/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:54:49 by ryanagit          #+#    #+#             */
/*   Updated: 2023/09/22 15:52:47 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	c_u;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	c_u = (unsigned char)c;
	while (n--)
	{
		if (*str == c_u)
		{
			s = (void *)str;
			return (str);
		}
		str++;
	}
	return (NULL);
}

// #include<string.h>
// #include<stdio.h>
// int main(void)
// {
// 	char str[] = {0, 1, 2 ,3 ,4 ,5};
// 	// char c = 'o';
// 	int n = 3;
// 	printf("%s\n",ft_memchr(str, 2 + 256, n));
// 	printf("%s\n",memchr(str, 2 + 256 ,n));
// 	return (0); 
// }