/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 06:09:33 by daypark           #+#    #+#             */
/*   Updated: 2021/01/16 13:06:51 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s1, int c, size_t n)
{
	unsigned char *s;

	s = (unsigned char *)s1;
	while (n--)
	{
		if (*s == (unsigned char)c)
			return (s);
		s++;
	}
	return (NULL);
}
