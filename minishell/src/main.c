#include "../include/minishell.h"

void	free_env(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->env_len)
		free(env->envp[i]);
	free(env->envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_env	env;

	(void)argc;
	(void)argv;
	if (!(copy_envp(&env, envp)))
		return (0);
	get_termios_signal(&env);
	get_readline(&env);
	return (0);
}
