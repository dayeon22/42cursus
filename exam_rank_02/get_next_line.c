/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 10:14:34 by daypark           #+#    #+#             */
/*   Updated: 2021/06/24 03:36:20 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		len1;
	int		len2;
	int		i;
	int		j;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(res = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
		res[i] = s1[i++];
	j = 0;
	while (s2[j])
		res[i++] = s1[j++];
	res[i] = 0;
	return (res);
}

char	*ft_strchr(char *s, int c)
{
	int		i;

	i = -1;
	while (s[++i])
	{
		if ((char)c == s[i])
			return (&s[i]);
	}
	if ((char)c == 0)
		return (&s[i]);
	return (NULL);
}

char	 *ft_strndup(char *s, int n)
{
	int		i;
	char	*res;

	res = (char *)malloc(sizeof(char) * n + 1);
	i = 0;
	while (s[i] && i < n)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

int		get_next_line(char **line)
{

}
