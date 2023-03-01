/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollar_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:09:27 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/18 17:43:17 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	dollar_special(t_split *sp, int k, int size)
{
	if (k == 1)
	{
		sp->c_vlaue[size] = 0;
		return (0);
	}
	else if (k == 2)
	{
		sp->c_vlaue[size] = ft_itoa(sp->e->exit_n);
		return (0);
	}
	return (1);
}

int	get_dollar_env(t_split *sp, char *str, int size)
{
	int		check;
	char	*cp;

	check = ft_special(str[0]);
	if (!dollar_special(sp, check, size))
		return (0);
	if (!check || check == 3)
	{
		cp = select_path(sp->e, str);
		if (cp && cp[0] == '=' && cp[1])
		{
			sp->c_vlaue[size] = ft_strdup(cp + 1);
			if (!sp->c_vlaue[size])
				return (1);
		}
		else
			sp->c_vlaue[size] = 0;
	}
	return (0);
}

int	sp_special_dollar(t_split *sp, char *rl, int *i, int size)
{
	int	be;
	int	af;
	int	j;

	be = *i;
	af = *i + 1;
	sp->dollar[size] = (char *)malloc(sizeof(char) * 3);
	if (!sp->dollar[size])
		return (1);
	one_point_null_fill(&sp->dollar[size], 2);
	j = 0;
	while (be < af)
	{
		sp->dollar[size][j] = rl[be];
		j++;
		be++;
	}
	sp->dollar[size][j] = 0;
	(*i)++;
	if (get_dollar_env(sp, sp->dollar[size], size) || !sp->dollar[size])
		return (1);
	return (0);
}

int	sp_dollar_count(t_split *sp, char *s, int i, int size)
{
	int	be;
	int	j;

	be = i;
	while (s[i] && !ft_isquotes(s[i]) && !ft_isspace(s[i]))
		++i;
	sp->dollar[size] = (char *)malloc(sizeof(char) * (i + 1));
	if (!sp->dollar[size])
		return (1);
	one_point_null_fill(&sp->dollar[size], i);
	j = 0;
	while (be < i)
	{
		sp->dollar[size][j] = s[be];
		j++;
		be++;
	}
	if (get_dollar_env(sp, sp->dollar[size], size) || !sp->dollar[size])
		return (1);
	return (0);
}

int	dollar_count(char *rl)
{
	int	i;
	int	len;
	int	q;

	i = -1;
	len = 0;
	while (rl[++i])
	{
		if (i > 0 && rl[i - 1] == '$' && ft_special(rl[i]) == 1)
		{
			++len;
			i = i + 1;
		}
		else if (i > 0 && rl[i - 1] == '$' && ft_special(rl[i]) == 4)
		{
			q = rl[i];
			while (rl[++i] != q)
				;
			++len;
		}
		else if (i > 0 && rl[i - 1] == '$' && !ft_isspace(rl[i])
			&& !ft_isquotes(rl[i]))
			++len;
	}
	return (len);
}
