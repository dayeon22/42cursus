/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_code_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:12:23 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/18 17:28:04 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	str_split_init(char *rl, int point, int *i, t_split *sp)
{
	char	*cut;

	cut = ft_substr(rl, point, (*i - point));
	if (!cut)
		return (e_code(sp->e, "cut malloc error", 1));
	sp->str = ft_split_mini(cut, 32);
	if (!sp->str && !free_one_point(cut))
		return (e_code(sp->e, "sp->str malloc error", 1));
	free_one_point(cut);
	sp->type = CHAR_WORD;
	return (0);
}

static int	str_split_check(char *rl, int *i, t_split *sp, int *size)
{
	while (rl[*i] && rl[*i] != '|' && rl[*i] != '<' && rl[*i] != '>')
	{
		if (rl[*i] == '\\' || rl[*i] == ';')
			return (e_code(sp->e, "backslash or semicolon error.", 1));
		else if (rl[*i] == '\"' || rl[*i] == '\'')
			if (quotes_check(rl, i, sp, size))
				return (sp->e->exit_n);
		(*i)++;
		if (rl[*i] && *i > 0 && rl[*i - 1] == '$' \
		&& (ft_special(rl[*i]) == 1 || ft_special(rl[*i]) == 2))
		{
			if (sp_special_dollar(sp, rl, i, *size))
				return (e_code(sp->e, "special malloc error", 1));
			sp->quotes[(*size)++] = '0';
		}
		if (rl[*i] && *i > 0 && rl[*i - 1] == '$' && !ft_isspace(rl[*i])
			&& !ft_isquotes(rl[*i]))
		{
			if (sp_dollar_count(sp, rl, *i, *size))
				return (e_code(sp->e, "dollar count malloc error", 1));
			sp->quotes[(*size)++] = '0';
		}
	}
	return (0);
}

static int	word_input(char *rl, int *i, t_split *sp)
{
	int	point;
	int	size;
	int	len;

	point = *i;
	size = 0;
	len = dollar_count(rl);
	sp->quotes = (char *)malloc(sizeof(char) * (len + 1));
	sp->dollar = (char **)malloc(sizeof(char *) * (len + 1));
	sp->c_vlaue = (char **)malloc(sizeof(char *) * (len + 1));
	sp->c_len = len;
	if (!sp->quotes || !sp->dollar || !sp->c_vlaue)
		return (e_code(sp->e, "word input malloc error", 1));
	sp_null_fill(&sp, len);
	if (str_split_check(rl, i, sp, &size))
		return (1);
	if (str_split_init(rl, point, i, sp))
		return (1);
	return (0);
}

static int	redir_check(char *rl, int *i, t_split *sp)
{
	if (rl[*i] == '|' && ++(*i) > 0)
		sp->type = CHAR_PIPE;
	else if (rl[*i] == '<' && rl[*i + 1] == '<' && ++(*i) > 0 && ++(*i))
		sp->type = CHAR_DLESS;
	else if (rl[*i] == '<' && ++(*i) > 0)
		sp->type = CHAR_LESS;
	else if (rl[*i] == '>' && rl[*i + 1] == '>' && ++(*i) > 0 && ++(*i))
		sp->type = CHAR_DGREAT;
	else if (rl[*i] == '>' && ++(*i) > 0)
		sp->type = CHAR_GREAT;
	else
		if (word_input(rl, i, sp))
			return (1);
	return (0);
}

t_split	*split_read_line(char *rl, t_split *sp, t_env *env)
{
	int		i;
	t_split	*tmp;

	i = 0;
	if (!rl || !rl[space_clear(rl, &i)])
		return (0);
	sp = sp_new_init(env);
	tmp = sp;
	if (!sp)
		return (0);
	while (rl[i])
	{
		if (!rl[space_clear(rl, &i)])
			return (sp);
		if (redir_check(rl, &i, tmp))
		{
			sp_list_clear(&sp);
			return (0);
		}
		if (rl[i])
			sp_add_back(&tmp, sp_new_init(env));
		if (tmp->next != NULL)
			tmp = tmp->next;
	}
	return (sp);
}
