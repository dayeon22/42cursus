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
# define PWD_SIZE 1024

typedef struct s_env
{
	char			**envp;
	int				env_len;
	int				exit_n;
	struct termios	old_term;
	struct termios	new_term;
}					t_env;

typedef struct s_int
{
	int			one;
	int			two;
	int			tree;
	int			four;
	int			a_len;
}				t_int;


typedef struct s_split
{
	int				num;
	char			**str;
	int				type;
	char			*quotes;
	char			**dollar;
	char			**c_vlaue;
	int				c_len;
	struct s_env	*e;
	struct s_int	*i;
	struct s_split	*next;
}				t_split;

# include "./functions.h"

#endif
