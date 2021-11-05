/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 05:28:13 by daypark           #+#    #+#             */
/*   Updated: 2021/03/21 13:13:49 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_over_range(unsigned long long result, int sign)
{
	if (result > LLONG_MAX - 1 && sign == -1)
		return (0);
	if (result > LLONG_MAX && sign == 1)
		return (-1);
	return (result * sign);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	result;

	i = 0;
	result = 0;
	sign = 1;
	if (!(ft_strncmp(str, "-2147483648", 12)))
		return (-2147483648);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || \
			str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (sign * result);
		else
			result = result * 10 + str[i++] - '0';
	}
	return (check_over_range(result, sign));
}
