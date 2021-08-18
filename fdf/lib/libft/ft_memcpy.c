/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:57:14 by daypark           #+#    #+#             */
/*   Updated: 2021/01/24 17:09:46 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp;

	if (!dst && !src)
		return (NULL);
	tmp = dst;
	while (n--)
		*((unsigned char *)tmp++) = *((unsigned char *)src++);
	return (dst);
}
