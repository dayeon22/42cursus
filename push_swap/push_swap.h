/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:48:55 by daypark           #+#    #+#             */
/*   Updated: 2021/09/29 18:53:45 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define A 1
# define B 2
# define ALL 3

#include "./libft/libft.h"
#include <stdio.h> //지우기

typedef struct	s_node
{
	int				value;
	struct s_node	*pre;
	struct s_node	*next;
}				t_node;

typedef struct	s_stack
{
	int		size;
	int		min;
	int		max;
	int		digit;
//	int		negative_count;
	t_node	*top;
	t_node	*bottom;
}				t_stack;

/*
 * main.c
 */
void	push_top(t_stack *stack, int num);
void	push_bottom(t_stack *stack, int num);
int		pop(t_stack *stack);
void	print_stack(t_stack *stack);
void	init_stack(t_stack *stack);
int		check_duplication(t_stack *stack, int num);
int		remove_space(t_stack *stack, char *str);

/*
 * sort.c
 */
void	radix_sort(t_stack *a, t_stack *b);
void	get_max_digit(t_stack *a);
void	sort_stack(t_stack *a, t_stack *b);

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
