/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:37:16 by kmotoyam          #+#    #+#             */
/*   Updated: 2024/02/21 12:55:36 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexparse/lex.h"
#include"../handle/handle.h"
#include"execve.h"

void	select_built_execve(t_branch *branch, size_t i, int *in, int *out)
{
	size_t	l;

	l = get_command_len(branch->command);
	if (check_built(branch->command[i]->str) == 1)
	{
		close(in[0]);
		do_built_child(branch->command[i], branch, i, df_out(out[1], i, l));
	}
	else
		do_execve(branch, in, out, i);
}

void	do_one_command(t_branch *branch)
{
	if (get_command_len(branch->command) == 0)
		return ;
	if (check_built(branch->command[0]->str) == 1)
		do_built(branch->command[0], branch);
	else
		do_execve_parent(branch->command[0], branch);
}

void	malloc_pid(t_branch *branch)
{
	size_t	len;
	size_t	i;

	if (branch->child_pid != NULL)
		free(branch->child_pid);
	len = get_command_len(branch->command);
	branch->child_pid = malloc((len + 1) * sizeof(pid_t));
	if (branch->child_pid == NULL)
		return ;
	i = 0;
	while (i < len + 1)
	{
		branch->child_pid[i] = 0;
		i++;
	}
}

size_t	double_close(int fd1, int fd2, size_t i)
{
	close(fd1);
	if (i > 0)
		close(fd2);
	return (i + 1);
}

void	which_close_end(int fd1, int fd2, int len, t_branch *branch)
{
	size_t	i;

	if (len % 2 == 0)
		close(fd1);
	else
		close(fd2);
	branch->child_pid[len] = 0;
	i = 0;
	while (branch->child_pid[i] != 0)
	{
		waitpid(branch->child_pid[i], &(branch->exit_status), 0);
		if (branch->exit_status == 256)
			branch->exit_status = 1;
		i++;
	}
}
