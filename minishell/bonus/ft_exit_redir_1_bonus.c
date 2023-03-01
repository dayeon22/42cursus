/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_redir_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:10:09 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/17 14:10:10 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	arguments_error(t_env *env)
{
	int		num;

	num = numeric_error(env->s_op[1]);
	if (env->exit_c != 3)
		ft_putstr_fd("exit\n", 2);
	env->exit_n = exit_error_collect(env, env->s_op, num);
	return (env->exit_n);
}

static int	exit_sense(t_env *env)
{
	int		size;

	size = two_point_size(env->s_op);
	if (size > 1)
		exit(arguments_error(env));
	env->exit_n = 0;
	if (env->exit_c != 3)
		ft_putstr_fd("exit\n", 1);
	if (size == 2)
	{
		if (numeric_error(env->s_op[1]))
			env->exit_n = exit_init(ft_atoi(env->s_op[1]));
		else
			env->exit_n = arguments_error(env);
	}
	exit(env->exit_n);
}

int	ft_exit_redir(t_env *env)
{
	env->exit_n = exit_sense(env);
	return (env->exit_n);
}
