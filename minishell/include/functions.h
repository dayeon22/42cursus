#ifndef FUNCTIONS_H
# define FUNCTIONS_H

/*ft_builtin.c*/
int				check_builtin(t_env *env, t_split *sp);

/*ft_cd_one.c*/
void			ft_cd(t_env *env, t_split *sp);

/*ft_cd_two.c*/
void			env_pwd_input(t_env *env, char *path);
void			env_oldpwd_input(t_env *env, char *path, char c);

/*ft_check_list.c*/
int				check_list(t_split *sp);

/*ft_cmd_one.c*/
char			**envp_lookup(char **envp, char *find);
int				lookup_bin_path(char *order, char **path, char **envp);
void			exec_bin_path(t_split *sp, t_env *env);
int				single_list_cmd(t_split *sp, t_env *env);
int				cmd_start(t_env *env, t_split *sp);

/*ft_cmd_two.c*/
int				command_exit(int status);
char			*connection_order(char *str, char *order);
int				bin_complete(char *order, char **bin_path, char **path);

/*ft_dollar.c*/
int				get_dollar_env(t_split *sp, char *str, int size);
int				sp_dollar_count(t_split *sp, char *s, int i, int size);
int				dollar_count(char *rl);

/*ft_env.c*/
void			ft_env(t_env *env, t_split *sp);

/*ft_error.c*/
int				error_printf(char *str, int code);

/*ft_exit_one.c*/
void			ft_exit(t_env *env, t_split *sp);

/*ft_exit_two.c*/
int				env_len(t_env *env);
int				numeric_error(char *str);

/*ft_export.c*/
void			ft_export(t_env *env, t_split *sp);
void			change_env(t_env *env, char *str, int env_idx);
void			add_env(t_env *env, char *str);
int				env_name_check(char *str);
void			print_sorted_env(t_env *env);
void			print_env(char **envp);
void			sort_env(char **envp, int envp_len);

/*ft_free.c*/
void			free_env(t_env *env);
void			free_one(char *str);
void			free_two(char **str);
void			free_all(t_env *env, t_split *sp, int index);
void			free_exit(t_split *sp, t_env *env, int code);

/*ft_list_utils1.c*/
t_split			*sp_new_init(t_env *env);
void			sp_add_back(t_split **sp, t_split *new);
t_split			*sp_list_del(t_split *sp);
void			sp_list_clear(t_split *sp);

/*ft_list_utils2.c*/
int				sp_list_size(t_split *sp);
int				sp_word_size(t_split *sp);

/*ft_pwd.c*/
void			ft_pwd(t_env *env, t_split *sp);

/*ft_readline*/
void			get_readline(t_env *env, t_split *sp);

/*ft_shlvl*/
int				extend_envp(t_env *env);
void			set_shlvl(t_env *env, int index, int i);
int				copy_envp(t_env *env, char **envp);

/*ft_signal*/
void			get_termios_signal(t_env *env);

/*ft_split_rl.c*/
t_split			*split_read_line(char *rl, t_split *sp, t_env *env);

/*ft_split_utils.c*/
int				space_clear(char *rl, int *i);
int				quotes_check(char *rl, int *i, t_split *sp, int *size);

/*ft_init*/
int				error_printf(char *str, int code);
int				ft_isspace(int sp);

/*ft_unset.c*/
int				find_env(t_env *env, char *str);
void			remove_env(t_env *env, int i);
void			ft_unset(t_env *env, t_split *sp);

/*ft_utils_one.c*/
int				sp_str_len(t_split *sp);
int				ft_isspace(int sp);
int				ft_isquotes(char sp);
char			*select_path(t_env *env, char *str);

/*ft_utils.c*/
void			double_free(char **words);



char	**apply_dollar(t_split *sp);

#endif
