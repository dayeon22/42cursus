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

int	sp_word_size(t_split *sp)
{
	int		cnt;

	cnt = 0;
	while (sp)
	{
		sp = sp->next;
        if (sp->type == CHAR_WORD)
		    cnt++;
	}
	return (cnt);
}