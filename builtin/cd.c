/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotoyam <kmotoyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:59:42 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/20 15:41:14 by kmotoyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"built.h"
#include"../lexparse/lex.h"

void	set_env_value(t_env *env_el, char *str, t_branch *branch)
{
	char	*tmp;

	tmp = env_el->value;
	env_el->value = re_strdup(str, branch);
	free(tmp);
}

void	set_pwd(char *str, char *old, t_branch *bra)
{
	t_env	*tmp;

	tmp = yet_env_exist(bra->env, "PWD");
	if (tmp != NULL)
	{
		set_env_value(tmp, str, bra);
	}
	tmp = yet_env_exist(bra->env, "OLDPWD");
	if (tmp != NULL)
		set_env_value(tmp, old, bra);
}

void	*re_calloc(char *old, t_branch *branch)
{
	void	*ret;

	ret = ft_calloc(1, ARG_MAX);
	if (ret == NULL)
	{
		if (old != NULL)
			free(old);
		free_branch_end(branch, 10);
	}
	return (ret);
}

int	built_cd(char *path, t_branch *branch)
{
	int		result;
	char	*buf;
	char	*old;

	old = re_calloc(NULL, branch);
	getcwd(old, ARG_MAX);
	result = chdir(path);
	if (result == -1)
	{	
		nofile_youwant_message(path);
		branch->exit_status = 1;
		result = result * -1;
	}
	else
	{
		buf = re_calloc(old, branch);
		getcwd(buf, ARG_MAX);
		set_pwd(buf, old, branch);
		free(buf);
	}
	free(old);
	return (result);
}

// void	built_pwd(int fd)
// {
// 	char	*buf;

// 	buf = ft_calloc(1, ARG_MAX);
// 	if (buf == NULL)
// 		return ;
// 	getcwd(buf, ARG_MAX);
// 	ft_putstr_fd(buf, fd);
// 	write(fd, "\n", 1);
// }

// int	main(void)
// {
// 	char *path="lexparse";
// 	built_pwd(STDOUT_FILENO);
// 	chdir(path);
	// built_pwd(STDOUT_FILENO);
// 	return (0);
// }
