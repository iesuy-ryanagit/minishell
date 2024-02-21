/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sidan.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:37:16 by kmotoyam          #+#    #+#             */
/*   Updated: 2024/02/21 12:54:39 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexparse/lex.h"
#include"execve.h"

void	double_free(char **path)
{
	size_t	i;

	if (path == NULL)
		return ;
	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}
