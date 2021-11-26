#include "../include/minishell.h"

static int	str_split_init(char *rl, int point, int *i, t_split *sp)
{
	char	*cut;

	cut = ft_substr(rl, point, (*i - point));
	if (!cut)
		return (error_printf(sp->e, "malloc error", 127));
	sp->str = ft_split(cut, 32);
	if (!sp->str)
	{
		free(cut);
		return (error_printf(sp->e, "malloc error", 127));
	}
	free(cut);
	sp->type = CHAR_WORD;
	return (1);
}

static int	str_split_check(char *rl, int *i, t_split *sp, int *size)
{
	while (rl[*i] && rl[*i] != '|' && rl[*i] != '<' && rl[*i] != '>')
	{
		if (rl[*i] == '\\' || rl[*i] == ';')
			return (error_printf(sp->e, "backslash or semicolon error", 127));
		else if (rl[*i] == '\"' || rl[*i] == '\'')
			if (!quotes_check(rl, i, sp, size))
				return (0);
		(*i)++;
		if (*i > 0 && rl[*i - 1] == '$' && rl[*i] == '$')
		{
			if (!sp_special_dollar(sp, rl, i, *size))
				return (error_printf(sp->e, "malloc error", 127));
			sp->quotes[(*size)++] = '0';
		}
		if (*i > 0 && rl[*i - 1] == '$' && !ft_isspace(rl[*i])
			&& !ft_isquotes(rl[*i]))
		{
			if (!sp_dollar_count(sp, rl, *i, *size))
				return (error_printf(sp->e, "malloc error", 127));
			sp->quotes[(*size)++] = '0';
		}
	}
	return (1);
}

static int	word_input(char *rl, int *i, t_split *sp, int *num)
{
	int	point;
	int	size;
	int	len;

	point = *i;
	size = 0;
	len = dollar_count(rl);
	sp->quotes = (char *)ft_calloc(sizeof(char), len + 1);
	sp->dollar = (char **)malloc(sizeof(char *) * (len + 1));
	sp->c_vlaue = (char **)malloc(sizeof(char *) * (len + 1));
	sp->c_len = len;
	if (!sp->quotes || !sp->dollar || !sp->c_vlaue)
		return (error_printf(sp->e, "malloc error", 1));
	while (len > -1)
	{
		sp->dollar[len] = 0;
		sp->c_vlaue[len] = 0;
		--len;
	}
	if (!str_split_check(rl, i, sp, &size))
		return (0);
	if (!str_split_init(rl, point, i, sp))
		return (0);
	sp->num = *num;
	return (1);
}

static int	redir_check(char *rl, int *i, t_split *sp, int *num)
{
	if (rl[*i] == '|' && (*i)++)
		sp->type = CHAR_PIPE;
	else if (rl[*i] == '<' && rl[*i + 1] == '<' && (*i)++ && (*i)++)
		sp->type = CHAR_DLESS;
	else if (rl[*i] == '<' && (*i)++)
		sp->type = CHAR_LESS;
	else if (rl[*i] == '>' && rl[*i + 1] == '>' && (*i)++ && (*i)++)
		sp->type = CHAR_DGREAT;
	else if (rl[*i] == '>' && (*i)++)
		sp->type = CHAR_GREAT;
	else
		if (!word_input(rl, i, sp, num))
			return (0);
	return (1);
}

t_split	*split_read_line(char *rl, t_split *sp, t_env *env)
{
	int		i;
	int		num;
	t_split	*tmp;
	t_int	c_int;

	i = 0;
	num = 1;
	if (!rl || !rl[space_clear(rl, &i)])
		return (0);
	sp = sp_new_init(env, &c_int);
	tmp = sp;
	if (!sp)
		return (0);
	while (rl[i])
	{
		if (!rl[space_clear(rl, &i)])
			return (sp);
		if (!redir_check(rl, &i, tmp, &num) && num++)
			return (0);
		if (rl[i])
			sp_add_back(&tmp, sp_new_init(env, &c_int));
		if (tmp->next != NULL)
			tmp = tmp->next;
	}
	return (sp);
}
