/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotoyam <kmotoyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:25:52 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/20 15:41:26 by kmotoyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"built.h"

void	built_pwd(int fd)
{
	char	*buf;

	buf = ft_calloc(1, ARG_MAX);
	if (buf == NULL)
		return ;
	getcwd(buf, ARG_MAX);
	ft_putstr_fd(buf, fd);
	write(fd, "\n", 1);
	free(buf);
}
