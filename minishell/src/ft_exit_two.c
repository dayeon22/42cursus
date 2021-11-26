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

void	exit_error_collect(t_env *env, t_split *sp, int num)
{
	if (num)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		env->exit_n = 2;
	}
	else
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(sp->str[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		env->exit_n = 255;
	}
}
