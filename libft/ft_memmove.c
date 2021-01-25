/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 05:14:31 by daypark           #+#    #+#             */
/*   Updated: 2021/01/24 17:09:00 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp;
	unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		tmp = (unsigned char *)dst;
		s = (unsigned char *)src;
		while (len--)
			*tmp++ = *s++;
	}
	else
	{
		tmp = (unsigned char *)dst + len - 1;
		s = (unsigned char *)src + len - 1;
		while (len--)
			*tmp-- = *s--;
	}
	return (dst);
}
