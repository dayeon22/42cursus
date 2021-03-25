/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:12:50 by daypark           #+#    #+#             */
/*   Updated: 2021/03/19 19:15:08 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*add;

	if (!lst || !f)
		return (NULL);
	n_lst = ft_lstnew(f(lst->content));
	if (!n_lst)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		add = ft_lstnew(f(lst->content));
		if (!add)
		{
			ft_lstclear(&n_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&n_lst, add);
		lst = lst->next;
	}
	return (n_lst);
}
