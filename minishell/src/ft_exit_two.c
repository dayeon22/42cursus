#include "../include/minishell.h"

int	env_len(t_env *env)
{
	int	i;
	int	index;

	i = -1;
	index = -1;
	while (env->envp[++i])
		if (!ft_strncmp(env->envp[i], "SHLVL=", 6))
			index = ft_atoi(env->envp[i] + 6);
	return (index);
}

int	numeric_error(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}
