/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:45:13 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/21 12:54:42 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_H
# define HANDLE_H

# include "../base.h"

void	handler(int sig);
int		set_signal(void);
int		check_state(void);
void	heredoc_handler(int sig);
int		do_execve_parent_handle(void);

#endif