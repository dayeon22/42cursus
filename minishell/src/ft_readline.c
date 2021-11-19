#include "../include/minishell.h"

static void	signal_d_exit(t_env *env)
{
	free_env(env);
	ft_putstr_fd("\x1b[1A", 1);
	ft_putstr_fd("\033[11C", 1);
	write(1, "exit\n", 5);
	tcsetattr(STDIN_FILENO, TCSANOW, &env->old_term);
	exit(0);
}

void	get_readline(t_env *env, t_split *sp)
{
	char	*rl;

	while (1)
	{
		rl = readline("minishell$ ");
		if (!rl)
			signal_d_exit(env);
		if (ft_strlen(rl) > 0)
		{
			add_history(rl);
			sp = split_read_line(rl, sp, env);
			apply_dollar(sp);
			if (sp && check_list(sp))
			{
				cmd_start(env, sp);
			}
		}
		free(rl);
	}
}
/*
			int	i;
			while (sp)
			{
				printf("num: %d\n", sp->num);
				i = -1;
				if (sp->str)
					while (sp->str[++i])
						printf("str: %s\n", sp->str[i]);
				i = -1;
				if (sp->quotes)
					while (sp->quotes[++i])
						printf("quotes: %c\n", sp->quotes[i]);
				i = -1;
				if (sp->dollar)
					while (sp->dollar[++i])
						printf("dollar: %s\n", sp->dollar[i]);
				i = -1;
				if (sp->c_vlaue)
					while (++i < sp->c_len)
						printf("c_vlaue: %s\n", sp->c_vlaue[i]);
				printf("c_len: %d\n", sp->c_len);
				sp = sp->next;
			}
*/
