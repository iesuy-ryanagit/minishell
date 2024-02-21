/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:08:44 by ryanagit          #+#    #+#             */
/*   Updated: 2023/09/20 20:35:30 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// #include<string.h>
// #include<stdio.h>
// int main (int argc, char *argv[])
// {
// 	int i;
// 	i = 0;
// 	while(i < argc)
// 	{
// 		if (ft_strlen(argv[i])-strlen(argv[i]))
// 			printf("%d",i);
// 		i++;
// 	}
// 	return (0);
// }