/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shlvl_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:11:49 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/17 14:11:49 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	set_shlvl(t_env *env, int index, int i)
{
	int		level;
	char	*str;
	char	*num;

	if (index == -1)
	{
		env->envp[i] = ft_strdup("SHLVL=1");
		if (!env->envp[i])
			return (e_code(env, "1 envp malloc error", 1));
		env->envp[i + 1] = NULL;
	}
	else
	{
		level = ft_atoi(env->envp[index] + 6) + 1;
		str = env->envp[index];
		num = ft_itoa(level);
		env->envp[index] = ft_strjoin("SHLVL=", num);
		if (!env->envp[index])
			return (e_code(env, "2 envp malloc error", 1));
		free_one_point(str);
		free_one_point(num);
	}
	return (0);
}

static int	get_envp_index(char **envp, char *s, int size, int *i)
{
	int	index;

	index = -1;
	while (envp[++(*i)])
		if (!ft_strncmp(envp[*i], s, size))
			index = *i;
	return (index);
}

static int	env_init(t_env *env, int i)
{
	env->exit_n = 0;
	env->exit_c = 0;
	env->i_fd = -42;
	env->o_fd = -42;
	env->s_op = 0;
	env->d_len = 0;
	env->d_count = 0;
	env->cat = 0;
	env->envp = (char **)malloc(sizeof(char *) * i + 1);
	if (!env->envp)
		return (e_code(env, "3 envp malloc error", 1));
	return (0);
}

int	copy_envp(t_env *env, char **envp)
{
	int		i;
	int		index;

	i = -1;
	index = get_envp_index(envp, "SHLVL=", 6, &i);
	if (index == -1)
		++i;
	if (env_init(env, i))
		return (env->exit_n);
	i = -1;
	while (envp[++i])
	{
		env->envp[i] = ft_strdup(envp[i]);
		if (!env->envp[i] && !free_two_point(env->envp))
			return (e_code(env, "4 envp malloc error", 1));
	}
	env->envp[i] = NULL;
	if (set_shlvl(env, index, i))
		return (env->exit_n);
	return (0);
}
