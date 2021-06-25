/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 05:42:03 by daypark           #+#    #+#             */
/*   Updated: 2021/06/22 08:35:36 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	int	k;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = -1;
	while (argv[1][++i])
	{
		j = -1;
		while (argv[2][++j])
		{
			if (argv[1][i] == argv[2][j])
			{
				k = i;
				while (--k >= 0)
				{
					if (argv[1][i] == argv[1][k])
						break;
				}
				if (k < 0)
					write(1, &argv[1][i], 1);
			}
		}
	}
	write(1, "\n", 1);
}
