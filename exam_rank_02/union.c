/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 08:14:53 by daypark           #+#    #+#             */
/*   Updated: 2021/06/22 08:55:47 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	s[255];

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (i < 255)
		s[i++] = 0;
	i = 0;
	while (++i < 3)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!s[(unsigned char)argv[i][j]])
			{
				s[(unsigned char)argv[i][j]] = 1;
				write(1, &argv[i][j], 1);
			}
		}
	}
	write(1, "\n", 1);
}
