/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:11:35 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/17 17:38:14 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	last_redirection_pipe(t_env *env, t_split *sp, int *left, int i)
{
	if (i == CHAR_PIPE)
		return (last_pipe(env, sp, left));
	else if (i == CHAR_LESS || i == CHAR_DLESS)
		return (last_less(env));
	else if (i == CHAR_GREAT || i == CHAR_DGREAT)
	{
		if (env->exit_c != 3 && !ft_strcmp(env->s_op[0], "exit"))
			return (check_builtin_great(env));
		return (last_great(env, left));
	}
	else if (i == 0)
		return (check_builtin(env, sp, 1));
	env->exit_n = 0;
	return (env->exit_n);
}

static t_split	*check_type(t_env *env, t_split *sp, int *left, int *i)
{
	if (*i == CHAR_PIPE)
	{
		if (make_pipe_process(sp, env, left))
			return (NULL);
	}
	else if (*i == CHAR_LESS || *i == CHAR_DLESS \
		|| *i == CHAR_GREAT || *i == CHAR_DGREAT)
	{
		sp = make_process(env, sp);
		if (!sp)
			return (NULL);
		*i = sp->type;
	}
	return (sp);
}

static t_split	*process_run(t_env *env, t_split *sp, int type, int *left)
{
	int	idx;
	int	i;

	i = -1;
	idx = 0;
	if (type == CHAR_DGREAT || type == CHAR_GREAT)
	{
		env->exit_c = 3;
		last_great(env, left);
		idx = sp_type_int(sp->next, type);
		while (idx > 0 && ++i < idx - 2)
			sp = sp->next;
	}
	else if (type == CHAR_LESS || type == CHAR_DLESS)
	{
		last_less2(env, left);
		idx = sp_type_int(sp->next, type);
		while (idx > 0 && ++i < idx - 2)
			sp = sp->next;
	}
	return (sp);
}

static int	progress_check(int i, t_env *env, t_split **sp, int *left)
{
	t_split	*cp;
	int		type;

	cp = (*sp)->next->next;
	type = type_check_int(i);
	if (type == 1 || type == 2 || type == 4)
	{
		if (!cp)
			return (i);
		else if (cp && cp->type == CHAR_PIPE)
			*sp = process_run(env, *sp, i, left);
		else if (cp && cp->type != CHAR_PIPE && sp_type_check(cp) != 0)
			return (i);
		if ((type == 1 || type == 4) && (*sp)->type == CHAR_PIPE)
			return ((*sp)->type);
	}
	else if (type == 3)
		return (i);
	if (type == 2 && cp->type == CHAR_PIPE \
		&& !ft_strcmp(cp->next->str[0], "grep"))
		return (1);
	return (0);
}

int	run_redirection_pipe(t_split *sp, t_env *env)
{
	int		i;
	int		left;

	i = type_check_int(sp->type);
	left = 0;
	if (i != 5 && i != 0)
		return (e_code(sp->e, "redir order error", 1));
	while (sp->next)
	{
		if (sp->type == CHAR_WORD)
		{
			i = sp->next->type;
			sp = check_type(env, sp, &left, &i);
			if (!sp)
				break ;
			i = progress_check(i, env, &sp, &left);
			if (!sp || type_check_int(i) == 2 || type_check_int(i) == 1)
				break ;
		}
		sp = sp->next;
	}
	if (!sp && env->exit_n > 0)
		return (env->exit_n);
	return (last_redirection_pipe(env, sp, &left, i));
}
