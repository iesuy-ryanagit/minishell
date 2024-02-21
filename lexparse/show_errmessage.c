/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_errmessage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotoyam <kmotoyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:04:06 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/20 15:42:11 by kmotoyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"lex.h"

void	syntax_error_message(char *str)
{
	ft_putstr_fd("minishell: syntax error near", STDERR_FILENO);
	ft_putstr_fd(" unexpected token '", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("\'\n", STDERR_FILENO);
}

void	command_not_found_message(char *str)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": command not found", STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	permission_denied_message(char *str)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": Permission denied", STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	nofile_youwant_message(char *str)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": No such file or directory", STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	is_direct_message(char *str)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": Is a directory", STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}
