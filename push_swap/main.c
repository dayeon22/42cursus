/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:48:46 by daypark           #+#    #+#             */
/*   Updated: 2021/09/28 11:59:35 by daypark          ###   ########.fr       */
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

int	check_duplication(t_stack *stack, int num)
{
	t_node	*node;

	node = stack->top;
	while (node != NULL)
	{
		if (node->value == num)
			return (1);
		node = node->next;
	}
	return (0);
}

int	check_int_range()

int	remove_space(t_stack *stack, char *str)
{
	int	i;
	int	num;
	char **words;

	words = ft_split(str, ' ');
	i = 0;
	while (words[i])
	{
		num = ft_atoi(words[i]);
		if (check_duplication(stack, num))
			return (1); //print_err(DUPLICATED_NUM);
		else
			push_bottom(stack, num);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack a;
	t_stack b;
	int		i;
	int		num;

	if (argc < 3) //2개까지 거르는게 맞나 알아보기
		return (1); //print_err(ARGC);
	init_stack(&a);
	init_stack(&b);

	i = 1;
	while (argv[i])
	{
		if (ft_strchr(argv[i], ' '))
			remove_space(&a, argv[i]);
		num = ft_atoi(argv[i]);
		if (check_duplication(&a, num))
			return (1); //print_err(DUPLICATED_NUM);
		else
			push_bottom(&a, num);
		i++;
	}

	print_stack(&a);
}
