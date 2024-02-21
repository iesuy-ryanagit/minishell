/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:25:24 by ryanagit          #+#    #+#             */
/*   Updated: 2023/09/20 20:34:54 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned long			i;
	unsigned char			*b_char;
	unsigned long			len_long;

	i = 0;
	b_char = (unsigned char *)b;
	len_long = (unsigned long)len;
	while (i < len_long)
	{
		*(b_char + i) = (unsigned char)c;
		i++;
	}
	return (b);
}

// #include<stdio.h>
// #include<string.h>
// int main(void)
// {
// 	char str[]="Hell";
// 	memset(str+2, 'a',4);

// 	printf("%s",str);
// 	return (0);
// }