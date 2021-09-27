/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:39:55 by daypark           #+#    #+#             */
/*   Updated: 2021/09/27 15:44:53 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	t_node *temp;

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

void	rrb(t_stack *b)
{
	rra(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b); //rra(b)가 더 효율적일 듯
}
