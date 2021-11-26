#include "../include/minishell.h"

int	check_builtin(t_env *env, t_split *sp)
{
	if (!ft_strcmp(sp->str[0], "echo"))
		ft_echo(env, sp);
	else if (!ft_strcmp(sp->str[0], "cd"))
		ft_cd(env, sp);
	else if (!ft_strcmp(sp->str[0], "pwd"))
		ft_pwd(env, sp);
	else if (!ft_strcmp(sp->str[0], "export"))
		ft_export(env, sp);
	else if (!ft_strcmp(sp->str[0], "unset"))
		ft_unset(env, sp);
	else if (!ft_strcmp(sp->str[0], "env"))
		ft_env(env, sp);
	else if (!ft_strcmp(sp->str[0], "exit"))
		ft_exit(env, sp);
	else
		return (1);
	return (0);
}
