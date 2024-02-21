/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotoyam <kmotoyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:38:37 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/20 15:41:09 by kmotoyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"built.h"

void	free_argv(char **argv)
{
	size_t	i;

	i = 0;
	if (argv == NULL)
		return ;
	else
	{
		while (argv[i])
			free(argv[i++]);
		free(argv);
	}
}

void	show_all_export(t_branch *branch, int fd)
{
	t_env	*tmp;

	tmp = *(branch->env);
	while (tmp)
	{
		ft_putstr_fd("declare -x ", fd);
		ft_putstr_fd(tmp->name, fd);
		if (tmp->value)
		{
			ft_putstr_fd("=\"", fd);
			ft_putstr_fd(tmp->value, fd);
			ft_putstr_fd("\"", fd);
		}
		ft_putstr_fd("\n", fd);
		tmp = tmp->next;
	}
}

void	builtin_execute(char **argv, int fd, t_branch *branch)
{
	int	flag;

	flag = 0;
	if (ft_strncmp(argv[0], "cd", 3) == 0)
		flag = built_cd(argv[1], branch);
	if (ft_strncmp(argv[0], "echo", 5) == 0)
		built_echo(fd, argv);
	if (ft_strncmp(argv[0], "env", 4) == 0)
		built_env(fd, branch->env);
	if (ft_strncmp(argv[0], "exit", 5) == 0)
		flag = built_exit(argv, branch);
	if (ft_strncmp(argv[0], "export", 7) == 0)
		flag = built_export(argv, branch, fd);
	if (ft_strncmp(argv[0], "pwd", 4) == 0)
		built_pwd(fd);
	if (ft_strncmp(argv[0], "unset", 6) == 0)
		built_unset(argv, branch);
	free_argv(argv);
	branch->exit_status = flag;
}
