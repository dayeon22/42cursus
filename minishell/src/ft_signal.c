#include "../include/minishell.h"

void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		rl_on_new_line();
		rl_redisplay();
		ft_putstr_fd("  ", 1);
		ft_putstr_fd("\b\b", 1);
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (signo == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
		ft_putstr_fd("  ", 1);
		ft_putstr_fd("\b\b", 1);
	}
}

char	*get_readline(t_env *env)
{
	char	*rl;

	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	while (1)
	{
		rl = readline("minishell$ ");
		if (!rl)
		{
			free_env(env);
			ft_putstr_fd("\x1b[1A", 1);
			ft_putstr_fd("\033[11C", 1);
			write(1, "exit\n", 5);
			exit(0);
		}
		if (*rl)
			add_history(rl);
		free(rl);
	}
	return (rl);
}
