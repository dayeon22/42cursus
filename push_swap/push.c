/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:46:55 by daypark           #+#    #+#             */
/*   Updated: 2021/09/27 14:32:39 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	int	num;

	if (b->top == NULL)
		return ;
	num = pop(b);
	push_top(a, num);
}

void	pb(t_stack *a, t_stack *b)
{
	pa(b, a);
}
