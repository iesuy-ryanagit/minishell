/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:37:16 by kmotoyam          #+#    #+#             */
/*   Updated: 2024/02/21 15:01:25 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexparse/lex.h"
#include"../handle/handle.h"
#include"execve.h"

void	do_execute_roop(t_branch *branch)
{
	size_t	i;
	size_t	len;
	int		pre_to_post[2];
	int		post_to_pre[2];

	len = get_command_len(branch->command);
	if (len <= 1)
	{
		do_one_command(branch);
		return ;
	}
	malloc_pid(branch);
	i = 0;
	while (i < len)
	{
		try_pipe(pre_to_post, post_to_pre, branch, i);
		select_built_execve(branch, i, post_to_pre, pre_to_post);
		i = double_close(pre_to_post[1], post_to_pre[0], i);
		if (i == len)
			break ;
		try_pipe(post_to_pre, pre_to_post, branch, i);
		select_built_execve(branch, i, pre_to_post, post_to_pre);
		i = double_close(post_to_pre[1], pre_to_post[0], i);
	}
	which_close_end(pre_to_post[0], post_to_pre[0], len, branch);
}
