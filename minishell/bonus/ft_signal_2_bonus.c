/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:12:00 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/17 14:12:02 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	sigint_setup(int signum)
{
	if (signum == SIGINT)
	{
		rl_replace_line("", 0);
		write(1, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

static void	sigquit_setup(int signum)
{
	if (signum == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

static void	sig_cat(int signum)
{
	if (signum == SIGQUIT)
		write(1, "Quit: 3", 8);
	write(1, "\n", 1);
	rl_redisplay();
}

void	setup_signal_handlers(t_env *env)
{
	if (!env->cat)
	{
		signal(SIGINT, sigint_setup);
		signal(SIGQUIT, sigquit_setup);
	}
	else
	{
		signal(SIGINT, sig_cat);
		signal(SIGQUIT, sig_cat);
		env->cat = 0;
	}
}
