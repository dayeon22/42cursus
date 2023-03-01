/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:11:56 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/18 14:36:27 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	set_termios(t_env *env)
{
	tcgetattr(STDIN_FILENO, &env->old_term);
	tcgetattr(STDIN_FILENO, &env->new_term);
	env->new_term.c_lflag &= ~(ECHOCTL);
	env->new_term.c_cc[VMIN] = 1;
	env->new_term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &env->new_term);
}

void	signal_ign(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	get_termios_signal(t_env *env)
{
	signal_ign();
	setup_signal_handlers(env);
}

void	cat_termios_signal(t_env *env)
{
	env->cat = 1;
	signal_ign();
	setup_signal_handlers(env);
}

int	signal_other(t_env *env, t_split *sp)
{
	if (!sp)
		return (1);
	if (two_point_size(sp->str) == 1 && sp_type_check(sp) != 1 \
		&& (!ft_strcmp(sp->str[0], "cat") || !ft_strcmp(sp->str[0], "wc") \
		|| !ft_strcmp(sp->str[0], "sort")))
		cat_termios_signal(env);
	if (two_point_size(sp->str) > 1 && sp_type_check(sp) != 1 \
		&& !ft_strcmp(sp->str[0], "grep"))
		cat_termios_signal(env);
	return (0);
}
