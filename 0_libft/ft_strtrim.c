/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 07:26:55 by daypark           #+#    #+#             */
/*   Updated: 2021/01/17 07:49:43 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		getfirst(char const *s1, char const *set)
{
	int		i;

	i = 0;
	while (s1[i] && strchr(set, s1[i]))
		i++;
	return (i);
}

int		getlast(char const *s1, char const *set)
{
	int		i;

	i = 0;
	while (s1[i] && strchr(set, s1[ft_strlen(s1) - i - 1]))
		i++;
	return (ft_strlen(s1) - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		first;
	int		last;
	char	*res;

	if (!s1)
		return (NULL);
	if (!set)
		return (strdup(s1));
	first = getfirst(s1, set);
	last = getlast(s1, set);
	if (first >= last)
		return (strdup(""));
	if (!(res = (char *)malloc(sizeof(char) * (last - first + 1))))
		return (NULL);
	strlcpy(res, s1 + start, last - first + 1);
	return (res);
}
