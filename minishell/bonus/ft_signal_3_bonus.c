/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:12:06 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/17 14:12:07 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	sig_dless(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		exit(1);
	}
	if (signum == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

void	redir_signal_handlers(void)
{
	signal(SIGINT, sig_dless);
	signal(SIGQUIT, sig_dless);
}
