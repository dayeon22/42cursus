#include "../include/minishell.h"

static int	check_redir_order(t_split *sp)
{
	while (sp)
	{
		if (sp->type == CHAR_LESS || sp->type == CHAR_DLESS
			|| sp->type == CHAR_GREAT || sp->type == CHAR_DGREAT)
		{
			if (!sp->next)
				return (0);
			else if (sp->type != CHAR_WORD)
				return (0);
		}
		sp = sp->next;
	}
	return (1);
}

static int	check_pipe_order(t_split *sp)
{
	if (sp->type == CHAR_PIPE)
		return (0);
	while (sp)
	{
		if (sp->type == CHAR_PIPE)
		{
			if (!sp->next)
				return (0);
			else if (sp->next->type == CHAR_PIPE)
				return (0);
		}
		sp = sp->next;
	}
	return (1);
}

int	check_list(t_split *sp)
{
	if (!sp)
		return (0);
	if (!check_pipe_order(sp))
		return (error_printf("pipeline order error", 127));
	if (!check_redir_order(sp))
		return (error_printf("redir order error", 127));
	return (1);
}
