/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:09:55 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/17 14:09:56 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_env(t_env *env, t_split *sp)
{
	int	i;

	if (two_point_size(sp->str) > 1 && sp->str[1][0] != '-')
		return (e_code(env, "No such file or directory", 1));
	if (two_point_size(sp->str) > 1 && sp->str[1][0] == '-')
		return (e_code(env, "env: illegal option", 1));
	i = -1;
	while (env->envp && env->envp[++i])
	{
		if (!ft_strchr(env->envp[i], '='))
			continue ;
		ft_putstr_fd(env->envp[i], 1);
		write(1, "\n", 1);
	}
	env->exit_n = 0;
	return (env->exit_n);
}

int	ft_env_redir(t_env *env)
{
	int	i;

	if (two_point_size(env->s_op) > 1 && env->s_op[1][0] != '-')
		return (e_code(env, "No such file or directory", 1));
	if (two_point_size(env->s_op) > 1 && env->s_op[1][0] == '-')
		return (e_code(env, "env: illegal option", 1));
	i = -1;
	while (env->envp && env->envp[++i])
	{
		if (!ft_strchr(env->envp[i], '='))
			continue ;
		ft_putstr_fd(env->envp[i], 1);
		write(1, "\n", 1);
	}
	env->exit_n = 0;
	return (env->exit_n);
}
