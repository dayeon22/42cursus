/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:11:42 by daypark           #+#    #+#             */
/*   Updated: 2021/03/19 19:25:39 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		size;
	char	*res;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	res[size--] = 0;
	while (size >= 0)
	{
		res[size] = f(size, s[size]);
		size--;
	}
	return (res);
}
