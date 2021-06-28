/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:32:42 by daypark           #+#    #+#             */
/*   Updated: 2021/06/28 18:01:31 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0 || !s)
		return ;
	write(fd, s, ft_strlen(s));
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

int		ft_atoi(char *s)
{
	int		result;
	int		sign;
	int		i;

	result = 0;
	i = 0;
	sign = 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || \
			s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
		i++;
	if (s[i] == '-' || s[i] == '+')
		sign = (s[i] == '-') ? -1 : 1;
	while (s[i])
	{
		if (!('0' <= s[i] && s[i] <= '9'))
			return (sign * result);
		else
			result = result * 10 + s[i++] - '0';
	}
	return (result * sign);
}
