/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:27:51 by daypark           #+#    #+#             */
/*   Updated: 2021/06/29 02:57:20 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	g_c = 0;
int				g_shift = 0;

int		main(void)
{
	ft_putstr_fd("Server PID: ", 1);
	ft_putstr_fd(ft_itoa(getpid()), 1); //ft_putnbr_fd로 변경?
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		pause();
}

void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
		g_c = g_c | (0b10000000 >> g_shift);
	g_shift++;
	if (g_shift > 7)
	{
		ft_putchar_fd(g_c, 1);
		if (g_c == '\0')
			ft_putchar_fd('\n', 1);
		g_c = 0;
		g_shift = 0;
	}
}
