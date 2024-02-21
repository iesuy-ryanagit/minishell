/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_sup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotoyam <kmotoyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:38:02 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/20 15:41:58 by kmotoyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"lex.h"

size_t	get_len_name_env(char *str)
{
	size_t	i;

	i = 0;
	if (str[0] == '?')
		return (1);
	while (str[i])
	{
		if (ft_isalnum(str[i]) == 0 && str[i] != '_')
			return (i);
		i++;
	}
	return (i);
}

char	*get_exp_from(char *str)
{
	size_t	len;
	char	*tmp;

	if (str[0] == '\"')
	{
		len = get_index_samequote(str, '\"');
		tmp = ft_substr(str, 0, len + 1);
	}
	else if (str[0] == '$')
	{
		len = get_len_name_env(str + 1);
		tmp = ft_substr(str, 0, len + 1);
	}
	else if (str[0] == '\'')
	{
		len = get_index_samequote(str, '\'');
		tmp = ft_substr(str, 0, len + 1);
	}
	else
	{
		len = get_index_quoteordol(str);
		tmp = ft_substr(str, 0, len);
	}
	return (tmp);
}

int	re_strcmp_dol(char *str)
{
	if (str[0] != '$')
		return (0);
	if (str[1] != '\0')
		return (0);
	return (1);
}

int	get_index_dol(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (i);
		i++;
	}
	return (i);
}

char	*get_exp_from_in_dq(char *str, t_branch *branch)
{
	size_t	len;
	char	*tmp;

	if (str[0] == '$')
	{
		len = get_len_name_env(str + 1);
		tmp = ft_substr(str, 0, len + 1);
		if (tmp == NULL)
			free_branch_end(branch, 4);
	}
	else
	{
		len = get_index_dol(str);
		tmp = ft_substr(str, 0, len);
		if (tmp == NULL)
			free_branch_end(branch, 4);
	}
	return (tmp);
}
