/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:30:03 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/22 12:25:41 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"lex.h"
#include"../execve/execve.h"

t_token	*one_word_split(t_token *token)
{
	size_t	i;
	t_token	*now;
	t_token	*ret;

	i = 0;
	ret = NULL;
	if (token->str == NULL)
		return (NULL);
	while (token->str[i])
	{
		while (token->str[i] && exist_to_be_split(token->str[i], " \n\t\v") == 1)
			i++;
		if (get_len(token->str, " \n\t\v", i) > 0)
		{
			now = make_new_list(token->str, i, get_len(token->str, " \n\t\v", i));
		}
		split_token_add_back(&ret, now);
		i += get_len(token->str, " \n\t\v", i);
	}
	free(token->str);
	free(token);
	return (ret);
}

void	shadow_steal(t_token *old, t_token *new, t_token **list)
{
	if (old->prev)
	{
		old->prev->next = new;
		new->prev = old->prev;
	}
	if (old->next)
	{
		token_last(new)->prev = new;
		new->next = old->next;
	}
	if (*(list) == old)
		*list = new;
}

void	help_word_split_roop(t_branch *branch, t_token *ret, t_token *tmp)
{
	if (*(branch->list) == NULL)
	{
		*(branch->list) = ret;
	}
	if (ret != NULL && ret->str != NULL)
	{
		if (tmp->type == COMMAND)
			ret->type = COMMAND;
		shadow_steal(tmp, ret, branch->list);
	}
}

void	word_split_roop(t_branch *branch)
{
	t_token	*tmp;
	t_token	*save;
	t_token	*ret;
	int		flag;

	if (branch->list == NULL)
		return ;
	tmp = *(branch->list);
	flag = 0;
	while (tmp)
	{
		save = tmp;
		if (tmp->flag_to_split == 1)
		{
			if (tmp->type == COMMAND)
				flag = 1;
			ret = one_word_split(tmp);
			flag = 0;
			help_word_split_roop(branch, ret, tmp);
		}
		else if (*(branch->list) == NULL)
			*(branch->list) = tmp;
		flag = 0;
		tmp = save->next;
	}
}

void	word_lexparse(char *str, t_branch *branch)
{
	branch->list = malloc(sizeof(t_token **) * 1);
	if (branch->list == NULL)
		free_end_before_token(str, branch);
	word_cut_roop(str, branch);
	if (*(branch->list) == NULL)
	{
		free(branch->list);
		return ;
	}
	classify_type_loop(branch->list);
	if (check_all(branch))
	{
		branch->exit_status = 258;
		free_list(branch->list);
		return ;
	}
	make_branch_command(branch);
	expansion_env(branch);
	word_split_roop(branch);
	delete_null(branch);
	revive_command(branch);
	free(branch->command);
	make_branch_command(branch);
	do_execute_roop(branch);
	free_success_end(branch);
}
