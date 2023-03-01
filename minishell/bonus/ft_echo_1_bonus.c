/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:09:41 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/18 16:25:18 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	echo_other(t_env *env, t_split *sp)
{
	int	i;
	int	j;

	i = 0;
	while (sp->str[++i] != 0)
	{
		j = -1;
		while (sp->str[i][++j])
			ft_putchar_fd(sp->str[i][j], 1);
		if (sp->str[i + 1] != 0)
			ft_putchar_fd(' ', 1);
	}
	write(1, "\n", 1);
	env->exit_n = 0;
	return (env->exit_n);
}

static int	echo_option(t_env *env, t_split *sp)
{
	int	i;
	int	j;

	i = 1;
	while (sp->str[++i])
	{
		j = -1;
		while (sp->str[i][++j])
			ft_putchar_fd(sp->str[i][j], 1);
		if (sp->str[i + 1])
			ft_putchar_fd(' ', 1);
	}
	env->exit_n = 0;
	return (env->exit_n);
}

static int	echo_sense(t_env *env, t_split *sp, int len)
{
	if (len == 1)
		write(1, "\n", 1);
	else if (len > 1)
	{
		if (len == 2 && !ft_strcmp(sp->str[1], "-n"))
			return (0);
		else if (len > 2 && !ft_strcmp(sp->str[1], "-n"))
			return (echo_option(env, sp));
		else
			return (echo_other(env, sp));
	}
	env->exit_n = 0;
	return (env->exit_n);
}

int	ft_echo(t_env *env, t_split *sp)
{
	int	len;

	len = two_point_size(sp->str);
	if (echo_sense(env, sp, len))
		return (env->exit_n);
	env->exit_n = 0;
	return (env->exit_n);
}
