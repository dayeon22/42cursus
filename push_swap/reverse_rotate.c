/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:39:55 by daypark           #+#    #+#             */
/*   Updated: 2021/09/29 15:15:30 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a, int type)
{
	t_node *temp;

	if (type == A)
		ft_putendl_fd("rra", 1);
	else if (type == B)
		ft_putendl_fd("rrb", 1);
	else
		ft_putendl_fd("rrr", 1);
	if (a->size <= 1)
		return ;
	temp = a->bottom->pre;
	temp->next = NULL;
	a->bottom->next = a->top;
	a->bottom->pre = NULL;
	a->top->pre = a->bottom;
	a->top = a->bottom;
	a->bottom = temp;
}

void	rrb(t_stack *b, int type)
{
	rra(b, type);
}

void	rrr(t_stack *a, t_stack *b, int type)
{
	rra(a, type);
	rra(b, type);
}
