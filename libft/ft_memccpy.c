/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 19:07:35 by daypark           #+#    #+#             */
/*   Updated: 2021/01/16 13:06:13 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n--)
	{
		*((unsigned char *)dst) = *((unsigned char *)src);
		dst++;
		if (*((unsigned char *)src) == (unsigned char)c)
			return (dst);
		src++;
	}
	return (NULL);
}
