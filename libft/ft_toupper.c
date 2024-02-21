/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:28:54 by ryanagit          #+#    #+#             */
/*   Updated: 2023/09/23 17:28:59 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (97 <= c && c <= 122)
		return (c - 32);
	else
		return (c);
}

// #include<stdio.h>
// int main(void)
// {
// 	printf("%d",ft_toupper(100));
// 	return (0);
// }