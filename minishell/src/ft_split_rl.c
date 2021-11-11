#include "../include/minishell.h"

static int	str_split_init(char *rl, int point, int *i, t_split *sp)
{
	char	*cut;

	cut = ft_substr(rl, point, (*i - point));
	if (!cut)
		return (error_printf("malloc error", 127));
	sp->str = ft_split(cut, 32);
	if (!sp->str)
	{
		free(cut);
		return (error_printf("malloc error", 127));
	}
	free(cut);
	return (1);
}

static int	quotes_check(char *rl, int *i, t_split *sp)
{
	char	quote;

	quote = rl[*i];
	(*i)++;
	while (rl[*i])
	{
		if (rl[*i] == quote)
		{
			sp->quotes = quote;
			return (1);
		}
		(*i)++;
	}
	return (error_printf("There is only one quote error.", 127));
}

static int	word_input(char *rl, int *i, t_split *sp)
{
	int		point;

	point = *i;
	while (rl[*i])
	{
		if (rl[*i] == '|' || rl[*i] == '<' || rl[*i] == '>')
			break ;
		else if (rl[*i] == '\\' || rl[*i] == ';')
			return (error_printf("backslash or semicolon error", 127));
		if (rl[*i] == '\"' || rl[*i] == '\'')
			if (!quotes_check(rl, i, sp))
				return (0);
		(*i)++;
	}
	if (!str_split_init(rl, point, i, sp))
		return (0);
	sp->type = CHAR_WORD;
	return (1);
}

static int	redir_check(char *rl, int *i, t_split *sp)
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
		if (!word_input(rl, i, sp))
			return (0);
	return (1);
}

t_split	*split_read_line(char *rl, t_split *sp)
{
	int		i;
	t_split	*tmp;

	i = 0;
	if (!rl)
		return (0);
	sp = sp_new_init();
	tmp = sp;
	if (!sp)
		return (0);
	while (rl[i])
	{
		while (ft_isspace(rl[i]))
			++i;
		if (!rl[i])
			return (sp);
		if (!redir_check(rl, &i, tmp))
			return (0);
		if (rl[i])
			sp_add_back(&tmp, sp_new_init());
		if (tmp->next != NULL)
			tmp = tmp->next;
	}
	return (sp);
}
