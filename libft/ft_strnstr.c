/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 10:55:49 by daypark           #+#    #+#             */
/*   Updated: 2021/01/24 21:18:06 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h_size;
	size_t	n_size;
	size_t	i;
	size_t	j;

	h_size = ft_strlen(haystack);
	n_size = ft_strlen(needle);
	if (needle[0] == 0)
		return ((char *)haystack);
	else if (h_size < n_size)
		return (NULL);
	i = 0;
	while (haystack[i] && i + 1 < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			j++;
			if (needle[j] == 0)
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

#include <stdio.h>
#include <string.h>

int		main(void)
{
	char	*big = "123456789";
	char	*little = "9";
	size_t	max = 8;

	char	*i1 = strnstr(big, little, max);
	char	*i2 = ft_strnstr(big, little, max);

	if (i1 != i2)
		printf("wrong");
	else
		printf("correct");
}
