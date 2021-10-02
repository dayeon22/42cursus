/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:48:46 by daypark           #+#    #+#             */
/*   Updated: 2021/10/02 00:57:07 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	int		i;

	if (argc == 1)
		print_error(&a);
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
		check_duplication(&a, ft_atoi(argv[i]));
	}
	if (a.size == 3)
		sort_three(&a);
	else if (a.size == 5)
		sort_five(&a, &b);
	else
		radix_sort(&a, &b);
	terminate(&a);
}

void	check_duplication(t_stack *stack, int num)
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
			print_error(stack);
		node = node->next;
	}
	push_bottom(stack, num);
}

void	remove_space(t_stack *stack, char *str)
{
	int		i;
	char	**words;

	words = ft_split(str, ' ');
	i = -1;
	while (words[++i])
		check_duplication(stack, ft_atoi(words[i]));
}

void	print_error(t_stack *stack)
{
	ft_putendl_fd("Error", 2);
	terminate(stack);
}

void	terminate(t_stack *stack)
{
	t_node	*node;
	t_node	*temp;

	node = stack->top;
	while (node)
	{
		temp = node;
		node = node->next;
		free(temp);
	}
	exit(1);
}
