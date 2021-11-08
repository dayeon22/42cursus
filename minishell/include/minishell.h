#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
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

# define PIPE -1
# define DOLLAR -2
# define RIGHT -3
# define LEFT -4
# define SPC -5

typedef struct s_cmd
{
	char			*command;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_env
{
	char			**envp;
	int				env_len;
	struct termios	old_term;
	struct termios	new_term;
}					t_env;
/*main.c*/
void			free_env(t_env *env);
/*ft_shlvl*/
int				copy_envp(t_env *env, char **envp);
void			set_shlvl(t_env *env, int index, int i);
int				extend_envp(t_env *env);
/*ft_signal*/
void			get_termios_signal(t_env *env);
/*ft_readline*/
void			get_readline(t_env *env);
/*ft_command.c*/
//int				run_command(char **words, t_env *env);
//int				run_builtins(char **words, t_env *env);
/* parse.c */
void			parse(char *line, t_cmd *cmd);
void			handle_signle_quotes(char **line, char **new_line);
void			handle_double_quotes(char **line, char **new_line);
void			handle_special_characters(char **line, char **new_line);
void			replace_symbol(char *line);
#endif
