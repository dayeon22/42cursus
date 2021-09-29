/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:46:55 by daypark           #+#    #+#             */
/*   Updated: 2021/09/29 15:12:43 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b, int type)
{
	int	num;

	if (type == A)
		ft_putendl_fd("pa", 1);
	else
		ft_putendl_fd("pb", 1);
	if (b->top == NULL)
		return ;
	num = pop(b);
	push_top(a, num);
}

void	pb(t_stack *a, t_stack *b, int type)
{
	pa(b, a, type);
}
