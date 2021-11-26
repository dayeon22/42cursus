#include "../include/minishell.h"

void	free_env(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->env_len)
		free(env->envp[i]);
	if (env->envp)
		free(env->envp);
}

void	free_one(char *str)
{
	if (str)
	{
		free(str);
		str = 0;
	}
}

void	free_two(char **str)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	if (!*str)
		return ;
	while (str[len])
		len++;
	while (++i < len)
		free(str[i]);
	if (str)
		free(str);
}

void	free_all(t_env *env, t_split *sp, int index)
{
	if (index == 2)
		free_env(env);
	sp_list_clear(sp);
}

void	free_exit(t_split *sp, t_env *env, int code)
{
	free_two(env->envp);
	sp_list_clear(sp);
	exit(code);
}
