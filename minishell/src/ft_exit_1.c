/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:02:25 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/17 14:02:35 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	arguments_error(t_env *env, t_split *sp, int size)
{
	int		num;

	num = numeric_error(sp->str[1]);
	if (size == 1 && env->exit_c != 2)
		ft_putstr_fd("exit\n", 2);
	env->exit_n = exit_error_collect(env, sp->str, num);
	finish_exit(&env, &sp, 1);
	return (env->exit_n);
}

static int	exit_sense(t_env *env, t_split *sp, int sp_len)
{
	int		size;

	size = sp_list_size(sp);
	if (sp_len > 2)
		exit(arguments_error(env, sp, size));
	env->exit_n = 0;
	if (env->exit_c != 2)
		ft_putstr_fd("exit\n", 1);
	if (sp_len == 2)
	{
		if (numeric_error(sp->str[1]))
			env->exit_n = exit_init(ft_atoi(sp->str[1]));
		else
			env->exit_n = arguments_error(env, sp, 0);
	}
	if (env->exit_c == 1)
		env->exit_n = 0;
	exit(env->exit_n);
}

int	ft_exit(t_env *env, t_split *sp)
{
	int	size;

	size = two_point_size(sp->str);
	if (size > 0)
		exit_sense(env, sp, size);
	return (env->exit_n);
}
