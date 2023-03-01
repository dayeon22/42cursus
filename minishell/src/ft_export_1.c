/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:10:22 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/18 09:56:18 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	env_name_check(t_env *env, char *str)
{
	if (*str != '_' && !ft_isalpha(*str))
	{
		e_code(env, "not valid identifier", 1);
		return (2);
	}
	str++;
	while (*str && *str != '=')
	{
		if (*str != '_' && !ft_isalnum(*str))
			return (e_code(env, "not valid identifier", 1));
		str++;
	}
	env->exit_n = 0;
	return (env->exit_n);
}

int	add_env(t_env *env, char *str)
{
	int		i;
	char	**n_envp;

	if (env_name_check(env, str) == 2)
		return (0);
	else if (env_name_check(env, str) == 1)
		return (env->exit_n);
	n_envp = (char **)malloc(sizeof(char *) * (two_point_size(env->envp) + 2));
	if (!n_envp)
		return (e_code(env, "1 add env malloc error", 1));
	i = -1;
	while (env->envp[++i])
	{
		n_envp[i] = ft_strdup(env->envp[i]);
		if (!n_envp[i] && !free_two_point(n_envp))
			return (e_code(env, "2 add env malloc error", 1));
	}
	n_envp[i] = ft_strdup(str);
	if (!n_envp[i - 1] && !free_two_point(n_envp))
		return (e_code(env, "3 add env malloc error", 1));
	n_envp[i + 1] = NULL;
	free_two_point(env->envp);
	env->envp = n_envp;
	env->exit_n = 0;
	return (env->exit_n);
}

static int	change_env(t_env *env, char *str, int env_idx)
{
	char	*cp;

	cp = env->envp[env_idx];
	env->envp[env_idx] = ft_strdup(str);
	if (!env->envp[env_idx])
	{
		env->envp[env_idx] = cp;
		return (e_code(env, "add env malloc error", 1));
	}
	free_one_point(cp);
	env->exit_n = 0;
	return (env->exit_n);
}

int	ft_export(t_env *env, t_split *sp)
{
	int	i;
	int	env_idx;

	i = 0;
	if (two_point_size(sp->str) == 1 && print_sorted_env(env))
		return (env->exit_n);
	while (sp->str && sp->str[++i])
	{
		env_idx = find_env(env, sp->str[i]);
		if (env_idx < 0)
		{
			if (add_env(env, sp->str[i]))
				return (env->exit_n);
		}
		else if (env_idx >= 0 && ft_strchr(sp->str[i], '='))
		{
			if (change_env(env, sp->str[i], env_idx))
				return (env->exit_n);
		}
	}
	env->exit_n = 0;
	return (env->exit_n);
}

int	ft_export_redir(t_env *env)
{
	int	i;
	int	size;

	if (two_point_size(env->s_op) == 1 && print_sorted_env(env))
		return (env->exit_n);
	i = 0;
	while (env->s_op[++i])
	{
		size = find_env(env, env->s_op[i]);
		if (size < 0)
		{
			if (add_env(env, env->s_op[i]))
				return (env->exit_n);
		}
		else if (size >= 0 && ft_strchr(env->s_op[i], '='))
		{
			if (change_env(env, env->s_op[i], size))
				return (env->exit_n);
		}
	}
	env->exit_n = 0;
	return (env->exit_n);
}
