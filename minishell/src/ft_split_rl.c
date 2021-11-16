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
/*
	int	j;
	j = -1;
	while (sp->str[++j])
		printf("str[%d] : %s\n", j, sp->str[j]);
	j = -1;
	while (sp->quotes[++j])
		printf("%c\n", sp->quotes[j]);
	printf("=============\n");
*/
	free(cut);
	sp->type = CHAR_WORD;
	return (1);
}

static int	word_input(char *rl, int *i, t_split *sp, int size)
{
	int	point;

	point = *i;
	sp->quotes = (char *)ft_calloc(sizeof(char), doallr_count(rl) + 1);
	if (!sp->quotes)
		return (error_printf("malloc error", 1));
	while (rl[*i] && rl[*i] != '|' && rl[*i] != '<' && rl[*i] != '>')
	{
		if (rl[*i] == '\\' || rl[*i] == ';')
			return (error_printf("backslash or semicolon error", 127));
		else if (rl[*i] == '\"' || rl[*i] == '\'')
			if (!quotes_check(rl, i, sp, &size))
				return (0);
		(*i)++;
		if (*i > 0 && rl[*i - 1] == '$' && !ft_isspace(rl[*i]))
			sp->quotes[size++] = '0';
	}
	if (!str_split_init(rl, point, i, sp))
		return (0);
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
		if (!word_input(rl, i, sp, 0))
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
	if (!rl[space_clear(rl, &i)])
		return (0);
	sp = sp_new_init();
	tmp = sp;
	if (!sp)
		return (0);
	while (rl[i])
	{
		if (!rl[space_clear(rl, &i)])
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
