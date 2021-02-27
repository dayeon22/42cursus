/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:06:57 by daypark           #+#    #+#             */
/*   Updated: 2021/02/27 04:53:15 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = 0;
	return (res);
}
/*
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(res = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_strlen(s1))
	{
		res[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
		res[i++] = s2[j++];
	res[i] = 0;
	return (res);
}
*/
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

//추가한것 여기서부터
char *ft_strncpy(char *dst, char *src, int n)
{
	int	i;
	
	if (dst == 0)
		return (NULL);
	i = -1;
	while (++i < n)
		dst[i] = src[i];
	return (dst);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *s_new;
	int len1;
	int len2;

	if (s1 == 0 && s2 == 0)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s_new = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (s_new == 0)
		return (0);
	ft_strncpy(s_new, s1, len1);
	ft_strncpy(s_new + len1, s2, len2);
	s_new[len1 + len2] = 0;
	return (s_new);
}
//여기까지
