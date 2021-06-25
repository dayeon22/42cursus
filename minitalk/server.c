/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:27:51 by daypark           #+#    #+#             */
/*   Updated: 2021/06/25 17:29:56 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <stdio.h> //지우기

int		main(void)
{
	ft_putstr_fd("Server PID: ", 1);
	ft_putstr_fd(ft_itoa(getpid()), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);

	int i;
	i = 1;
	while (1)
	{
		printf("%d", i);
		sleep(1);
		//pause();
		
		i++;
	}

}

int c = 0;
int cnt = 0;

void	sig_handler(int sig)
{
	/*
	//printf("sig_handler()");
	if (sig == SIGUSR1)
	{
		printf("1");
	}
	else
	{
		printf("0");
	}
	*/

	char	bit;

	bit = (sig == SIGUSR1) ? 1 : 0;
	c = c >> 1;
	c += bit & 0b10000000;
	cnt++;

	if (cnt == 8)
	{
		cnt = 0;
		printf("%c", c);
		c = 0;
	}
}