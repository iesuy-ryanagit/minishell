/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotoyam <kmotoyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:29:42 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/20 15:42:00 by kmotoyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"lex.h"

char	*get_exp_to_in_dq(char *tmp, t_branch *branch)
{
	char	*env;

	if (re_strcmp_dol(tmp))
		env = re_strdup(tmp, branch);
	else if (tmp[0] == '$')
	{
		env = get_result_expansion(tmp + 1, branch);
		if (env == NULL)
		{
			env = malloc(1);
			if (env == NULL)
				return (NULL);
			*env = '\0';
		}
	}
	else
		env = re_strdup(tmp, branch);
	return (env);
}

char	*expansion_in_dquote(char *str, t_branch *branch)
{
	size_t	i;
	char	*tmp;
	char	*add;
	char	*ret;

	ret = NULL;
	i = 0;
	while (str[i])
	{
		tmp = get_exp_from_in_dq(&str[i], branch);
		add = get_exp_to_in_dq(tmp, branch);
		ret = re_re_strjoin(ret, add, branch);
		i = i + ft_strlen(tmp);
		free(tmp);
	}
	return (ret);
}

char	*get_exp_to(char *tmp, t_token *now, t_branch *branch)
{
	char	*env;
	char	*origin;

	if (re_strcmp_dol(tmp))
		env = re_strdup(tmp, branch);
	else if (tmp[0] == '$')
	{
		env = get_result_expansion(tmp + 1, branch);
		now->flag_to_split = 1;
		if (env == NULL)
			return (NULL);
	}
	else if (tmp[0] == '\'' && ch_close(&tmp[1], '\''))
		env = re_strtrim(tmp, "\'", branch, 0);
	else if (tmp[0] == '\"' && ch_close(&tmp[1], '\"'))
	{
		env = re_strdup(tmp, branch);
		origin = expansion_in_dquote(env, branch);
		free(env);
		env = re_strtrim(origin, "\"", branch, 1);
		free(origin);
	}
	else
		env = re_strdup(tmp, branch);
	return (env);
}

char	*expansion_str(char *str, t_token *now, t_branch *branch)
{
	size_t	i;
	char	*tmp;
	char	*add;
	char	*ret;

	i = 0;
	ret = NULL;
	while (str[i])
	{
		tmp = get_exp_from(&str[i]);
		if (tmp == NULL)
			free_branch_end(branch, 1);
		add = get_exp_to(tmp, now, branch);
		ret = re_re_strjoin(ret, add, branch);
		i = i + re_strlen(tmp);
		if (tmp)
			free(tmp);
	}
	return (ret);
}

void	expansion_env(t_branch *branch)
{
	t_token	*tmp;
	char	*tobefree;

	if (branch->list == NULL)
		return ;
	tmp = *(branch->list);
	while (tmp)
	{
		tobefree = tmp->str;
		tmp->str = expansion_str(tmp->str, tmp, branch);
		free(tobefree);
		tmp = tmp->next;
	}
}
