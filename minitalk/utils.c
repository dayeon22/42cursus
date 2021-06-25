/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:32:42 by daypark           #+#    #+#             */
/*   Updated: 2021/06/21 17:20:33 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		get_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	put_str(char *str)
{
	write(1, str, get_len(str));
}

char	*ft_itoa(int n)
{
	int		size;
	int		temp;
	char	*res;

	size = 1;
	if (n < 0)
		size++;
	temp = n;
	while (temp /= 10)
		size++;
	if (!(res = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		res[0] = '-';
	}
	if (n == 0)
		res[0] = '0';
	while (n)
	{
		res[--size] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}
