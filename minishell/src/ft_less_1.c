/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_less_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:10:53 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/17 14:10:54 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	redir_env_init(t_env *env)
{
	int		i;
	char	*c;
	char	*n;

	if (env->i_fd > 0 && !close(env->i_fd))
		env->i_fd = -42;
	if (env->o_fd > 0 && !close(env->o_fd))
		env->o_fd = -42;
	free_two_point(env->s_op);
	env->s_op = 0;
	i = -1;
	while (++i < env->d_len)
	{
		n = ft_itoa(i);
		c = ft_strjoin(".temp_dless_", n);
		unlink(c);
		free_one_point(n);
		free_one_point(c);
	}
	env->d_len = 0;
}

int	last_less(t_env *env)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (env->o_fd > 0 && dup2(env->o_fd, STDIN_FILENO) < 0)
			exit(e_code(env, "less o_fd dup2 error", 1));
		if (env->i_fd > 0 && dup2(env->i_fd, STDOUT_FILENO) < 0)
			exit(e_code(env, "less i_fd dup2 error", 1));
		if (!close(env->o_fd) && env->i_fd > 0)
			close(env->i_fd);
		if (check_builtin_great(env))
			exit(env->exit_n);
		env->exit_n = 0;
		exit(env->exit_n);
	}
	waitpid(pid, &status, 0);
	redir_env_init(env);
	env->exit_n = command_exit(status);
	return (env->exit_n);
}

int	last_less2(t_env *env, int *left)
{
	int		fd[2];
	pid_t	pid;
	int		status;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		if (env->o_fd > 0 && dup2(env->o_fd, STDIN_FILENO) < 0)
			exit(e_code(env, "less2 o_fd dup2 error", 1));
		if (fd[1] > 0 && dup2(fd[1], STDOUT_FILENO) < 0)
			exit(e_code(env, "less fd[1] dup2 error", 1));
		if (!close(env->o_fd) && !close(fd[0]) && !close(fd[1]))
			if (exec_redirection(env))
				exit(env->exit_n);
		env->exit_n = 0;
		exit(env->exit_n);
	}
	waitpid(pid, &status, 0);
	close(fd[1]);
	*left = fd[0];
	redir_env_init(env);
	env->exit_n = command_exit(status);
	return (env->exit_n);
}
