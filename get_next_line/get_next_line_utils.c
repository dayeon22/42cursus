/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:02:21 by daypark           #+#    #+#             */
/*   Updated: 2021/02/27 20:25:56 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	res[i] = 0;
	return (res);
}

char	*ft_strncpy(char *dst, char *src, int n)
{
	int		i;

	if (!dst)
		return (NULL);
	i = -1;
	while (++i < n)
		dst[i] = src[i];
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		len1;
	int		len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(ret = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (0);
	ft_strncpy(ret, s1, len1);
	ft_strncpy(ret + len1, s2, len2);
	ret[len1 + len2] = 0;
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
