#include "../include/minishell.h"

int	error_printf(char *str, int code)
{
	printf("minishell: %s\n", str);
	(void)code;
	return (0);
}