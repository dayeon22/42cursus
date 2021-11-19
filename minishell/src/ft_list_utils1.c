#include "../include/minishell.h"

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
	new->c_len = 0;
	new->t_env = env;
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

t_split	*sp_list_del(t_split *sp)
{
	t_split	*cp;

	cp = sp;
	if (sp->next)
		sp = sp->next;
	if (!cp->next)
	{
		free(cp);
		return (NULL);
	}
	free(cp);
	return (sp);
}

void	sp_list_clear(t_split *sp)
{
	t_split	*cp;

	while (1)
	{
		cp = sp;
		if (sp->next)
			sp = sp->next;
		free_two(cp->str);
		free(cp);
		if (!sp->next)
			break ;
	}
}
