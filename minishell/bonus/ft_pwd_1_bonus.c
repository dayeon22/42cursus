/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:11:07 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/17 14:11:08 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	invalid_error(t_env *env, t_split *sp)
{
	ft_putstr_fd("minishell: pwd: ", 2);
	ft_putchar_fd(sp->str[1][0], 2);
	ft_putstr_fd(sp->str[1], 2);
	ft_putstr_fd(" invalid option\n", 2);
	ft_putstr_fd("pwd: usage: pwd no option\n", 2);
	env->exit_n = 1;
	return (env->exit_n);
}

static int	pwd_write(t_env *env, t_split *sp, int len)
{
	int		size;
	char	buf[PWD_SIZE];

	size = sp_list_size(sp);
	if (size == 1)
	{
		if (len > 1 && ft_strlen(sp->str[1]) >= 2 && sp->str[1][0] == '-')
			if (!(ft_strlen(sp->str[1]) == 2 && !ft_strcmp(sp->str[1], "--")))
				return (invalid_error(env, sp));
		if (!getcwd(buf, PWD_SIZE))
			return (e_code(env, strerror(errno), errno));
		ft_putstr_fd(buf, 1);
		write(1, "\n", 1);
	}
	else if (size > 2)
	{
		env->exit_n = 0;
		return (env->exit_n);
	}
	env->exit_n = 0;
	return (env->exit_n);
}

int	ft_pwd(t_env *env, t_split *sp)
{
	int	len;

	len = two_point_size(sp->str);
	if (pwd_write(env, sp, len))
		return (env->exit_n);
	env->exit_n = 0;
	return (env->exit_n);
}
