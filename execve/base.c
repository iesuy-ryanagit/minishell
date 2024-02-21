/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:22:50 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/21 13:53:39 by ryanagit         ###   ########.fr       */
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
	if (access((path + res(path)), X_OK) != 0)
	{
		permission_denied_message(path);
		double_free(argv);
		double_free(cmd);
		exit(126);
	}
	return (re_strdup(path, NULL));
}
