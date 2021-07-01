/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:27:51 by daypark           #+#    #+#             */
/*   Updated: 2021/07/01 16:46:02 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_info	g_info;

int		main(void)
{
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	g_info.c = 0;
	g_info.shift = 0;
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		pause();
}

void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
		g_info.c = g_info.c | (0b10000000 >> g_info.shift);
	g_info.shift++;
	if (g_info.shift > 7)
	{
		ft_putchar_fd(g_info.c, 1);
		if (g_info.c == '\0')
			ft_putchar_fd('\n', 1);
		g_info.c = 0;
		g_info.shift = 0;
	}
}
