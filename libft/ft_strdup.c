/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:25:06 by ryanagit          #+#    #+#             */
/*   Updated: 2023/09/20 20:35:09 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	get_len(const char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

static char	*copy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	int		l;
	char	*d;

	l = get_len(src);
	d = (char *) malloc(l + 1);
	if (d != NULL)
	{
		d = copy(d, src);
		return (d);
	}
	else
		return (0);
}

// #include<stdio.h>
// int main()
// {
//     char original[] = "Hello, world!";
//     char *duplicate = ft_strdup(original);
//     if (duplicate != NULL)
//     {
//         printf("Original: %s\n", original);
//         printf("Duplicate: %s\n", duplicate);
//         free(duplicate); // Don't forget to free the memory
//     }
//     else
//     {
//         printf("Memory allocation failed.\n");
//     }
//     return 0;
// }