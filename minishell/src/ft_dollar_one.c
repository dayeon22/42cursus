#include "../include/minishell.h"

static int	dollar_special(t_split *sp, int k, int size)
{
	if (k == 1)
	{
		sp->c_vlaue[size] = 0;
		return (1);
	}
	else if (k == 2)
	{
		sp->c_vlaue[size] = ft_itoa(sp->e->exit_n);
		return (1);
	}
	return (0);
}

int	get_dollar_env(t_split *sp, char *str, int size)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(str);
	if (dollar_special(sp, ft_special(str[0]), size) == 1)
		return (1);
	while (sp->e->envp[++i])
	{
		if (!ft_strncmp(sp->e->envp[i], str, len) && \
			sp->e->envp[i][len] == '=' && sp->e->envp[i][len + 1] != 0)
		{
			sp->c_vlaue[size] = ft_strdup(sp->e->envp[i] + (len + 1));
			if (!sp->c_vlaue[size])
				return (0);
			return (1);
		}
		else
			sp->c_vlaue[size] = 0;
	}
	return (1);
}

int	sp_special_dollar(t_split *sp, char *s, int *i, int size)
{
	int	be;
	int	j;

	be = *i;
	(*i) = (*i) + 1;
	sp->dollar[size] = (char *)ft_calloc(sizeof(char), (*i) + 1);
	if (!sp->dollar[size])
		return (0);
	j = 0;
	while (be < *i)
	{
		sp->dollar[size][j] = s[be];
		j++;
		be++;
	}
	(*i)++;
	if (!get_dollar_env(sp, sp->dollar[size], size) || !sp->dollar[size])
		return (0);
	return (1);
}

int	sp_dollar_count(t_split *sp, char *s, int i, int size)
{
	int	be;
	int	j;

	be = i;
	while (s[i] && !ft_isquotes(s[i]) && !ft_isspace(s[i]))
		++i;
	sp->dollar[size] = (char *)ft_calloc(sizeof(char), i + 1);
	if (!sp->dollar[size])
		return (0);
	j = 0;
	while (be < i)
	{
		sp->dollar[size][j] = s[be];
		j++;
		be++;
	}
	if (!get_dollar_env(sp, sp->dollar[size], size))
		return (0);
	if (!sp->dollar[size])
		return (0);
	return (1);
}

int	dollar_count(char *rl)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (rl[++i])
	{
		if (i > 0 && rl[i - 1] == '$' && rl[i] == '$')
		{
			++len;
			i = i + 2;
		}
		else if (i > 0 && rl[i - 1] == '$' && !ft_isspace(rl[i])
			&& !ft_isquotes(rl[i]))
			++len;
	}
	return (len);
}
