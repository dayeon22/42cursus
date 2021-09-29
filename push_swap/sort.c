/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:10:10 by daypark           #+#    #+#             */
/*   Updated: 2021/09/29 18:55:18 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	a_size;

	i = 0;
	a_size = a->size;
	while (i < a->digit)
	{
		j = 0;
		while (j < a_size)
		{
			if (((a->top->value >> i) & 0b1) == 0)
				pb(a, b, B);
			else
				ra(a, A);
			j++;
		}
		while (b->size > 0)
			pa(a, b, A);
		i++;
	}

	while (a->bottom->value < 0)
	{
		rra(a, A);
		pb(a, b, B);
	}
	while (b->size > 0)
	{
		rrb(b, B);
		pa(a, b, A);
	}
}

void	get_max_digit(t_stack *a)
{
	if (a->min == -2147283648)
	{
		a->digit = 32;
		return ;
	}
	if (a->min < 0)
		a->min *= -1;
	if (a->max < 0)
		a->max *= -1;
	while (a->max > 0 || a->min > 0)
	{
		a->max = a->max >> 1;
		a->min = a->min >> 1;
		a->digit++;
	}
	a->digit++; //음수있을때만 1 더해야 효율적임
}

void	sort_stack(t_stack *a, t_stack *b)
{
	get_max_digit(a);
	radix_sort(a, b);
}
