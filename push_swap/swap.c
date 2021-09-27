/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:54:41 by daypark           #+#    #+#             */
/*   Updated: 2021/09/27 12:56:20 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	t_node *temp;

	if (a->size <= 1)
		return ;
	temp = a->top->next;
	a->top->pre = temp;
	a->top->next = temp->next;
	temp->pre = NULL;
	temp->next = a->top;
	a->top = temp;
	if (a->size == 2)
		a->bottom = a->top->next;
}

void	sb(t_stack *b)
{
	sa(b);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}
