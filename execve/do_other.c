/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_other.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:28:42 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/21 12:55:17 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"execve.h"
#include"../lexparse/lex.h"
#include"../handle/handle.h"

void	do_built(t_token *cmd, t_branch *branch)
{
	char	**argv;
	int		fd;

	while (cmd && cmd->type != COMMAND)
		cmd = cmd->next;
	fd = check_heredoc(cmd, branch);
	if (fd > 0)
		close(fd);
	fd = STDOUT_FILENO;
	fd = check_red_c(cmd, branch, fd);
	if (fd < 0)
		return ;
	if (g_signal_handled == 1)
		return ;
	argv = split_command(cmd, branch);
	builtin_execute(argv, fd, branch);
}

int	pnft(t_branch *br, char *cd_p, char **path, char **argv)
{
	char	*str;

	str = br->command[0]->str;
	if (cd_p == NULL)
	{
		command_not_found_message(str);
		set_free(cd_p, path, argv);
		br->exit_status = 127;
		return (1);
	}
	else
		return (0);
}

void	end_do_execve_parent(t_branch *branch, int fd, pid_t pid)
{
	do_execve_parent_handle();
	if (fd > 0)
		close(fd);
	waitpid(pid, &(branch->exit_status), 0);
	if (branch->exit_status == 256)
		branch->exit_status = 1;
}

void	fail_execve_parent(pid_t pid, t_branch *branch, int fd)
{
	if (pid < 0)
	{
		if (fd != STDIN_FILENO)
			close(fd);
		free_branch_end(branch, 10);
	}
}

void	do_execve_parent(t_token *cmd, t_branch *branch)
{
	char	**path;
	char	*cmd_path;
	char	**argv;
	pid_t	pid;
	int		fd;

	cmd = branch->command[0];
	fd = check_heredoc(cmd, branch);
	if (g_signal_handled == 1)
		return ;
	pid = fork();
	fail_execve_parent(pid, branch, fd);
	if (pid == 0)
	{
		path = get_env_path(branch);
		argv = split_command(cmd, branch);
		cmd_path = set_command(argv, path);
		if (pnft(branch, cmd_path, path, argv))
			exit(127);
		check_red(cmd);
		change_heredoc(fd, cmd);
		just_execve(cmd_path, argv, branch->envp);
	}
	end_do_execve_parent(branch, fd, pid);
}
