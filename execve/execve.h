/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:37:16 by kmotoyam          #+#    #+#             */
/*   Updated: 2024/02/21 12:55:33 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECVE_H
# define EXECVE_H

# include"../base.h"
# include <fcntl.h>

// +++++base.c
size_t			count_execve(t_token **list, size_t i);
char			*set_command(char **path, char **cmd);
char			**split_command(t_token *list, t_branch *branch);
// +++++help.c
int				do_heredoc(t_token *delimiter, t_branch *branch);
void			check_red(t_token *list);

// ******helpc.c
int				check_red_c(t_token *list, t_branch *branch, int fd);
// +++++pipe.c

// +++++mini.c
size_t			get_command_len(t_token **command);
void			change_red(int fd_in, int fd_out);
int				df_out(int fd_out, int index, int len);

// built.c
void			builtin_execute(char **argv, int fd, t_branch *branch);
t_env			*yet_env_exist(t_env **env, char *name);

char			**get_env_path(t_branch *branch);
void			command_not_found_message(char *str);
void			do_execute_roop(t_branch *branch);
int				check_built(char *str);
void			builtin_execute(char **argv, int fd, t_branch *branch);

// cris.c
void			try_pipe(int	*pipe_fd, int *o_fd, t_branch *bra, size_t i);
int				check_exist_slash(char *str);

// sidan.c
void			double_free(char **path);

// show_error_message.c
void			permission_denied_message(char *str);

// heredoc.c
int				check_heredoc(t_token *list, t_branch *branch);

// help_heredoc.c
size_t			count_del(t_token *list);
char			**get_all_del(t_token *list);
void			help_do_heredoc(char *line, int fd, char **del, size_t i);
void			set_first_heredoc(char ***d, t_token *l, int p[2], t_branch *b);
void			end_heredoc(char **del, int fd_close, char *line);

// pipehelp.c
int				c_e_tp(t_token *list, int ty);
void			set_free(char *cmd_path, char **path, char **argv);
void			process_not_found(char *str, t_command *com, int *in, int *out);
int				infile_last(t_token *list);
char			*red_in_last(t_token *list);

// do_execve.c
void			change_heredoc(int fd, t_token *list);
void			change_pipe(t_branch *branch, size_t i, int in, int out);
void			just_execve(char *cmd, char **argv, char **envp);
void			end_do_execve(int fd, t_branch *branch, pid_t pid, int i);
void			do_execve(t_branch *branch, int *in, int *out, size_t i);

// do_other.c
void			do_built(t_token *cmd, t_branch *branch);
int				pnft(t_branch *b, char *c, char **p, char **a);
void			end_do_execve_parent(t_branch *branch, int fd, pid_t pid);
void			do_execve_parent(t_token *cmd, t_branch *branch);
void			do_built_child(t_token *cmd, t_branch *branch, int i, int out);

// helpipe.c
void			select_built_execve(t_branch *bra, size_t i, int *in, int *out);
void			do_one_command(t_branch *branch);
void			malloc_pid(t_branch *branch);
size_t			double_close(int fd1, int fd2, size_t i);
void			which_close_end(int fd1, int fd2, int len, t_branch *branch);

// pipe.c
void			do_execute_roop(t_branch *branch);
char			*process_slash(char **argv, char **cmd);

// add.c
void			fail_execve(t_branch *branch, int *out, int fd);
t_command		*set_first(t_branch *branch, size_t i);

// do_built_child.c
void			do_built_child(t_token *cmd, t_branch *bra, int i, int fd_out);
#endif