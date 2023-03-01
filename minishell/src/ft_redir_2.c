/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:59:37 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/17 14:11:40 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	f_order_join(t_env *env, t_split *sp)
{
	int	i;

	i = -1;
	while (sp->str && sp->str[++i])
	{
		env->s_op[i] = ft_strdup(sp->str[i]);
		if (!env->s_op[i])
			return (e_code(env, "f order s_op[] malloc error", 1));
	}
	env->s_op[i] = NULL;
	env->exit_n = 0;
	return (env->exit_n);
}

static int	file_open(t_env *env, char *s, int t)
{
	if (t == CHAR_GREAT)
		env->i_fd = open(s, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	else if (t == CHAR_DGREAT)
		env->i_fd = open(s, O_CREAT | O_WRONLY | O_APPEND, 0666);
	if (t == CHAR_GREAT || t == CHAR_DGREAT)
		if (env->i_fd < 0)
			return (e_code(env, strerror(errno), errno));
	if (t == CHAR_LESS)
		env->o_fd = open(s, O_RDONLY, 0444);
	else if (t == CHAR_DLESS)
		env->o_fd = get_here_document(env, s, 0);
	if (t == CHAR_LESS || t == CHAR_DLESS)
		if (env->o_fd < 0)
			return (e_code(env, strerror(errno), errno));
	env->exit_n = 0;
	return (env->exit_n);
}

static int	s_order_join(t_env *env, t_split *sp, char **cp, int t)
{
	int	i[2];

	i[0] = 0;
	i[1] = -1;
	while (cp && cp[++i[1]])
	{
		env->s_op[i[0]++] = ft_strdup(cp[i[1]]);
		if (!env->s_op[i[0] - 1])
			return (e_code(env, "s_order s_op malloc error", 1));
	}
	i[1] = 0;
	while (sp->str && sp->str[++i[1]])
	{
		env->s_op[i[0]++] = ft_strdup(sp->str[i[1]]);
		if (!env->s_op[i[0] - 1])
			return (e_code(env, "s_order s_op malloc error", 1));
	}
	env->s_op[i[0]] = NULL;
	if (file_open(env, sp->str[0], t))
		return (1);
	env->exit_n = 0;
	return (env->exit_n);
}

int	two_point_join(t_env *env, t_split *sp, int t)
{
	char	**cp;

	cp = env->s_op;
	if (!cp)
		env->s_op = (char **)malloc(sizeof(char *) \
			* two_point_size(sp->str) + 1);
	else if (cp)
		env->s_op = (char **)malloc(sizeof(char *) \
			* (two_point_size(env->s_op) + two_point_size(sp->str)));
	if (!env->s_op)
		return (e_code(env, "s_op malloc err", 1));
	if (!cp && f_order_join(env, sp))
		return (env->exit_n);
	else if (cp && s_order_join(env, sp, cp, t) && !free_two_point(cp))
		return (env->exit_n);
	free_two_point(cp);
	env->exit_n = 0;
	return (env->exit_n);
}
