/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:48:46 by daypark           #+#    #+#             */
/*   Updated: 2021/09/30 23:56:08 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_bottom(t_stack *stack, int num)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node)); //실패시
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
	stack->min = 0;
	stack->max = 0;
	stack->digit = 0;
	stack->top = NULL;
	stack->bottom = NULL;
}

int	check_duplication(t_stack *stack, int num)
{
	t_node	*node;

	if (num > stack->max)
		stack->max = num;
	if (num < stack->min)
		stack->min = num;
	node = stack->top;
	while (node != NULL)
	{
		if (node->value == num)
			return (1);
		node = node->next;
	}
	return (0);
}

int	remove_space(t_stack *stack, char *str)
{
	int		i;
	int		num;
	char	**words;

	words = ft_split(str, ' ');
	i = 0;
	while (words[i])
	{
		num = ft_atoi(words[i]);
		if (check_duplication(stack, num))
			print_error();
		else
			push_bottom(stack, num);
		i++;
	}
	return (0);
}

void	print_error()
{
	ft_putendl_fd("Error", 2);
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

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	int		i;
	int		num;

	if (argc == 1)
		print_error();
	init_stack(&a);
	init_stack(&b);
	i = 0;
	while (argv[++i])
	{
		if (ft_strchr(argv[i], ' '))
		{
			remove_space(&a, argv[i]);
			continue ;
		}
		//아래 코드를 check_duplication()에 넣어버리기
		num = ft_atoi(argv[i]);
		if (check_duplication(&a, num))
			print_error();
		else
			push_bottom(&a, num);
	}
	if (a.size == 3)
		sort_three(&a);
	else if (a.size == 5)
		sort_five(&a, &b);
	else
		radix_sort(&a, &b);

	print_stack(&a);
}
