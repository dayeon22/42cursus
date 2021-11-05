#include "../include/minishell.h"

void	signal_setup(int signum)
{
	if (signum == SIGINT)
	{
		rl_replace_line("", 0);
		write(1, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
	}
	else if (signum == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

void	setup_signal_handlers(void)
{
	signal(SIGINT, signal_setup);
	signal(SIGQUIT, signal_setup);
}

void	set_termios(t_env *env)
{
	tcgetattr(STDIN_FILENO, &env->new_term);
	env->new_term.c_lflag &= ~(ECHOCTL);
	env->new_term.c_cc[VMIN] = 1;
	env->new_term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &env->new_term);
}

char	*get_readline(t_env *env)
{
	char	*rl;

	set_termios(env);
	setup_signal_handlers();
	while (1)
	{
		rl = readline("minishell$ ");
		if (!rl)
		{
			free_env(env);
			ft_putstr_fd("\x1b[1A",1);
			ft_putstr_fd("\033[11C",1);
			write(1, "exit\n", 5);
			exit(0);
		}
		if (*rl)
			add_history(rl);
		free(rl);
	}
	return (rl);
}
