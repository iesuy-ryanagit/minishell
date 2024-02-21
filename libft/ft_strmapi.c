/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:23:18 by ryanagit          #+#    #+#             */
/*   Updated: 2023/09/27 12:35:20 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*d;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	d = (char *)malloc(len + 1);
	if (d == NULL)
		return (NULL);
	while (i < len)
	{
		d[i] = f(i, s[i]);
		i++;
	}
	d[i] = '\0';
	return (d);
}

// char num(unsigned int i, char c)
// {
// 	i--;
// 	if (48 <= c && c <= 57)
// 		return (48);
// 	else
// 		return (c);
// }
// #include<stdio.h>
// int main(void)
// {
// 	char s[]= "Hello 123 World";
// 	printf("%s", ft_strmapi(s, num));
// 	return (0);
// }