/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 13:55:11 by daypark           #+#    #+#             */
/*   Updated: 2021/11/19 15:00:11 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	/*
	char *cp_str;

	cp_str = (char *)b;
	while (len-- > 0)
		*cp_str++ = (char)c;
	return (b);
	// unsigned char	*tmp;

	// tmp = (unsigned char *)b;
	// while (len--)
	// 	*((unsigned char *)tmp++) = c;
	// return (b);
*/
	unsigned char	*ptr;
	ptr = b;
	while (len-- > 0)
		*ptr++ = c;
	return (b);
}
