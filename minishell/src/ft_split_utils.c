#include "../include/minishell.h"

int space_clear(char *rl, int *i)
{
	while (ft_isspace(rl[*i]))
		(*i)++;
	return (*i);
}

int	doallr_count(char *rl)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (rl[++i])
	{
		if (i > 0 && rl[i - 1] == '$' && !ft_isspace(rl[i]))
			++len;
	}
	return (len);
}

int	quotes_check(char *rl, int *i, t_split *sp, int *size)
{
	char	quote;

	quote = rl[*i];
	(*i)++;
	while (rl[*i])
	{
		if (rl[*i - 1] == '$' && !ft_isspace(rl[*i]))
			sp->quotes[(*size)++] = quote;
		if (rl[*i] == quote)
			return (1);
		(*i)++;
	}
	return (error_printf("There is only one quote error.", 127));
}
