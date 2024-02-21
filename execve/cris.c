/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cris.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:28:42 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/21 15:55:34 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"execve.h"
#include"../lexparse/lex.h"

void	try_pipe(int	*pipe_fd, int *open_fd, t_branch *branch, size_t	i)
{
	if (pipe(pipe_fd) == 0)
		return ;
	else
	{
		if (i > 0)
			close(open_fd[0]);
		free_env(branch->env);
		free_list(branch->list);
		free(branch->command);
		ft_putstr_fd("PIPE FAILED\n", STDERR_FILENO);
		exit(1);
	}
}

int	check_exist_slash(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

char	*process_slash(char **argv, char **cmd)
{
	char		*path;

	path = argv[0];
	if (access((path + res(path)), F_OK) != 0)
	{
		nofile_youwant_message(path);
		double_free(argv);
		double_free(cmd);
		exit(127);
	}
	reject_file(argv, cmd, path);
	if (access((path + res(path)), X_OK) != 0)
	{
		permission_denied_message(path);
		double_free(argv);
		double_free(cmd);
		exit(126);
	}
	return (re_strdup(path, NULL));
}
