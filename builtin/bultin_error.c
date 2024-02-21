/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultin_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotoyam <kmotoyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:22:34 by kmotoyam          #+#    #+#             */
/*   Updated: 2024/02/20 15:41:12 by kmotoyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"built.h"
#include"../lexparse/lex.h"

void	print_bultin_error(char *str, int num)
{
	if (num == 1)
	{
		ft_putstr_fd("bash: exit: ", STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putstr_fd(" : numeric argument required\n", STDERR_FILENO);
	}
}
