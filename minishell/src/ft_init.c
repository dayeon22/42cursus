#include "../include/minishell.h"

int	error_printf(char *str, int code)
{
	printf("minishell: %s\n", str);
	(void)code;
	return (0);
}

int	ft_isspace(int sp)
{
	if ((sp >= 9 && sp <= 13) || sp == 32)
		return (1);
	return (0);
}
