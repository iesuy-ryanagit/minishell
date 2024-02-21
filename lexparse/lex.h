/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryanagit <ryanagit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:26:10 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/21 14:15:25 by ryanagit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEX_H
# define LEX_H

# include"../base.h"

// lexparse
//_________check_char.c
int			check_one(char c);
int			check_reduc_in(char c);
int			check_reduc_out(char c);
int			check_split(char c);
int			check_stop_word(char c);

// _________check_str.c
int			str_check_reduc_in(char *str);
int			str_check_reduc_out(char *str);
int			str_check_chase(char *str);
int			str_check_heredoc(char *str);
int			str_check_pipe(char *str);

// ________check_gram.c
int			check_reduc(t_branch *branch);
int			check_pipe(t_branch *branch);
int			check_all(t_branch *branch);

// _______exp_env_list.c
char		*get_result_expansion(char *str, t_branch *branch);

// _______exp_help.c
int			ch_close(char *str, char c);
void		free_success_end(t_branch *branch);
size_t		get_index_samequote(char *str, unsigned char c);
size_t		get_index_quoteordol(char *str);

// _______exp_sup.c
size_t		get_len_name_env(char *str);
char		*get_exp_from(char *str);
int			re_strcmp_dol(char *str);
int			get_index_dol(char *str);
char		*get_exp_from_in_dq(char *str, t_branch *branch);

// ________exp.c
char		*get_exp_to_in_dq(char *tmp, t_branch *branch);
char		*expansion_in_dquote(char *str, t_branch *branch);
char		*get_exp_to(char *tmp, t_token *now, t_branch *branch);
char		*expansion_str(char *str, t_token *now, t_branch *branch);
void		expansion_env(t_branch *branch);

// ________free_end.c
void		free_end_before_token(char *str, t_branch *branch);
void		free_list(t_token **list);
void		free_branch_end(t_branch *branch, int flag);
void		free_token_list(t_branch *branch, int flag);
void		free_token_end_success(t_branch *branch);
void		free_end_exp(t_branch *branch);
void		free_env(t_env **env);

// ________get_count.c
size_t		get_count_pipe(t_token **list);
t_token		*get_pipe_next_command(t_token *tmp);
t_token		**one_pipe_line(t_token **list);
size_t		get_count_infile(t_token **list);
size_t		get_count_outfile(t_token **list);

// ________lexparse.c
t_token		*one_word_split(t_token *token);
void		shadow_steal(t_token *old, t_token *new, t_token **list);
void		word_split_roop(t_branch *branch);
void		word_lexparse(char *str, t_branch *branch);

// _______list.c
t_token		*token_create_new(char *str, int start, int len);
t_token		*token_last(t_token *lst);
void		token_add_back(t_branch *branch, t_token *new);
size_t		token_listlen(t_token **lst);

// _______parse.c
void		classify_type_one(t_token *list, int flag);
void		make_branch_command(t_branch *branch);
void		classify_type_loop(t_token **list);

// ______word_roop.c
int			stop_word_case(char *str, int i);
int			che_close(char *str, char c);
size_t		word_real_length(char *str);
size_t		get_num_command(t_token **branch);
void		word_cut_roop(char *str, t_branch *branch);
void		word_lexparse(char *str, t_branch *branch);

// ______word_split.c
size_t		exist_to_be_split(char c, char *str);
size_t		get_len(char *str, char *split, int start);
t_token		*make_new_list(char *str, int start, int len);
void		insert_new_list(t_token *tmp, t_token *prev, t_token *post);
void		split_token_add_back(t_token **list, t_token *new);

// _____env_list_base.c
t_env		*env_create_new(char *name, char *value);
t_env		*env_last(t_env *lst);
void		env_add_back(t_env **lst, t_env *new);
size_t		env_listlen(t_env **lst);

// _____env_list_make.c
char		*env_get_name(char *str);
int			check_exist_equal(char *str);
char		*env_get_value(char *str);
t_env		**make_env_list(char **str, t_branch *branch);

// _____relibft.c
char		*re_strdup(char *str, t_branch *branch);
char		*re_strtrim(char *str1, char *str2, t_branch *branch, int flag);
size_t		re_strlen(const char *str);
char		*re_re_strjoin(char *str1, char *str2, t_branch *branch);
char		*re_itoa(int value, t_branch *branch);

// _____show_errmessage.c
void		syntax_error_message(char *str);
void		command_not_found_message(char *str);
void		help_word_split_roop(t_branch *branch, t_token *ret, t_token *tmp);
void		nofile_youwant_message(char *str);
void		is_direct_message(char *str);

// triadd.c
void		delete_null(t_branch *branch);
int			help_revive(t_token *tmp);
void		revive_command(t_branch *branch);

#endif
