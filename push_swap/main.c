/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:48:46 by daypark           #+#    #+#             */
/*   Updated: 2021/09/27 12:57:37 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, int num)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	node->value = num;
	if (stack->size == 0)
	{
		node->pre = NULL;
		node->next = NULL;
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		node->pre = stack->bottom;
		node->next = NULL;
		stack->bottom->next = node;
		stack->bottom = node;
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
	t_stack a;

	init_stack(&a);
	push(&a, 1);
	push(&a, 2);
	push(&a, 3);
	push(&a, 4);
	push(&a, 5);
	print_stack(&a);
	printf("pop : %d\n", pop(&a));
	printf("pop : %d\n", pop(&a));
	pop(&a);
	print_stack(&a);
	sa(&a);
	print_stack(&a);
	printf("top : %d\n", a.top->value);
	printf("bottom : %d\n", a.bottom->value);
	printf("size : %d\n", a.size);
}
