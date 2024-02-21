/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotoyam <kmotoyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:28:42 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/19 16:28:01 by kmotoyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"execve.h"

size_t	get_command_len(t_token **command)
{
	size_t	i;

	i = 0;
	if (command == NULL)
		return (0);
	while (command[i])
		i++;
	return (i);
}

void	change_red(int fd_in, int fd_out)
{
	if (fd_in != STDIN_FILENO)
	{
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
	}
	if (fd_out != STDOUT_FILENO)
	{
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
	}
}

int	df_out(int fd_out, int index, int len)
{
	if (index == len - 1)
		return (STDOUT_FILENO);
	else
		return (fd_out);
}

int	check_built(char *str)
{
	if (ft_strncmp(str, "cd", 3) == 0)
		return (1);
	if (ft_strncmp(str, "echo", 5) == 0)
		return (1);
	if (ft_strncmp(str, "env", 4) == 0)
		return (1);
	if (ft_strncmp(str, "exit", 5) == 0)
		return (1);
	if (ft_strncmp(str, "export", 7) == 0)
		return (1);
	if (ft_strncmp(str, "pwd", 4) == 0)
		return (1);
	if (ft_strncmp(str, "unset", 6) == 0)
		return (1);
	return (0);
}
