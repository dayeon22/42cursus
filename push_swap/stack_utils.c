/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:54:03 by daypark           #+#    #+#             */
/*   Updated: 2021/10/04 15:54:14 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_bottom(t_stack *stack, int num)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		print_error(stack);
	new->value = num;
	if (stack->size == 0)
	{
		new->pre = NULL;
		new->next = NULL;
		stack->top = new;
		stack->bottom = new;
		stack->min = num;
		stack->max = num;
	}
	else
	{
		new->pre = stack->bottom;
		new->next = NULL;
		stack->bottom->next = new;
		stack->bottom = new;
	}
	stack->size++;
}

void	push_top(t_stack *stack, int num)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		print_error(stack);
	new->value = num;
	if (stack->size == 0)
	{
		new->pre = NULL;
		new->next = NULL;
		stack->top = new;
		stack->bottom = new;
	}
	else
	{
		new->pre = NULL;
		new->next = stack->top;
		stack->top->pre = new;
		stack->top = new;
	}
	stack->size++;
}

int	pop(t_stack *stack)
{
	int		ret;
	t_node	*temp;

	ret = stack->top->value;
	temp = stack->top;
	stack->top = stack->top->next;
	free(temp);
	stack->size--;
	return (ret);
}

void	init_stack(t_stack *stack)
{
	stack->size = 0;
	stack->min = 0;
	stack->max = 0;
	stack->digit = 0;
	stack->top = NULL;
	stack->bottom = NULL;
}

int	sort_check(t_stack *stack)
{
	t_node	*temp;

	temp = stack->top;
	while (temp && temp->next)
	{
		if (temp->value > temp->next->value)
			return (1);
		temp = temp->next;
	}
	return (0);
}
