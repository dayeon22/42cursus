/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:08:24 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/18 10:21:34 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	check_redir_order(t_split *sp)
{
	while (sp)
	{
		if (sp->type == CHAR_LESS || sp->type == CHAR_DLESS
			|| sp->type == CHAR_GREAT || sp->type == CHAR_DGREAT)
		{
			if (!sp->next)
				return (1);
			else if (sp->next->type != CHAR_WORD)
				return (1);
		}
		sp = sp->next;
	}
	return (0);
}

static int	check_pipe_order(t_split *sp)
{
	while (sp)
	{
		if (sp->type == CHAR_PIPE)
		{
			if (!sp->next)
				return (1);
			else if (sp->next->type != CHAR_WORD)
				return (1);
		}
		sp = sp->next;
	}
	return (0);
}

int	check_list(t_split *sp)
{
	if (!sp)
		return (e_code(sp->e, "split sp no date", 1));
	if (check_pipe_order(sp))
		return (e_code(sp->e, "pipeline order error", 258));
	if (check_redir_order(sp))
		return (e_code(sp->e, "redir order error", 258));
	return (0);
}
