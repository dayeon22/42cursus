/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:48:55 by daypark           #+#    #+#             */
/*   Updated: 2021/10/01 23:36:35 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define A 1
# define B 2
# define ALL 3

# include "./libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*pre;
	struct s_node	*next;
}				t_node;

typedef struct s_stack
{
	int		size;
	int		min;
	int		max;
	int		digit;
	t_node	*top;
	t_node	*bottom;
}				t_stack;

/*
 * main.c
 */
void	check_duplication(t_stack *stack, int num);
void	remove_space(t_stack *stack, char *str);
void	print_error(t_stack *stack);
void	terminate(t_stack *stack);

/*
 * utils.c
 */
void	push_bottom(t_stack *stack, int num);
void	push_top(t_stack *stack, int num);
int		pop(t_stack *stack);
void	init_stack(t_stack *stack);
int		sort_check(t_stack *stack);

/*
 * sort.c
 */
void	radix_sort(t_stack *a, t_stack *b);
void	set_digit(t_stack *a);
void	sort_negative(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);

/*
 * swap.c
 */
void	sa(t_stack *a, int type);
void	sb(t_stack *b, int type);
void	ss(t_stack *a, t_stack *b, int type);

/*
 * push.c
 */
void	pa(t_stack *a, t_stack *b, int type);
void	pb(t_stack *a, t_stack *b, int type);

/*
 * rotate.c
 */
void	ra(t_stack *a, int type);
void	rb(t_stack *b, int type);
void	rr(t_stack *a, t_stack *b, int type);

/*
 * reverse_rotate.c
 */
void	rra(t_stack *a, int type);
void	rrb(t_stack *b, int type);
void	rrr(t_stack *a, t_stack *b, int type);

#endif
