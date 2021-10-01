/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:54:41 by daypark           #+#    #+#             */
/*   Updated: 2021/10/01 17:13:36 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, int type)
{
	t_node	*temp;

	if (type == A)
		ft_putendl_fd("sa", 1);
	else if (type == B)
		ft_putendl_fd("sb", 1);
	else
		ft_putendl_fd("ss", 1);
	if (a->size <= 1)
		return ;
	temp = a->top->next;
	if (a->size >= 3)
		temp->next->pre = a->top;
	a->top->pre = temp;
	a->top->next = temp->next;
	temp->pre = NULL;
	temp->next = a->top;
	a->top = temp;
	if (a->size == 2)
		a->bottom = a->top->next;
}

void	sb(t_stack *b, int type)
{
	sa(b, type);
}

void	ss(t_stack *a, t_stack *b, int type)
{
	sa(a, type);
	sa(b, type);
}
