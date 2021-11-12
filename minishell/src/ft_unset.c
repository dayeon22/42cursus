#include "../include/minishell.h"

int	find_env(t_env *env, char *str)
{
	int		i;
	char	*equal_pos;

	i = -1;
	while (env->envp[++i])
	{
		equal_pos = ft_strchr(env->envp[i], '=');
		if (!equal_pos)
			continue ;
		if (!ft_strncmp(env->envp[i], str, equal_pos - env->envp[i]))
			return (i);
	}
	return (-1);
}

void	remove_env(t_env *env, int i)
{
	if (i < 0)
		return ;
	free(env->envp[i]);
	while (env->envp[i])
	{
		env->envp[i] = env->envp[i + 1];
		i++;
	}
}

void	ft_unset(t_env *env, t_split *sp)
{
	int	i;

	i = 0;
	while (sp->str[++i])
		remove_env(env, find_env(env, sp->str[i]));
}
