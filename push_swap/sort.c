/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:10:10 by daypark           #+#    #+#             */
/*   Updated: 2021/10/04 16:06:47 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	a_size;

	a_size = a->size;
	set_digit(a);
	i = -1;
	while (++i < a->digit)
	{
		if (!sort_check(a))
			return ;
		j = -1;
		while (++j < a_size)
		{
			if (((a->top->value >> i) & 0b1) == 0)
				pb(a, b, B);
			else
				ra(a, A);
		}
		while (b->size > 0)
			pa(a, b, A);
	}
	sort_negative(a, b);
}

void	sort_negative(t_stack *a, t_stack *b)
{
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

void	set_digit(t_stack *a)
{
	if (a->min == -2147283648)
	{
		a->digit = 32;
		return ;
	}
	if (a->min < 0 || a->max < 0)
		a->digit++;
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
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->bottom->value;
	if (!sort_check(a))
		return ;
	if (first > second && second < third && third > first)
		sa(a, A);
	else if (first > second && second < third && third < first)
		ra(a, A);
	else if (first < second && second > third && third < first)
		rra(a, A);
	else if (first > second && second > third && third < first)
	{
		sa(a, A);
		rra(a, A);
	}
	else if (first < second && second > third && third > first)
	{
		sa(a, A);
		ra(a, A);
	}
}

void	sort_five(t_stack *a, t_stack *b)
{
	if (!sort_check(a))
		return ;
	while (a->size > 3)
	{
		if (a->top->value == a->max || a->top->value == a->min)
			pb(a, b, B);
		else
			ra(a, A);
	}
	sort_three(a);
	if (b->top->value > b->bottom->value)
		sb(b, B);
	pa(a, b, A);
	pa(a, b, A);
	ra(a, A);
}
