/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotoyam <kmotoyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:29:42 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/20 15:42:01 by kmotoyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"lex.h"

void	free_list(t_token **list)
{
	t_token	*tmp;
	t_token	*stay;

	if (list == NULL)
		exit(1);
	tmp = *list;
	while (tmp)
	{
		stay = tmp;
		free(tmp->str);
		free(tmp);
		tmp = stay->next;
	}
	free(list);
}

void	free_env(t_env **env)
{
	t_env	*tmp;
	t_env	*stay;

	tmp = *env;
	while (tmp)
	{
		stay = tmp;
		free(tmp->name);
		free(tmp->value);
		free(tmp);
		tmp = stay->next;
	}
	free(env);
}

void	free_end_before_token(char *str, t_branch *branch)
{
	free(str);
	free(branch->command);
	free_env(branch->env);
	free(branch);
	printf("malloc failed to allocate memory for double double point list\n");
	exit(0);
}

void	free_token_list(t_branch *branch, int flag)
{
	free_list(branch->list);
	free_env(branch->env);
	free(branch);
	if (flag == 0)
		printf("Unfortunately, something wrong while making token \n");
	else if (flag == 1)
		printf("Unfortunately, something wrong while making token \n");
	else if (flag == 2)
		printf("Unfortunately, A syntax error you make \n");
	else if (flag == 3)
		printf("malloc failed to allocate memory for pointer branch\n");
}

void	free_branch_end(t_branch *branch, int flag)
{
	free_list(branch->list);
	free_env(branch->env);
	free(branch);
	if (flag == 0)
		printf("Success end \n");
	else if (flag == 1)
		printf("Expansion Error : rere_strjoin \n");
	else if (flag == 3)
		printf("Expansion Error : re_strdup \n");
	if (flag > 0)
		exit(EXIT_FAILURE);
}
