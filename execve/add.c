/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:22:50 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/21 12:33:01 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"execve.h"
#include"../lexparse/lex.h"

size_t	count_command_len(t_token *list)
{
	t_token		*tmp;
	size_t		i;

	i = 0;
	tmp = list;
	while (tmp && tmp->type != PIPE)
	{
		if (tmp && tmp->type >= RED_IN)
			tmp = tmp->next->next;
		else
		{
			tmp = tmp->next;
			i++;
		}
	}
	return (i);
}

char	**split_command(t_token *list, t_branch *branch)
{
	char	**arr;
	size_t	i;
	t_token	*tmp;

	tmp = list;
	arr = (char **)malloc(sizeof(char *) * count_command_len(tmp) + 1);
	if (arr == NULL)
	{
		ft_putstr_fd("malloc error\n", STDERR_FILENO);
		free_branch_end(branch, 1);
	}
	i = 0;
	while (list && (list->type != PIPE))
	{
		if (list->type < RED_IN && (list->prev == NULL || list->prev->type < 3))
		{
			arr[i] = re_strdup(list->str, branch);
			i++;
		}
		list = list->next;
	}
	arr[i] = NULL;
	return (arr);
}

char	*set_command(char **argv, char **cmd)
{
	char	*path;
	char	*tmp_path;
	char	*add_slash;
	int		i;

	i = 0;
	if (argv == NULL)
		return (NULL);
	path = argv[0];
	if (check_exist_slash(path) == 1)
		return (process_slash(argv, cmd));
	if (cmd == NULL)
		return (ft_strdup(path));
	while (cmd[i])
	{
		add_slash = ft_strjoin(cmd[i], "/");
		tmp_path = ft_strjoin(add_slash, path);
		free(add_slash);
		if (access(tmp_path, X_OK) == 0)
			return (tmp_path);
		free(tmp_path);
		i++;
	}
	return (NULL);
}

void	fail_execve(t_branch *branch, int *out, int fd)
{
	close(out[0]);
	close(out[1]);
	if (fd != STDIN_FILENO)
		close(fd);
	free_branch_end(branch, 10);
}

t_command	*set_first(t_branch *branch, size_t i)
{
	t_command	*ret;

	ret = malloc(sizeof(t_command) * 1);
	if (ret == NULL)
		exit(EXIT_FAILURE);
	ret->path = get_env_path(branch);
	ret->argv = split_command(branch->command[i], branch);
	ret->cmd_path = set_command(ret->argv, ret->path);
	ret->num = i;
	return (ret);
}
// void	error_fork(t_branch *branch, int here_fd, int *in, int *out)
// {
// 	if (here_fd != STDIN_FILENO)
// 		close(here_fd);
// 	if (here_fd)
// 		free_branch_end(branch, 10);
// }