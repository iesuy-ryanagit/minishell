/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:22:50 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/21 15:58:10 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"execve.h"
#include"../lexparse/lex.h"

size_t	count_execve(t_token **command, size_t i)
{
	size_t	count;

	count = 0;
	if (command == NULL)
		return (0);
	while (command[i] && check_built((command[i])->str) == 0)
	{
		i++;
		count++;
	}
	return (count);
}

char	**get_env_path(t_branch *branch)
{
	t_env	*tmp;
	char	**ret;

	tmp = yet_env_exist(branch->env, "PATH");
	if (tmp == NULL)
		return (NULL);
	else
	{
		ret = ft_split(tmp->value, ':');
		if (ret == NULL)
			free_branch_end(branch, 6);
	}
	return (ret);
}

size_t	res(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
		{
			if (i == 0)
				return (i);
			else
				return (i + 1);
		}
		i++;
	}
	return (0);
}

char	*last_slash(char *str)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = str;
	while (str[i])
	{
		if (str[i] == '/')
			tmp = &(str[i + 1]);
		i++;
	}
	return (tmp);
}

void	reject_file(char **argv, char **cmd, char *path)
{
	DIR		*fd;

	fd = opendir(path);
	if (fd != NULL)
	{
		is_direct_message(path);
		double_free(argv);
		double_free(cmd);
		closedir(fd);
		exit(126);
	}
}
