/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:09:07 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/17 14:09:08 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	exec_redirection(t_env *env)
{
	int		check;
	char	*path;

	check = lookup_bin_path(env->s_op[0], &path, env->envp);
	if (check == -1 && !free_one_point(path))
		return (e_code(env, "lookup bin path malloc error", 1));
	else if (check == 0 && !free_one_point(path))
		return (e_code(env, "No such file or directory", 127));
	if (execve(path, env->s_op, env->envp) == -1 && !free_one_point(path))
		return (e_code(env, strerror(errno), errno));
	free_one_point(path);
	env->exit_n = 0;
	return (env->exit_n);
}

t_split	*save_option_join(t_env *env, t_split *sp, int t)
{
	t_split	*cp;

	cp = NULL;
	while (sp)
	{
		if (sp->type == CHAR_WORD && two_point_join(env, sp, t))
			return (NULL);
		if (!sp->next || sp->next->type == CHAR_PIPE)
			return (cp);
		t = sp->type;
		cp = sp;
		sp = sp->next;
	}
	env->exit_n = 1;
	return (NULL);
}
