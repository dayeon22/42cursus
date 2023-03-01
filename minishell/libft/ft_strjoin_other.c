/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_other.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@studen.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:48:10 by daypark           #+#    #+#             */
/*   Updated: 2021/12/17 14:14:05 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_other(char const *s1, char const *s2, char const *s3)
{
	size_t	len[3];
	size_t	i;
	char	*res;

	len[0] = ft_strlen(s1);
	len[1] = ft_strlen(s2) + len[0];
	len[2] = ft_strlen(s3) + len[1];
	res = (char *)malloc(sizeof(char) * (len[2] + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < len[0])
		res[i] = s1[i];
	i = 0;
	while (len[0] < len[1])
		res[len[0]++] = s2[i++];
	i = 0;
	while (len[0] < len[2])
		res[len[0]++] = s3[i++];
	res[len[0]] = 0;
	return (res);
}
