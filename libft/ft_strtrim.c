/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:40:19 by ryanagit          #+#    #+#             */
/*   Updated: 2023/09/24 12:46:59 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	check_is(char s, char const *set)
{
	while (*set)
	{
		if (*set == s)
			return (1);
		set++;
	}
	return (0);
}

static size_t	get_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && check_is(s1[i], set) == 1)
		i++;
	return (i);
}

static size_t	get_last(char const	*s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while (0 < i && check_is(s1[i], set) == 1)
		i--;
	return (i);
}

static	char	*null_case(int i, char const *s1)
{
	char	*d;

	if (i == 1 && s1 != NULL)
	{
		d = ft_strdup(s1);
		if (d == NULL)
			return (NULL);
		return (d);
	}
	d = malloc(1);
	*d = '\0';
	return (d);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	last;
	size_t	i;
	char	*d;

	i = 0;
	if (set == NULL || s1 == NULL)
		return (null_case(1, s1));
	start = get_start(s1, set);
	last = get_last(s1, set);
	if (start > last)
		return (null_case(0, s1));
	d = (char *)malloc(last - start + 2);
	if (d == NULL)
		return (NULL);
	while (check_is(*s1, set) == 1 && *s1 != '\0')
		s1++;
	while (i < last - start + 1 && s1[i] != '\0')
	{
		d[i] = s1[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

// #include<stdio.h>
// int main(void)
// {
// 	char str[]= "  \t \t \n   \n\n\n\t";
// 	char set[]= " \n\t";
// 	printf("%s",ft_strtrim(str,set));
// 	return (0);
// }