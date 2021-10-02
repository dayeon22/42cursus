/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 05:28:13 by daypark           #+#    #+#             */
/*   Updated: 2021/10/02 17:38:20 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_over_range(unsigned long long result, int sign)
{
	if (result > 2147483648 && sign == -1)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	if (result > 2147483647 && sign == 1)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	return (result * sign);
}

int	count_space(const char *str, int i)
{
	int	cnt;

	cnt = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || \
			str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
	{
		i++;
		cnt++;
	}
	return (cnt);
}

void	check_num(const char *str, int i)
{
	if (ft_isdigit(str[i]) || str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (!ft_isdigit(str[i + 1]))
			{
				ft_putendl_fd("Error", 2);
				exit(1);
			}
		}
		return ;
	}
	ft_putendl_fd("Error", 2);
	exit(1);
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
	i += count_space(str, i);
	if (str[i] == '+' || str[i] == '-')
	{
		check_num(str, i);
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i])
	{
		check_num(str, i);
		if (!('0' <= str[i] && str[i] <= '9'))
			return (sign * result);
		else
			result = result * 10 + str[i++] - '0';
	}
	return (check_over_range(result, sign));
}
