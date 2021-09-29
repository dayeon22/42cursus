/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:38:37 by daypark           #+#    #+#             */
/*   Updated: 2021/09/29 17:03:44 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, int type)
{
	t_node	*temp;

	if (type == A)
		ft_putendl_fd("ra", 1);
	else if (type == B)
		ft_putendl_fd("rb", 1);
	else
		ft_putendl_fd("rr", 1);
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


void	rb(t_stack *b, int type)
{
	ra(b, type);
}

void	rr(t_stack *a, t_stack *b, int type)
{
	ra(a, type);
	ra(b, type);
}
