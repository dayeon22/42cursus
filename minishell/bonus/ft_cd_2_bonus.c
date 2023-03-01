/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:02:11 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/18 14:32:33 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	env_pwd_input(t_env *env, char *path, int index)
{
	char	*cp;

	index = select_env_index(env, "PWD=");
	if (index == -1)
	{
		cp = ft_strjoin("PWD=", path);
		if (!cp)
			return (e_code(env, strerror(errno), errno));
		if (add_env(env, cp) && !free_one_point(cp))
			return (env->exit_n);
		free_one_point(cp);
	}
	else
	{
		cp = env->envp[index];
		env->envp[index] = ft_strjoin("PWD=", path);
		if (!env->envp[index])
		{
			env->envp[index] = cp;
			return (e_code(env, strerror(errno), errno));
		}
		free_one_point(cp);
	}
	env->exit_n = 0;
	return (env->exit_n);
}

int	env_oldpwd_input(t_env *env, char *path, int index)
{
	char	*cp;

	index = select_env_index(env, "OLDPWD=");
	if (index == -1)
	{
		cp = ft_strjoin("OLDPWD=", path);
		if (!cp)
			return (e_code(env, strerror(errno), errno));
		if (add_env(env, cp) && !free_one_point(cp))
			return (env->exit_n);
		free_one_point(cp);
	}
	else
	{
		cp = env->envp[index];
		env->envp[index] = ft_strjoin("OLDPWD=", path);
		if (!env->envp[index])
		{
			env->envp[index] = cp;
			return (e_code(env, strerror(errno), errno));
		}
		free_one_point(cp);
	}
	env->exit_n = 0;
	return (env->exit_n);
}

int	cd_mark_minus(t_env *env, char *str, int len)
{
	char	buf[PWD_SIZE];
	char	*path;

	if (!getcwd(buf, PWD_SIZE))
		return (e_code(env, strerror(errno), errno));
	if (len == 1 || (len == 2 && str[1] == '-'))
	{
		if (!select_path(env, "OLDPWD="))
			return (e_code(env, "cd: OLDPWD not set", 1));
		path = ft_strdup(select_path(env, "OLDPWD="));
		if ((!path || chdir(path) == -1) && !free_one_point(path))
			return (e_code(env, strerror(errno), errno));
		if ((env_pwd_input(env, path, -1) || env_oldpwd_input(env, buf, -1)) \
			&& !free_one_point(path))
			return (env->exit_n);
		write(1, path, ft_strlen(path));
		write(1, "\n", 1);
		free_one_point(path);
	}
	else if (len > 1 && str[1] != '-')
		return (e_code(env, "cd: invalid option\ncd: usage: cd [dir]", 1));
	env->exit_n = 0;
	return (env->exit_n);
}

int	cd_mark_wave(t_env *env, char *str, int len)
{
	char	buf[PWD_SIZE];
	char	*cp;

	cp = NULL;
	if (!getcwd(buf, PWD_SIZE))
		return (e_code(env, strerror(errno), errno));
	if (!select_path(env, "HOME="))
		return (e_code(env, "cd: HOME not set", 1));
	if (len == 1)
		cp = ft_strdup(select_path(env, "HOME="));
	else if (len > 1)
		cp = ft_strjoin(select_path(env, "HOME="), str + 1);
	if (!cp)
		return (e_code(env, "cd_mark_wave malloc error", 1));
	if (chdir(cp) == -1 && !free_one_point(cp))
		return (e_code(env, strerror(errno), errno));
	if ((env_oldpwd_input(env, buf, -1) || env_pwd_input(env, cp, -1)) \
		&& !free_one_point(cp))
		return (env->exit_n);
	free_one_point(cp);
	env->exit_n = 0;
	return (env->exit_n);
}
