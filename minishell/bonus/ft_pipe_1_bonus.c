/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:11:00 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/17 14:11:01 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	pipe_child_process(t_env *env, t_split *sp, int *fd, int left)
{
	close(fd[0]);
	if (left)
	{
		if (dup2(left, STDIN_FILENO) < 0)
			return (e_code(env, "pipe dup2 error 1", 1));
		close(left);
	}
	if (dup2(fd[1], STDOUT_FILENO) < 0)
		return (e_code(env, "pipe dup2 error 2", 1));
	close(fd[1]);
	if (check_builtin(env, sp, 2))
		return (env->exit_n);
	env->exit_n = 0;
	return (env->exit_n);
}

int	make_pipe_process(t_split *sp, t_env *env, int *left)
{
	int		fd[2];
	pid_t	pid;
	int		status;

	pipe(fd);
	env->exit_c = 1;
	pid = fork();
	if (pid < 0 && !close(fd[0]) && !close(fd[1]) && !close(*left))
		return (1);
	if (pid == 0)
	{
		if (pipe_child_process(env, sp, fd, *left))
			exit(env->exit_n);
		exit(env->exit_n);
	}
	waitpid(pid, &status, 0);
	if (*left != 0)
		close(*left);
	close(fd[1]);
	*left = fd[0];
	env->exit_n = command_exit(status);
	return (env->exit_n);
}

int	last_pipe(t_env *env, t_split *sp, int *left)
{
	pid_t	pid;
	int		stats;

	env->exit_c = 2;
	pid = fork();
	if (pid == 0)
	{
		if (dup2(*left, STDIN_FILENO) < 0)
			exit(e_code(env, "pipe dup2 error 1", 1));
		close(*left);
		if (check_builtin(env, sp, 2))
			exit(env->exit_n);
		env->exit_n = 0;
		exit(env->exit_n);
	}
	waitpid(pid, &stats, 0);
	close(*left);
	env->exit_n = command_exit(stats);
	return (env->exit_n);
}
