/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:44:42 by ryanagit          #+#    #+#             */
/*   Updated: 2023/09/24 14:51:43 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void	change_num(unsigned int i, char *c)
// {
// 	i--;
// 	if (48 <= *c && *c <= 57)
// 		*c = 48;
// }
// #include<stdio.h>
// int	main(void)
// {
// 	// char c = 48;
// 	// printf("%c",c);
// 	char s[] = "abcd123454gjkgjl";
// 	printf("%s\n", s);
// 	ft_striteri(s, change_num);
// 	printf("%s", s);
// 	return (0);
// }