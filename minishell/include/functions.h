/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@studen.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:13:32 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/18 09:59:00 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

int				check_builtin(t_env *env, t_split *sp, int count);
int				check_builtin_great(t_env *env);
int				ft_cd(t_env *env, t_split *sp);
int				env_pwd_input(t_env *env, char *path, int index);
int				env_oldpwd_input(t_env *env, char *path, int index);
int				cd_mark_minus(t_env *env, char *str, int len);
int				cd_mark_wave(t_env *env, char *str, int len);
int				ft_cd_redir(t_env *env);
int				check_list(t_split *sp);
int				lookup_bin_path(char *order, char **path, char **envp);
int				exec_bin_path(t_env *env, t_split *sp);
int				single_list_cmd(t_env *env, t_split *sp);
int				cmd_start(t_env *env, t_split *sp);
int				command_exit(int status);
int				bin_complete(char *order, char **bin_path, char **path);
int				exec_redirection(t_env *env);
t_split			*save_option_join(t_env *env, t_split *sp, int t);
int				get_here_document(t_env *env, char *eof, char *rl);
int				get_dollar_env(t_split *sp, char *str, int size);
int				sp_dollar_count(t_split *sp, char *s, int i, int size);
int				dollar_count(char *rl);
int				sp_special_dollar(t_split *sp, char *rl, int *i, int size);
char			**apply_dollar(t_split *sp);
int				ft_echo(t_env *env, t_split *sp);
int				ft_echo_redir(t_env *env);
int				ft_env(t_env *env, t_split *sp);
int				ft_env_redir(t_env *env);
int				e_code(t_env *env, char *str, int code);
void			finish_exit(t_env **env, t_split **sp, int check);
int				ft_exit(t_env *env, t_split *sp);
int				ft_exit_redir(t_env *env);
int				numeric_error(char *str);
int				exit_error_collect(t_env *env, char **str, int num);
int				exit_init(int num);
int				add_env(t_env *env, char *str);
int				ft_export(t_env *env, t_split *sp);
int				ft_export_redir(t_env *env);
int				print_sorted_env(t_env *env);
int				free_one_point(void *str);
int				free_two_point(char **str);
void			free_cmd_list(t_env **env, t_split **sp);
t_split			*make_process(t_env *env, t_split *sp);
int				last_great(t_env *env, int *left);
void			redir_env_init(t_env *env);
int				last_less(t_env *env);
int				last_less2(t_env *env, int *left);
int				ft_pwd(t_env *env, t_split *sp);
int				ft_pwd_redir(t_env *env);
void			get_readline(t_env *env, t_split *sp);
int				run_redirection_pipe(t_split *sp, t_env *env);
int				two_point_join(t_env *env, t_split *sp, int t);
int				copy_envp(t_env *env, char **envp);
void			signal_ign(void);
void			set_termios(t_env *env);
void			get_termios_signal(t_env *env);
void			cat_termios_signal(t_env *env);
int				signal_other(t_env *env, t_split *sp);
void			setup_signal_handlers(t_env *env);
void			redir_signal_handlers(void);
t_split			*split_read_line(char *rl, t_split *sp, t_env *env);
t_split			*sp_new_init(t_env *env);
void			sp_add_back(t_split **sp, t_split *new);
void			sp_list_clear(t_split **sp);
int				sp_list_size(t_split *sp);
int				quotes_check(char *rl, int *i, t_split *sp, int *size);
int				find_env(t_env *env, char *str);
int				ft_unset(t_env *env, t_split *sp);
int				ft_unset_redir(t_env *env);
int				space_clear(char *rl, int *i);
int				ft_isspace(int sp);
int				ft_isquotes(char sp);
int				ft_special(char c);
char			*select_path(t_env *env, char *str);
void			sp_null_fill(t_split **sp, int len);
void			one_point_null_fill(char **str, int size);
int				sp_type_check(t_split *sp);
int				sp_type_int(t_split *sp, int type);
int				type_check_int(int type);
char			**ft_split_mini(char *s, char c);
int				two_point_size(char **s);
int				select_env_index(t_env *env, char *str);
int				file_delet(t_env *env);
int				make_pipe_process(t_split *sp, t_env *env, int *left);
int				last_pipe(t_env *env, t_split *sp, int *left);
int				one_redirection_pipe(t_split *sp, t_env *env, int *left);

#endif
