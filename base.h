/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:33:54 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/21 17:59:57 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <signal.h>
# include <sys/stat.h>
# include "libft/libft.h"
# include <dirent.h>
# include <errno.h>

extern sig_atomic_t		g_signal_handled;
typedef struct s_token	t_token;

enum e_type {
	COMMAND,
	OPTION,
	PIPE,
	RED_IN,
	RED_OUT,
	CHASE,
	HERE_DOC
};

typedef struct s_token {
	char			*str;
	enum e_type		type;
	struct s_token	*next;
	struct s_token	*prev;
	int				flag_to_split;
}	t_token;

typedef struct s_env {
	char			*name;
	char			*value;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

typedef struct s_branch {
	struct s_token	**list;
	struct s_token	**command;
	struct s_env	**env;
	char			**envp;
	int				exit_status;
	pid_t			*child_pid;
}	t_branch;

typedef struct s_command {
	char			**path;
	char			*cmd_path;
	char			**argv;
	size_t			num;
}	t_command;

#endif