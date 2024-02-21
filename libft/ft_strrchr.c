/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:18:40 by ryanagit          #+#    #+#             */
/*   Updated: 2023/09/25 09:44:18 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*ret;
	char	c_u;

	c_u = c;
	str = (char *)s;
	if (c_u == '\0')
	{
		while (*str)
			str++;
		return (str);
	}
	ret = 0;
	while (*str)
	{
		if (*str == c_u)
			ret = str;
		str++;
	}
	return (ret);
}

// #include<string.h>
// #include<stdio.h>
// int main(void)
// {
// 	char str[] = "Asahi appplied the job";
// 	char c = 'B';
// 	printf("%s\n",ft_strrchr(str,c));
// 	printf("%s\n",strrchr(str,c));
// 	return (0); 
// }