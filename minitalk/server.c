/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:27:51 by daypark           #+#    #+#             */
/*   Updated: 2021/06/25 20:44:33 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <stdio.h> //지우기

int c = 0;
int cnt = 0;

int		main(void)
{
	ft_putstr_fd("Server PID: ", 1);
	ft_putstr_fd(ft_itoa(getpid()), 1);
	write(1, "\n", 1);

	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);

	while (1)
	{
		pause();
	}
}

void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		printf("1");
	}
	else if (sig == SIGUSR2)
	{
		printf("0");
	}
	
	/*
	char	bit;

	printf("sig_handler()");
	cnt++;
	if (sig == SIGUSR1)
		bit = 1;
	if (sig == SIGUSR2)
		bit = 0;
	c = c >> 1;
	c += bit & 0b10000000;

	if (cnt == 8)
	{
		cnt = 0;
		printf("%c", c);
		c = 0;
	}
*/
}
