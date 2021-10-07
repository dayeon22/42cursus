/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:48:46 by daypark           #+#    #+#             */
/*   Updated: 2021/10/04 16:18:37 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	int		i;

	init_stack(&a);
	init_stack(&b);
	if (argc == 1)
		return (0);
	i = 0;
	while (argv[++i])
	{
		if (!ft_strcmp(argv[i], "") || is_all_space(argv[i]))
			print_error(&a);
		if (ft_strchr(argv[i], ' '))
			remove_space(&a, argv[i]);
		else
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
