/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:48:46 by daypark           #+#    #+#             */
/*   Updated: 2021/09/27 15:47:35 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_bottom(t_stack *stack, int num)
{
	t_node *new;

	new = (t_node *)malloc(sizeof(t_node)); //실패시
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
		new->pre = stack->bottom;
		new->next = NULL;
		stack->bottom->next = new;
		stack->bottom = new;
	}
	stack->size++;
}

void	push_top(t_stack *stack, int num)
{
	t_node *new;

	new = (t_node *)malloc(sizeof(t_node)); //실패시
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

void	print_stack(t_stack *stack) //작동 확인용 코드
{
	t_node	*temp;

	temp = stack->top;
	while (temp != NULL)
	{
		printf("%d -> ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}

void	init_stack(t_stack *stack)
{
	stack->size = 0;
	stack->top = NULL;
	stack->bottom = NULL;
}

int	main()
{
	t_stack	a;
	t_stack	b;

	init_stack(&a);
	init_stack(&b);
	push_bottom(&a, 1);
	push_bottom(&a, 2);
	push_bottom(&a, 3);
	push_bottom(&a, 4);
	push_bottom(&a, 5);
	print_stack(&a);

/*	
	rra(&a);
	print_stack(&a);
	rra(&a);
	print_stack(&a);
	rra(&a);
	print_stack(&a);
	printf("%d %d\n", a.top->value, a.bottom->value);
	rra(&a);
	print_stack(&a);
	rra(&a);
	print_stack(&a);
*/

	pb(&a, &b);
	pb(&a, &b);
	print_stack(&b);
	rrb(&b);
	printf("%d %d\n", b.top->value, b.bottom->value);
	print_stack(&b);
	rrb(&b);
	printf("%d %d\n", b.top->value, b.bottom->value);
	print_stack(&b);

	printf("stack a : ");
	print_stack(&a);
	printf("stack b : ");
	print_stack(&b);
	printf("top : %d\n", a.top->value);
	printf("bottom : %d\n", a.bottom->value);
	printf("size : %d\n", a.size);
}
