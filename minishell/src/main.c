#include "../include/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_env	env;
	t_split	sp;

	(void)argc;
	(void)argv;
	if (!(copy_envp(&env, envp)))
		return (0);
	get_termios_signal(&env);
	get_readline(&env, &sp);
	return (0);
}
