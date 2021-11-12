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
		add_history(rl);
		sp = split_read_line(rl, sp);

		/*
		// split test code
		int	i;
		while (sp)
		{
			i = -1;
			if (sp->str)
				while (sp->str[++i])
					printf("str: %s\n", sp->str[i]);
			sp = sp->next;
		}
		*/
		if (check_list(sp))
		{
			cmd_start(env, sp);
		}
		free(rl);
	}
}
