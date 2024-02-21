/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:07:04 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/20 11:19:44 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_H
# define BUILT_H
# include"../base.h"
// _______cd.c
size_t	len_command(char **str);
size_t	check_flag_nopution(char *str);
void	built_echo(int fd, char **str);
void	built_env(int fd, t_env **env);
t_env	*yet_env_exist(t_env **env, char *name);
int		built_export(char **str, t_branch *list, int fd);
void	built_pwd(int fd);
void	delete_one_env(t_env **env, char *name);
void	built_unset(char **str, t_branch *list);
int		built_exit(char **argv, t_branch *branch);
void	print_bultin_error(char *str, int num);
int		built_cd(char *path, t_branch *branch);

// _______exit.c
int		check_over(char digit, long check, int i);
int		check_digit(int i);
int		check_exit(long num, char *nptr, int i, long check);
void	show_all_export(t_branch *branch, int fd);
#endif
