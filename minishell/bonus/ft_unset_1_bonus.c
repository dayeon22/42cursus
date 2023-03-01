/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@studen.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:12:35 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/17 16:07:52 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	find_env(t_env *env, char *str)
{
	int		i;
	char	*env_pos;
	char	*str_pos;
	int		compare_len;

	i = -1;
	str_pos = ft_strchr(str, '=');
	if (!str_pos)
		str_pos = ft_strchr(str, '\0');
	while (env->envp[++i])
	{
		env_pos = ft_strchr(env->envp[i], '=');
		if (!env_pos)
			env_pos = ft_strchr(env->envp[i], '\0');
		compare_len = str_pos - str;
		if (env_pos - env->envp[i] > compare_len)
			compare_len = env_pos - env->envp[i];
		if (!ft_strncmp(env->envp[i], str, compare_len))
			return (i);
	}
	return (-1);
}

static int	remove_env(t_env *env, int i)
{
	if (i < 0)
	{
		env->exit_n = 0;
		return (env->exit_n);
	}
	free_one_point(env->envp[i]);
	while (env->envp[i])
	{
		env->envp[i] = env->envp[i + 1];
		if (env->envp[i] == NULL)
			break ;
		i++;
	}
	env->exit_n = 0;
	return (0);
}

int	ft_unset(t_env *env, t_split *sp)
{
	int	i;

	i = 0;
	while (sp->str && sp->str[++i])
		if (remove_env(env, find_env(env, sp->str[i])))
			return (env->exit_n);
	env->exit_n = 0;
	return (env->exit_n);
}

int	ft_unset_redir(t_env *env)
{
	int	i;

	i = 0;
	while (env->s_op && env->s_op[++i])
		if (remove_env(env, find_env(env, env->s_op[i])))
			return (env->exit_n);
	env->exit_n = 0;
	return (env->exit_n);
}
