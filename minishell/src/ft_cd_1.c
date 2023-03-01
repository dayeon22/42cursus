/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:02:00 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/18 14:24:47 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	cd_pathway(t_env *env, t_split *sp)
{
	char	buf[PWD_SIZE];
	char	buf2[PWD_SIZE];

	if (!getcwd(buf, PWD_SIZE))
		return (e_code(env, strerror(errno), errno));
	if (chdir(sp->str[1]) == -1)
		return (e_code(env, strerror(errno), errno));
	if (!getcwd(buf2, PWD_SIZE))
		return (e_code(env, strerror(errno), errno));
	if (env_oldpwd_input(env, buf, 0) || env_pwd_input(env, buf2, 0))
		return (env->exit_n);
	env->exit_n = 0;
	return (env->exit_n);
}

static int	cd_solo(t_env *env)
{
	char	buf[PWD_SIZE];
	char	*cp;

	if (!getcwd(buf, PWD_SIZE))
		return (e_code(env, strerror(errno), errno));
	if (!select_path(env, "HOME="))
		return (e_code(env, "cd: HOME not set", 1));
	cp = ft_strdup(select_path(env, "HOME="));
	if (!cp)
		return (e_code(env, "cd solo Malloc error", 1));
	if (chdir(cp) == -1 && !free_one_point(cp))
		return (e_code(env, strerror(errno), errno));
	if ((env_oldpwd_input(env, buf, -1) || env_pwd_input(env, cp, -1)) \
		&& !free_one_point(cp))
		return (env->exit_n);
	free_one_point(cp);
	env->exit_n = 0;
	return (env->exit_n);
}

static int	cd_mark(t_env *env, t_split *sp)
{
	int	len;

	len = ft_strlen(sp->str[1]);
	if (sp->str[1][0] == '-' && cd_mark_minus(env, sp->str[1], len))
		return (env->exit_n);
	if (sp->str[1][0] == '~' && cd_mark_wave(env, sp->str[1], len))
		return (env->exit_n);
	env->exit_n = 0;
	return (env->exit_n);
}

static int	cd_sense(t_env *env, t_split *sp, int sp_len)
{
	if (sp_len > 1 && sp->str[1])
	{
		if (!ft_strncmp(sp->str[1], "-", 1) || !ft_strncmp(sp->str[1], "~", 1))
			return (cd_mark(env, sp));
		else
			return (cd_pathway(env, sp));
	}
	else
		if (cd_solo(env))
			return (env->exit_n);
	env->exit_n = 0;
	return (env->exit_n);
}

int	ft_cd(t_env *env, t_split *sp)
{
	int	sp_len;

	sp_len = two_point_size(sp->str);
	if (cd_sense(env, sp, sp_len))
		return (env->exit_n);
	env->exit_n = 0;
	return (env->exit_n);
}
