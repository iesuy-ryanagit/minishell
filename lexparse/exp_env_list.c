/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_env_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotoyam <kmotoyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:04:29 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/20 15:41:52 by kmotoyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"lex.h"

char	*get_result_expansion(char *str, t_branch *branch)
{
	t_env	*tmp;
	char	*ret;

	ret = NULL;
	if (branch->env == NULL)
		return (NULL);
	if (ft_strncmp("?", str, 2) == 0)
	{
		if (branch->exit_status > 255 && branch->exit_status != 258)
			branch->exit_status = branch->exit_status / 256;
		return (re_itoa(branch->exit_status, branch));
	}
	tmp = *(branch->env);
	while (tmp)
	{
		if (ft_strncmp(tmp->name, str, re_strlen(str)) == 0)
		{
			ret = re_strdup(tmp->value, branch);
			return (ret);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

int	stop_word_case(char *str, int i)
{
	if (i != 0)
		return (i);
	if (check_reduc_in(*str) || check_reduc_out(*str))
	{
		if (*str == *(str + 1))
			return (2);
	}
	return (1);
}
