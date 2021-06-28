/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:27:51 by daypark           #+#    #+#             */
/*   Updated: 2021/06/29 01:39:06 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int c = 0;
int shift = 0;

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
	unsigned char	bit;
	bit = 0b10000000;
	if (sig == SIGUSR1)
		c |= bit >> shift;
	shift++;
	if (shift > 7)
	{
		ft_putchar_fd(c, 1);
		if (c == '\0')
			ft_putchar_fd('\n', 1);
		c = 0;
		shift = 0;
	}
}
