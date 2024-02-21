/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relibft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotoyam <kmotoyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:30:03 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/20 15:42:10 by kmotoyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"lex.h"

char	*re_strdup(char *str, t_branch *branch)
{
	char	*tmp;

	tmp = ft_strdup(str);
	if (tmp == NULL)
	{
		free_branch_end(branch, 2);
		return (NULL);
	}
	else
		return (tmp);
}

char	*re_strtrim(char *str1, char *str2, t_branch *branch, int flag)
{
	char	*tmp;

	tmp = ft_strtrim(str1, str2);
	if (tmp == NULL)
	{
		if (flag == 1)
			free(str1);
		free_branch_end(branch, 3);
		return (NULL);
	}
	else
		return (tmp);
}

size_t	re_strlen(const char *str)
{
	if (str == NULL)
		return (0);
	else
		return (ft_strlen(str));
}

char	*re_re_strjoin(char *str1, char *str2, t_branch *branch)
{
	char	*join;

	if (str1 == NULL && str2 == NULL)
		return (NULL);
	join = ft_strjoin(str1, str2);
	if ((str1 != NULL || str2 != NULL) && join == NULL)
	{
		free(str1);
		free(str2);
		free_branch_end(branch, 1);
	}
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	return (join);
}

char	*re_itoa(int value, t_branch *branch)
{
	char	*tmp;

	tmp = ft_itoa(value);
	if (tmp == NULL)
		free_branch_end(branch, 5);
	return (tmp);
}
