#include "../include/minishell.h"

int	check_builtin(t_env *env, t_split *sp)
{
	if (ft_strcmp(sp->str[0], "echo"))
		printf("ft_echo()\n");
	else if (ft_strcmp(sp->str[0], "cd"))
		printf("ft_cd()\n");
	else if (ft_strcmp(sp->str[0], "pwd"))
		printf("ft_pwd()\n");
	else if (ft_strcmp(sp->str[0], "export"))
		printf("ft_export()\n");
	else if (ft_strcmp(sp->str[0], "unset"))
		printf("ft_strcmp()\n");
	else if (ft_strcmp(sp->str[0], "env"))
		printf("ft_env()\n");
	else if (ft_strcmp(sp->str[0], "exit"))
		printf("ft_exit()\n");
	else
		return (1);
	return (0);
}
