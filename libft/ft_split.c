/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:02:03 by ryanagit          #+#    #+#             */
/*   Updated: 2023/09/24 12:12:08 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	is_split(char str, char c)
{
	if (str == '\0')
		return (-1);
	else if (str == c)
		return (1);
	else
		return (0);
}

static int	count_str(char const *str, char c)
{
	int		i;
	int		count;
	int		f;

	i = 0;
	count = 0;
	f = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (is_split(str[i], c) == 1 && f == 1)
		{
			count++;
			f = 0;
		}
		if (is_split(str[i], c) == 0)
			f = 1;
		i++;
	}
	if (is_split(str[i], c) == -1 && f == 1)
		count++;
	return (count);
}

static char	*hm_strdup(char const *src, int s, int e)
{
	int		l;
	int		i;
	char	*d;

	l = e - s + 1;
	i = 0;
	d = (char *) malloc(l + 1);
	if (d != NULL)
	{
		while (i < l)
		{
			d[i] = src[s + i];
			i++;
		}
		d[i] = '\0';
		return (d);
	}
	else
		return (NULL);
}

static int	start_or_free(int i, char **array, char const *str, char c)
{
	int	l;

	l = 0;
	if (str == NULL)
		return (0);
	if (i < 0)
	{
		while (is_split(str[l], c) == 1)
			l++;
		return (l);
	}
	while (l < i)
	{
		free(array[l]);
		l++;
	}
	free(array);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		e;
	int		d;
	char	**array;

	array = (char **)malloc((count_str(s, c) + 1) * sizeof(char *));
	i = 0;
	d = start_or_free(-1, array, s, c);
	while (s != NULL && array != NULL && s[d])
	{
		e = d;
		while (is_split(s[e], c) == 0)
			e++;
		if (e > d)
			array[i++] = hm_strdup(s, d, e - 1);
		if (is_split(s[e], c) == -1 || array[i - 1] == NULL)
			break ;
		d = e + 1;
	}
	if (array != NULL && (i == 0 || (i > 0 && array[i - 1] != NULL)))
		array[i] = NULL;
	else if (array != NULL)
		start_or_free(i, array, s, c);
	return (array);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     char charset = '-';
// 	printf("%d",count_str(NULL,charset));
//     char **result = ft_split(NULL, charset);

// 	*result = NULL;
//     if (result != NULL)
//     {
//         int i = 0;
//         while (result[i] != NULL)
//         {
//             printf("Token %d: %s\n", i, result[i]);
//             free(result[i]); // メモリ解放
//             i++;
//         }
//         free(result); // 最後に配列自体のメモリも解放
//     }
//     else
//     {
//         printf("Memory allocation error\n");
//     }
//     return 0;
// }