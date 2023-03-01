/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_redir_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:09:47 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/18 09:56:49 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	echo_other_rd(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (env->s_op[++i])
	{
		j = -1;
		while (env->s_op[i][++j])
		{
			if (env->s_op[i][j] == '$' && env->s_op[i][j + 1] == '?')
			{
				ft_putnbr_fd(env->exit_n, 1);
				j = j + 1;
			}
			else
				ft_putchar_fd(env->s_op[i][j], 1);
		}
		if (env->s_op[i + 1])
			ft_putchar_fd(' ', 1);
	}
	write(1, "\n", 1);
	env->exit_n = 0;
	return (env->exit_n);
}

static int	echo_option_rd(t_env *env)
{
	int	i;
	int	j;

	i = 1;
	while (env->s_op[++i])
	{
		j = -1;
		while (env->s_op[i][++j])
		{
			if (env->s_op[i][j] == '$' && env->s_op[i][j + 1] == '?')
			{
				ft_putnbr_fd(env->exit_n, 1);
				j = j + 1;
			}
			else
				ft_putchar_fd(env->s_op[i][j], 1);
		}
		if (env->s_op[i + 1])
			ft_putchar_fd(' ', 1);
	}
	env->exit_n = 0;
	return (env->exit_n);
}

static int	echo_sense_rd(t_env *env, int len)
{
	if (len == 1)
		write(1, "\n", 1);
	else if (len > 1)
	{
		if (len == 2 && !ft_strcmp(env->s_op[1], "-n"))
			return (0);
		else if (len > 2 && !ft_strcmp(env->s_op[1], "-n"))
			return (echo_option_rd(env));
		else
			return (echo_other_rd(env));
	}
	env->exit_n = 0;
	return (env->exit_n);
}

int	ft_echo_redir(t_env *env)
{
	int	len;

	len = two_point_size(env->s_op);
	env->exit_n = echo_sense_rd(env, len);
	return (env->exit_n);
}
