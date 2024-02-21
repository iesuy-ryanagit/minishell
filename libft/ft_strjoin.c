/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:31:08 by ryanagit          #+#    #+#             */
/*   Updated: 2023/09/24 12:36:41 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*process_null(char const *s1, char const *s2)
{
	char	*d;

	if (s1 == NULL && s2 == NULL)
	{
		d = malloc(1);
		if (d == NULL)
			return (NULL);
		*d = '\0';
		return (d);
	}
	else if (s1 == NULL)
		return (ft_strdup(s2));
	else
		return (ft_strdup(s1));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	char	*d;

	if (s1 == NULL || s2 == NULL)
		return (process_null(s1, s2));
	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	d = (char *)malloc(len_s1 + len_s2 + 1);
	if (d == NULL)
		return (NULL);
	while (i < len_s1)
	{
		d[i] = s1[i];
		i++;
	}
	while (i < len_s1 + len_s2)
	{
		d[i] = s2[i - len_s1];
		i++;
	}
	d[i] = '\0';
	return (d);
}

// int main(void)
// {
// 	char s1[] ="Hello World";
// 	char s2[]= "Goodbye World";
// 	printf("%s", ft_strjoin(s1,s2));
// }