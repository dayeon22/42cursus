/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_great_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:10:46 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/17 14:10:47 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	close_great(t_env *env, int *left, int i)
{
	if (i == 1 && env->i_fd > 0)
		close(env->i_fd);
	if (i == 1 && env->o_fd > 0)
		close(env->o_fd);
	if (i == 1 && *left > 0)
		close(*left);
	if (i == 0 && *left > 0)
		close(*left);
	return (0);
}

int	last_great(t_env *env, int *left)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (*left > 0 && dup2(*left, STDIN_FILENO) < 0)
			exit(e_code(env, "great left dup2 error", 1));
		if (env->o_fd > 0 && dup2(env->o_fd, STDIN_FILENO) < 0)
			exit(e_code(env, "great o_fd dup2 error", 1));
		if (env->i_fd > 0 && dup2(env->i_fd, STDOUT_FILENO) < 0)
			exit(e_code(env, "great i_fd dup2 error", 1));
		close_great(env, left, 1);
		if (check_builtin_great(env))
			exit(env->exit_n);
		env->exit_n = 0;
		exit(env->exit_n);
	}
	waitpid(pid, &status, 0);
	close_great(env, left, 0);
	redir_env_init(env);
	env->exit_n = command_exit(status);
	return (env->exit_n);
}

t_split	*make_process(t_env *env, t_split *sp)
{
	t_split	*cp;

	cp = NULL;
	if (two_point_join(env, sp, 0))
		return (0);
	cp = save_option_join(env, sp->next, 0);
	if (!cp)
		return (0);
	return (cp);
}
