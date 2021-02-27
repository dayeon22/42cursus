/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 00:31:22 by daypark           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/01/30 14:13:21 by daypark          ###   ########.fr       */
=======
/*   Updated: 2021/02/06 02:22:30 by daypark          ###   ########.fr       */
>>>>>>> 7ef87be1ee610270fe2b6aecbe0e715f2d7089ef
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		cnt;

	cnt = 0;
	while (lst)
	{
		lst = lst->next;
		cnt++;
	}
	return (cnt);
}
