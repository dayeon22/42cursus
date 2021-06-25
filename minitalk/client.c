/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:13:17 by daypark           #+#    #+#             */
/*   Updated: 2021/06/25 15:27:52 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <stdio.h> //지우기

int		main(int argc, char *argv[])
{
	int		send_pid;
	int		i; // 줄 모자라면 이거 없애고 포인터 값 증가시키기
	int		bit;
	int		j; //줄 모자라면 없애기

	if (argc != 3) //줄 모자라면 if (argc == 3)으로 하고 괄호안에 코드 넣기
		return 0;
	send_pid = ft_atoi(argv[1]);
	i = 0;

	while (argv[2][i])
	{
		j = 0;
		while (j < 8)
		{
			char c = argv[2][i];
			bit = (c >> j) & 0b00000001;
			//printf("%d", bit);
			if (bit == 1)
			{
				kill(send_pid, SIGUSR1);
			}
			else
			{
				kill(send_pid, SIGUSR2);
			}
			j++;
			usleep(100); //느린건지 확인
		}
		//printf("\n");
		i++;
	}

}