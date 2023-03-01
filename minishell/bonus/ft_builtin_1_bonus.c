/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:58:24 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/18 17:51:09 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_builtin(t_env *env, t_split *sp, int count)
{
	if (!ft_strcmp(sp->str[0], "echo"))
		return (ft_echo(env, sp));
	else if (!ft_strcmp(sp->str[0], "cd"))
		return (ft_cd(env, sp));
	else if (!ft_strcmp(sp->str[0], "pwd"))
		return (ft_pwd(env, sp));
	else if (!ft_strcmp(sp->str[0], "export"))
		return (ft_export(env, sp));
	else if (!ft_strcmp(sp->str[0], "unset"))
		return (ft_unset(env, sp));
	else if (!ft_strcmp(sp->str[0], "env"))
		return (ft_env(env, sp));
	else if (!ft_strcmp(sp->str[0], "exit"))
		return (ft_exit(env, sp));
	else
	{
		if (count == 1)
			return (single_list_cmd(env, sp));
		else
			return (exec_bin_path(env, sp));
	}
	env->exit_n = 0;
	return (env->exit_n);
}

int	check_builtin_great(t_env *env)
{
	if (!ft_strcmp(env->s_op[0], "echo"))
		return (ft_echo_redir(env));
	else if (!ft_strcmp(env->s_op[0], "cd"))
		return (ft_cd_redir(env));
	else if (!ft_strcmp(env->s_op[0], "pwd"))
		return (ft_pwd_redir(env));
	else if (!ft_strcmp(env->s_op[0], "export"))
		return (ft_export_redir(env));
	else if (!ft_strcmp(env->s_op[0], "unset"))
		return (ft_unset_redir(env));
	else if (!ft_strcmp(env->s_op[0], "env"))
		return (ft_env_redir(env));
	else if (!ft_strcmp(env->s_op[0], "exit"))
		return (ft_exit_redir(env));
	else
		return (exec_redirection(env));
	env->exit_n = 0;
	return (env->exit_n);
}
