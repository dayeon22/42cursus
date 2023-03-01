/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:07:10 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/17 14:07:31 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	numeric_error(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

int	exit_error_collect(t_env *env, char **str, int num)
{
	if (!num)
	{
		if (env->exit_c != 3)
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(str[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
		}
		env->exit_n = 255;
		return (env->exit_n);
	}
	else if (two_point_size(str) > 2)
	{
		if (env->exit_c != 3)
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		if (num)
			env->exit_n = 1;
		return (env->exit_n);
	}
	env->exit_n = 0;
	return (env->exit_n);
}

int	exit_init(int num)
{
	int	x;

	while (1)
	{
		if ((num / 256) == 0)
		{
			x = num % 256;
			if (num < 0)
			{
				if (x == 0)
					return (0);
				return (256 + x);
			}
			else
				return (x);
		}
		else
			num = num / 256;
	}
	return (0);
}
