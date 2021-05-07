/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 10:55:49 by daypark           #+#    #+#             */
/*   Updated: 2021/01/26 21:25:18 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_size;

	n_size = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len >= n_size)
	{
		if (*haystack == *needle && (ft_memcmp(haystack, needle, n_size) == 0))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
