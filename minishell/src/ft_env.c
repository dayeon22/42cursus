#include "../include/minishell.h"

void	ft_env(t_env *env, t_split *sp)
{
	int	i;

	if (sp->str[1])
	{
		ft_putstr_fd("No such file or directory\n", 2);
		return ;
	}
	i = -1;
	while (env->envp[++i])
	{
		if (!ft_strchr(env->envp[i], '='))
			continue ;
		printf("%s\n", env->envp[i]);
	}
	(void)sp;
}
