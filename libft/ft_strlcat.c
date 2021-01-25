/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 13:37:02 by daypark           #+#    #+#             */
/*   Updated: 2021/01/16 13:37:07 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dstlength;

	i = ft_strlen(dst);
	j = 0;
	dstlength = ft_strlen(dst);
	if (dstsize < ft_strlen(dst) + 1)
		return (ft_strlen(src) + dstsize);
	while (src[j] && i < dstsize - 1)
		dst[i++] = src[j++];
	dst[i] = 0;
	return (ft_strlen(src) + dstlength);
}
