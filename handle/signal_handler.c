/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:45:13 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/21 12:55:48 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle.h"

void	heredoc_handler(int sig)
{
	if (sig == SIGINT)
		g_signal_handled = 1;
}

void	handler(int sig)
{
	if (sig == SIGINT)
	{
		g_signal_handled = 2;
		ft_putstr_fd("\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

int	set_signal(void)
{
	struct sigaction	action;

	action.sa_handler = handler;
	action.sa_flags = 0;
	g_signal_handled = 0;
	rl_event_hook = 0;
	sigemptyset(&action.sa_mask);
	sigaction(SIGINT, &action, NULL);
	signal(SIGQUIT, SIG_IGN);
	return (0);
}

int	do_execve_parent_handle(void)
{
	signal(SIGINT, SIG_IGN);
	return (0);
}

int	check_state(void)
{
	if (g_signal_handled)
	{
		rl_done = 1;
		rl_event_hook = 0;
	}
	return (130);
}
