/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd_redir_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:11:19 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/17 14:11:20 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	invalid_error(t_env *env)
{
	ft_putstr_fd("minishell: pwd: ", 2);
	ft_putchar_fd(env->s_op[1][0], 2);
	ft_putstr_fd(env->s_op[1], 2);
	ft_putstr_fd(" invalid option\n", 2);
	ft_putstr_fd("pwd: usage: pwd no option\n", 2);
	env->exit_n = 1;
	return (env->exit_n);
}

static int	pwd_write(t_env *env, int size)
{
	char	buf[PWD_SIZE];

	if (size > 1 && ft_strlen(env->s_op[1]) > 1 && env->s_op[1][0] == '-')
		if (!(ft_strlen(env->s_op[1]) == 2 && !ft_strcmp(env->s_op[1], "--")))
			return (invalid_error(env));
	if (!getcwd(buf, PWD_SIZE))
		return (e_code(env, strerror(errno), errno));
	ft_putstr_fd(buf, 1);
	write(1, "\n", 1);
	env->exit_n = 0;
	return (env->exit_n);
}

int	ft_pwd_redir(t_env *env)
{
	int	size;

	size = two_point_size(env->s_op);
	if (pwd_write(env, size))
		return (env->exit_n);
	env->exit_n = 0;
	return (env->exit_n);
}
