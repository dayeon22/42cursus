/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:12:53 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/17 14:12:55 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	sp_null_fill(t_split **sp, int len)
{
	int	i;

	i = -1;
	while (++i <= len)
	{
		(*sp)->quotes[i] = 0;
		(*sp)->dollar[i] = 0;
		(*sp)->c_vlaue[i] = 0;
	}
}

void	one_point_null_fill(char **str, int size)
{
	int	i;

	i = -1;
	while (++i <= size)
		(*str)[i] = 0;
}

int	sp_type_check(t_split *sp)
{
	while (sp)
	{
		if (sp->type == CHAR_LESS || sp->type == CHAR_DLESS)
			return (1);
		else if (sp->type == CHAR_GREAT || sp->type == CHAR_DGREAT)
			return (2);
		if (!sp->next)
			break ;
		sp = sp->next;
	}
	return (0);
}

int	type_check_int(int type)
{
	if (type == CHAR_LESS)
		return (1);
	else if (type == CHAR_GREAT || type == CHAR_DGREAT)
		return (2);
	else if (type == CHAR_PIPE)
		return (3);
	else if (type == CHAR_DLESS)
		return (4);
	else if (type == 0)
		return (5);
	return (0);
}

int	sp_type_int(t_split *sp, int type)
{
	int	i;

	i = 0;
	while (sp)
	{
		++i;
		if (sp->type == type)
			return (i);
		if (sp->type == CHAR_PIPE)
			return (i + 2);
		if (!sp->next)
			break ;
		sp = sp->next;
	}
	return (i + 1);
}
