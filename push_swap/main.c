/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:48:46 by daypark           #+#    #+#             */
/*   Updated: 2021/09/25 23:58:01 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_data **data, int num)
{
	t_data	*lst;
	t_data	new;

	lst = *data;
	if (lst == NULL)
	{
		new.value = num;
		new.pre = NULL;
		new.next = NULL;
		*data = &new;
		return ;
	}
	lst = *data;
	lst->pre = &new;
	new.value = num;
	new.pre = NULL;
	new.next = lst;
}

void	print_values(t_data **data)
{
	t_data	*temp;

	temp = *data;
	printf("%d", temp->value);
//	while (temp != NULL)
//	{
//		printf("%d -> ", temp->value);
//		temp = temp->next;
//	}
}

int	main()
{
	t_data *a;

	a = NULL;
	push(&a, 1);
	push(&a, 2);
	push(&a, 3);
	push(&a, 4);
	push(&a, 5);
	print_values(&a);
}
