/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:48:55 by daypark           #+#    #+#             */
/*   Updated: 2021/09/27 12:52:07 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	t_node	*top;
	t_node	*bottom;
}				t_stack;

/*
 * main.c
 */
void	push(t_stack *stack, int num);
int		pop(t_stack *stack);
void	print_stack(t_stack *stack);
void	init_stack(t_stack *stack);

/*
 * swap.c
 */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);


#endif
