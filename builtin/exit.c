/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:16:58 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/21 13:58:42 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"built.h"

long	get_result(char *nptr, long check, int i, t_branch *branch)
{
	long	num;

	num = 0;
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		num *= 10;
		if (check_exit(num, nptr, i, check) == 1)
		{
			print_bultin_error(nptr, 1);
			branch->exit_status = 255;
			exit(255);
		}
		num += nptr[i] - '0';
		i++;
	}
	if (!ft_isdigit(nptr[i]) && nptr[i] != '\0')
	{
		print_bultin_error(nptr, 1);
		branch->exit_status = 255;
		exit(255);
	}
	return (num);
}

long	ft_strtol(char *nptr, t_branch *branch)
{
	long	check;
	int		i;

	check = 1;
	i = 0;
	if (nptr[i] == '-')
	{
		check = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	return (get_result(nptr, check, i, branch) * check);
}

void	get_exit_status(long arg_num, t_branch *branch)
{
	long	tmp;

	if (arg_num == LONG_MIN)
	{
		branch->exit_status = 0;
		arg_num = 0;
	}
	else if (arg_num < 0)
	{
		arg_num *= -1;
		tmp = arg_num % 256;
		arg_num = 256 - tmp;
	}
	else if (arg_num >= 0)
	{
		while (arg_num >= 256)
			arg_num %= 256;
	}
	ft_putstr_fd("exit\n", STDERR_FILENO);
	branch->exit_status = arg_num;
	exit(arg_num);
}

int	built_exit(char **argv, t_branch *branch)
{
	int		i;
	long	arg_num;

	i = 0;
	while (argv[i])
		i++;
	if (i == 1)
	{
		ft_putstr_fd("exit\n", STDERR_FILENO);
		branch->exit_status = 0;
		exit(0);
	}
	arg_num = ft_strtol(argv[1], branch);
	if (i >= 3)
	{
		ft_putstr_fd("bash: exit: too many arguments\n", STDERR_FILENO);
		branch->exit_status = 1;
		return (1);
	}
	get_exit_status(arg_num, branch);
	return (-1);
}
