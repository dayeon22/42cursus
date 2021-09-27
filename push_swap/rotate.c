/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:38:37 by daypark           #+#    #+#             */
/*   Updated: 2021/09/27 15:45:04 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	t_node	*temp;

	if (a->size <= 1)
		return ;
	temp = a->top->next;
	temp->pre = NULL;
	a->top->pre = a->bottom;
	a->top->next = NULL;
	a->bottom->next = a->top;
	a->bottom = a->top;
	a->top = temp;
}


void	rb(t_stack *b)
{
	ra(b);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b); //ra(b)가 더 효율적일듯?
}
