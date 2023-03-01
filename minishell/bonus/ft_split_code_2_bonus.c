/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_code_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:12:26 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/17 14:12:27 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	sp_list_size(t_split *sp)
{
	int		cnt;

	cnt = 0;
	while (sp)
	{
		sp = sp->next;
		cnt++;
	}
	return (cnt);
}

t_split	*sp_new_init(t_env *env)
{
	t_split	*new;

	new = malloc(sizeof(t_split) * 1);
	if (!new)
		return (NULL);
	new->str = NULL;
	new->type = 0;
	new->quotes = 0;
	new->dollar = 0;
	new->c_vlaue = 0;
	new->c_len = 0;
	new->e = env;
	new->next = NULL;
	return (new);
}

void	sp_add_back(t_split **sp, t_split *new)
{
	t_split	*back;

	if (!sp || !new)
		return ;
	back = *sp;
	if (!back)
	{
		*sp = new;
		return ;
	}
	while (back)
	{
		if (back->next == NULL)
			break ;
		back = back->next;
	}
	back->next = new;
	return ;
}

void	sp_list_clear(t_split **sp)
{
	t_split	*cp;

	while (*sp)
	{
		free_two_point((*sp)->str);
		(*sp)->str = 0;
		free_one_point((*sp)->quotes);
		(*sp)->quotes = 0;
		free_two_point((*sp)->dollar);
		(*sp)->dollar = 0;
		free_two_point((*sp)->c_vlaue);
		(*sp)->c_vlaue = 0;
		cp = *sp;
		if (!(*sp)->next)
		{
			free(cp);
			cp = 0;
			break ;
		}
		(*sp) = (*sp)->next;
		free(cp);
		cp = 0;
	}
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
			if (sp_dollar_count(sp, rl, *i, *size))
				return (e_code(sp->e, "dollar count malloc error", 1));
			sp->quotes[(*size)++] = quote;
		}
		if (rl[*i] == quote)
			return (0);
		(*i)++;
	}
	return (e_code(sp->e, "There is only one quote error.", 1));
}
