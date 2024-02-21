/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_execve_bc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:40:47 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/21 17:33:50 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"execve.h"
#include"../lexparse/lex.h"
#include"../handle/handle.h"

void	error_built_child(t_branch *branch, pid_t pid, int fd, int fd_out)
{
	if (pid < 0)
	{
		if (fd != STDIN_FILENO)
			close(fd);
		close(fd_out);
		free_branch_end(branch, 10);
	}
}

void	dup_out(int fd_out)
{
	if (fd_out != STDOUT_FILENO)
	{
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
	}
}

void	do_built_child(t_branch *branch, size_t i, int fd_out, int *in)
{
	t_token	*cmd;
	char	**argv;
	pid_t	pid;
	int		fd;

	cmd = branch->command[i];
	fd = check_heredoc(cmd, branch);
	pid = fork();
	error_built_child(branch, pid, fd, fd_out);
	if (pid == 0)
	{
		if (i != 0)
			close(in[0]);
		dup_out(fd_out);
		check_red(cmd);
		change_heredoc(fd, cmd);
		argv = split_command(cmd, branch);
		builtin_execute(argv, STDOUT_FILENO, branch);
		exit(branch->exit_status);
	}
	if (fd != STDIN_FILENO)
		close(fd);
	branch->child_pid[i] = pid;
}
