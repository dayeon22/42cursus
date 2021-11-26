#include "../include/minishell.h"

int	error_printf(t_env *env, char *str, int code)
{
	printf("minishell: %s\n", str);
	env->exit_n = code;
	return (0);
}
