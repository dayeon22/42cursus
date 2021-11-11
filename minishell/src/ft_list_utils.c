#include "../include/minishell.h"

t_split	*sp_new_init(void)
{
	t_split	*new;

	new = malloc(sizeof(t_split) * 1);
	if (!new)
		return (NULL);
	new->str = NULL;
	new->type = 0;
	new->quotes = -99;
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
