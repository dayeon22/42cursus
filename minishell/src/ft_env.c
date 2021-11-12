#include "../include/minishell.h"

void	ft_env(t_env *env, t_split *sp)
{
	int	i;

	i = 0;
	if (sp->str[1])
	{
		printf("No such file of directory\n");
		return ;
	}
	while (env->envp[i])
		printf("%s\n", env->envp[i++]);
	(void)sp;
}
