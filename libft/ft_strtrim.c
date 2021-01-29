/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 07:26:55 by daypark           #+#    #+#             */
/*   Updated: 2021/01/30 04:10:15 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getfirst(char const *s1, char const *set)
{
	int		i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

static int	getlast(char const *s1, char const *set)
{
	int		i;
	size_t	s1len;

	i = 0;
	s1len = ft_strlen(s1);
	while ((s1len - i - 1) && ft_strchr(set, s1[s1len - i - 1]))
		i++;
	return (ft_strlen(s1) - i);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		first;
	int		last;
	char	*res;
	int		i;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	first = getfirst(s1, set);
	last = getlast(s1, set);
	if (first >= last)
		return (ft_strdup(""));
	if (!(res = (char *)malloc(sizeof(char) * (last - first + 1))))
		return (NULL);
	i = 0;
	ft_strlcpy(res, s1 + first, last - first + 1);
	return (res);
}
