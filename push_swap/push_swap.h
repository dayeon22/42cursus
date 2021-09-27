/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:48:55 by daypark           #+#    #+#             */
/*   Updated: 2021/09/26 18:10:45 by daypark          ###   ########.fr       */
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

#endif
