/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 20:00:01 by daypark           #+#    #+#             */
/*   Updated: 2021/05/29 19:39:09 by daypark          ###   ########.fr       */
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

static void	set(int *size, int *sign, int *n)
{
	if (*n <= 0)
	{
		*size = 1;
		if (*n == 0)
			*sign = 1;
		else
		{
			*sign = -1;
			*n = -(*n);
		}
	}
	else
	{
		*size = 0;
		*sign = 1;
	}
}

char		*ft_itoa(int n)
{
	int		size;
	int		sign;
	char	*res;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	set(&size, &sign, &n);
	size += get_size(n);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
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
