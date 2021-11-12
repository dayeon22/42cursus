#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <sys/stat.h>
# include <string.h>
# include <fcntl.h>
# include <signal.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include "../libft/libft.h"
/*|, <, <<, >, >>*/
# define CHAR_PIPE -1
# define CHAR_LESS -2
# define CHAR_DLESS -3
# define CHAR_GREAT -4
# define CHAR_DGREAT -5
# define CHAR_WORD -6

typedef struct s_env
{
	char			**envp;
	int				env_len;
	struct termios	old_term;
	struct termios	new_term;
}					t_env;

typedef struct s_split
{
	char			**str;
	int				type;
	int				quotes;
	struct s_split	*next;
}				t_split;

/*main.c*/
void			free_env(t_env *env);
/*ft_shlvl*/
int				copy_envp(t_env *env, char **envp);
void			set_shlvl(t_env *env, int index, int i);
int				extend_envp(t_env *env);
/*ft_signal*/
void			get_termios_signal(t_env *env);
/*ft_readline*/
void			get_readline(t_env *env, t_split *sp);
/*ft_split_rl.c*/
t_split			*split_read_line(char *rl, t_split *sp);
/*ft_init*/
int				error_printf(char *str, int code);
int				ft_isspace(int sp);
/*ft_check_list.c*/
int				check_list(t_split *sp);
/*ft_list_utils.c*/
t_split			*sp_new_init(void);
void			sp_add_back(t_split **sp, t_split *new);
int				sp_list_size(t_split *sp);
/*ft_cmd_one.c*/
int				cmd_start(t_env *env, t_split *sp);
int				single_list_cmd(t_split *sp, t_env *env);
void			exec_bin_path(t_split *sp, t_env *env);
int				lookup_bin_path(char *order, char **path, char **envp);
char			**envp_lookup(char **envp, char *find);
/*ft_cmd_two.c*/
int				bin_complete(char *order, char **bin_path, char **path);
char			*connection_order(char *str, char *order);
int				command_exit(int status);
/*ft_error.c*/
void			free_two(char **str);
void			sp_list_clear(t_split *sp);
void			free_exit(t_split *sp, t_env *env, int code);
/*ft_builtin.c*/
int		check_builtin(t_env *env, t_split *sp);
/*ft_env.c*/
void			ft_env(t_env *env, t_split *sp);
/*ft_unset.c*/
void			ft_unset(t_env *env, t_split *sp);
int				find_env(t_env *env, char *str);
/*ft_export.c*/
void			ft_export(t_env *env, t_split *sp);
/*ft_utils.c*/
void			double_free(char **words);
#endif
