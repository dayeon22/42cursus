#include "../include/minishell.h"

static void	sigint_setup(int signum)
{
	(void)signum;
	rl_replace_line("", 0);
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
}

static void	sigquit_setup(int signum)
{
	(void)signum;
	rl_on_new_line();
	rl_redisplay();
}

static void	setup_signal_handlers(void)
{
	signal(SIGINT, sigint_setup);
	signal(SIGQUIT, sigquit_setup);
}

static void	set_termios(t_env *env)
{
	tcgetattr(STDIN_FILENO, &env->old_term);
	tcgetattr(STDIN_FILENO, &env->new_term);
	env->new_term.c_lflag &= ~(ECHOCTL);
	env->new_term.c_cc[VMIN] = 1;
	env->new_term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &env->new_term);
}

void	get_termios_signal(t_env *env)
{
	set_termios(env);
	setup_signal_handlers();
}
