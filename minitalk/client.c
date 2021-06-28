/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:13:17 by daypark           #+#    #+#             */
/*   Updated: 2021/06/29 02:31:05 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		main(int argc, char *argv[])
{
	int		i;
	int		send_pid;

	if (argc != 3)
		return 0;
	send_pid = ft_atoi(argv[1]);
	i = -1;
	while (argv[2][++i])
	{
		if (transmission(argv[2][i], send_pid))
			return 0;
	}
	if (transmission('\0', send_pid))
		return 0;
}

int		transmission(char c, int send_pid)
{
	int				shift;

	shift = -1;
	while (++shift < 8)
	{
		if (c & (0b10000000 >> shift))
		{
			if (kill(send_pid, SIGUSR1))
				return (1);
		}
		else
		{
			if (kill(send_pid, SIGUSR2))
				return (1);
		}
		usleep(100);
	}
	return (0);
}
