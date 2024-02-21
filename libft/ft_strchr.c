/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:56:07 by ryanagit          #+#    #+#             */
/*   Updated: 2023/09/25 10:05:38 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	c_u;

	c_u = c;
	str = (char *)s;
	if (c_u == '\0')
	{
		while (*str)
			str++;
		return ((char *)str);
	}
	while (*s)
	{
		str = (char *)s;
		if (*str == c_u)
			return ((char *)str);
		s++;
	}
	return (0);
}
