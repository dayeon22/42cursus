/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 20:00:01 by daypark           #+#    #+#             */
/*   Updated: 2021/01/30 04:25:09 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int n)
{
	int		size;

	size = 0;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	int		size;
	int		sign;
	char	*res;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = (n <= 0) ? 1 : 0;
	sign = (n < 0) ? -1 : 1;
	n = (n < 0) ? -n : n;
	size += get_size(n);
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	res[size--] = 0;
	while (size >= 0)
	{
		res[size--] = '0' + n % 10;
		n /= 10;
	}
	if (sign == -1)
		res[0] = '-';
	return (res);
}
