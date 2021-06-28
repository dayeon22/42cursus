/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:13:17 by daypark           #+#    #+#             */
/*   Updated: 2021/06/29 01:44:56 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		main(int argc, char *argv[])
{
	int		send_pid;
	int		i; // 줄 모자라면 이거 없애고 포인터 값 증가시키기
	int		bit;
	int		shift; //줄 모자라면 없애기

	if (argc != 3) //줄 모자라면 if (argc == 3)으로 하고 괄호안에 코드 넣기
		return 0;
	send_pid = ft_atoi(argv[1]);
	i = -1;
	while (argv[2][++i])
	{
		shift = -1;
		bit = 0b10000000;
		while (++shift < 8)
		{
			int a;
			unsigned char c = argv[2][i];
			a = c & (bit >> shift);
			if (a)
			{
				if (kill(send_pid, SIGUSR1))
					return (0);
			}
			else
			{
				if (kill(send_pid, SIGUSR2))
					return (0);
			}
			usleep(100);
		}
	}
}
