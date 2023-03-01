/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:08:34 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/17 14:08:41 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	**envp_lookup(char **envp, char *find)
{
	int		i;
	char	**path;

	i = -1;
	while (envp[++i])
		if (!ft_strncmp(envp[i], find, 5))
			break ;
	if (!envp[i])
		return (0);
	path = ft_split_mini(envp[i] + 5, ':');
	if (!path)
		return (0);
	return (path);
}

int	lookup_bin_path(char *order, char **path, char **envp)
{
	char	**bin_path;
	int		check;

	if (ft_strchr(order, '/'))
	{
		*path = ft_strdup(order);
		if (!(*path))
			return (-1);
		return (1);
	}
	bin_path = envp_lookup(envp, "PATH=");
	if (!bin_path)
		return (-1);
	check = bin_complete(order, bin_path, path);
	free_two_point(bin_path);
	return (check);
}

int	exec_bin_path(t_env *env, t_split *sp)
{
	int		check;
	char	*path;

	check = lookup_bin_path(sp->str[0], &path, env->envp);
	if (check == -1 && !free_one_point(path))
		return (e_code(env, "lookup bin path malloc error", 1));
	else if (check == 0 && !free_one_point(path))
		return (e_code(env, "command not found", 127));
	if (execve(path, sp->str, env->envp) == -1 && !free_one_point(path))
		return (e_code(env, strerror(errno), errno));
	free_one_point(path);
	env->exit_n = 0;
	return (env->exit_n);
}

int	single_list_cmd(t_env *env, t_split *sp)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (exec_bin_path(env, sp))
			exit(env->exit_n);
		exit(env->exit_n);
	}
	wait(&status);
	env->exit_n = command_exit(status);
	return (env->exit_n);
}

int	cmd_start(t_env *env, t_split *sp)
{
	int	cmd_count;

	env->d_len = 0;
	env->d_count = 0;
	env->exit_c = 0;
	cmd_count = sp_list_size(sp);
	if (!cmd_count)
		return (1);
	if (cmd_count > 1)
		env->exit_n = run_redirection_pipe(sp, env);
	else
		env->exit_n = check_builtin(env, sp, 1);
	return (env->exit_n);
}
