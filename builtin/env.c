/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotoyam <kmotoyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:25:52 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/20 15:41:18 by kmotoyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../lexparse/lex.h"
#include"built.h"

void	built_env(int fd, t_env **env)
{
	t_env	*tmp;

	if (env == NULL)
	{
		printf("Erorr\n");
		exit(0);
	}
	tmp = *env;
	while (tmp)
	{
		if (tmp->value)
		{
			ft_putstr_fd(tmp->name, fd);
			write(fd, "=", 1);
			ft_putstr_fd(tmp->value, fd);
			write(fd, "\n", 1);
		}
		tmp = tmp->next;
	}
}
