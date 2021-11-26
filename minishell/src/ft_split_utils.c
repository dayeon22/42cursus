#include "../include/minishell.h"

int	space_clear(char *rl, int *i)
{
	while (ft_isspace(rl[*i]))
		(*i)++;
	return (*i);
}

int	quotes_check(char *rl, int *i, t_split *sp, int *size)
{
	char	quote;

	quote = rl[*i];
	(*i)++;
	while (rl[*i])
	{
		if (rl[*i - 1] == '$' && !ft_isspace(rl[*i]) && !ft_isquotes(rl[*i]))
		{
			if (!sp_dollar_count(sp, rl, *i, *size))
				return (error_printf(sp->e, "malloc error", 127));
			sp->quotes[(*size)++] = quote;
		}
		if (rl[*i] == quote)
			return (1);
		(*i)++;
	}
	return (error_printf(sp->e, "There is only one quote error.", 127));
}
