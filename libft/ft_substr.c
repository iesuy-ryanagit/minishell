/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 08:26:50 by ryanagit          #+#    #+#             */
/*   Updated: 2023/09/24 12:13:38 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static char	*zero_pattern(void)
{
	char	*d;

	d = malloc(1);
	*d = '\0';
	return (d);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*d;
	size_t			len_s;
	size_t			st;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	st = (size_t)start;
	i = 0;
	if (st >= len_s || len == 0)
		return (zero_pattern());
	if (len > len_s - st)
		len = len_s - st;
	d = malloc(len + 1);
	if (d == NULL)
		return (NULL);
	while (i < len && s[st + i] != '\0')
	{
		d[i] = s[st + i];
		i++;
	}
	while (i < len + 1)
		d[i++] = '\0';
	return (d);
}

// #include<stdio.h>
// #include<string.h>
// int main(void)
// {
// 	char str[]= "i just want this part #############";
// 	unsigned int start= 5;
// 	size_t len = 10;
// 	printf("%s\n",ft_substr(str,start,len));
// 	return (0);
// }