/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:28:42 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/21 12:55:00 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"execve.h"
#include"../lexparse/lex.h"

void	change_heredoc(int fd, t_token *list)
{
	int	red;

	if (infile_last(list) == HERE_DOC)
	{
		if (fd > 0)
		{
			dup2(fd, STDIN_FILENO);
			close(fd);
		}
	}
	if (infile_last(list) == RED_IN)
	{
		red = open(red_in_last(list), O_RDONLY);
		dup2(red, STDIN_FILENO);
		close(red);
	}
}

void	change_pipe(t_branch *branch, size_t i, int in, int out)
{
	t_token	*com;
	size_t	len;

	len = get_command_len(branch->command);
	com = branch->command[i];
	if (c_e_tp(com, HERE_DOC) == 0 && c_e_tp(com, RED_IN) == 0 && i != 0)
	{
		dup2(in, STDIN_FILENO);
		close(in);
	}
	if (c_e_tp(com, RED_OUT) == 0 && c_e_tp(com, CHASE) == 0 && (i != len - 1))
	{
		dup2(out, STDOUT_FILENO);
		close(out);
	}
}

void	just_execve(char *cmd, char **argv, char **envp)
{
	if (execve(cmd, argv, envp) == -1)
	{
		command_not_found_message(argv[0]);
		exit(EXIT_FAILURE);
	}
}

void	end_do_execve(int fd, t_branch *branch, pid_t pid, int i)
{
	if (fd != STDIN_FILENO)
		close(fd);
	branch->child_pid[i] = pid;
}

void	do_execve(t_branch *branch, int *in, int *out, size_t i)
{
	t_command	*com;
	pid_t		pid;
	int			fd;

	fd = check_heredoc(branch->command[i], branch);
	if (g_signal_handled == 1)
		return ;
	pid = fork();
	if (pid < 0)
	{
		if (i > 0)
			close(in[0]);
		fail_execve(branch, out, fd);
	}
	if (pid == 0)
	{
		com = set_first(branch, i);
		close(out[0]);
		process_not_found(branch->command[i]->str, com, in, out);
		check_red(branch->command[i]);
		change_heredoc(fd, branch->command[i]);
		change_pipe(branch, i, in[0], out[1]);
		just_execve(com->cmd_path, com->argv, branch->envp);
	}
	end_do_execve(fd, branch, pid, i);
}
