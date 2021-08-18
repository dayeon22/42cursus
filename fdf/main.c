/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 16:57:56 by daypark           #+#    #+#             */
/*   Updated: 2021/08/16 18:41:40 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int main()
{
	t_map	m;

	//argc == 3일 때만 코드 돌아가게 하기
	read_map("42.fdf", &m); //리턴값에 따라 처리하기(전 함수에서 처리했음 됐고)
	draw(&m); //m에 포함된 값을 바꾸지 않을거면 굳이 포인터로 전송할 필요는 없을 듯
		
/*
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	int		i;
	int		j;
	int		x = 0;
//	int		y = 0;
	char	*line = 0;
	int		fd;
	int		ret;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "test");
	img.img = mlx_new_image(mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		char	**words;

		words = ft_split(line, '\n');
		i = 0;
		while (words[i])
		{
			char **word = ft_split(words[i], ' ');

			j = 0;
			while (word[j])
			{
				int num = ft_atoi(word[j]);
			
				if (num == 0)
					my_mlx_pixel_put(&img, (j * 30) + 10, (x * 30) + 10, 0x00FFFFFF);
				else
					my_mlx_pixel_put(&img, (j * 30) + 10, (x * 30) + 10, 0x00FF0000);
				printf("%d ", num);
				j++;
			}
			i++;
			x++;
			printf("\n");
		}
		free(line);
	}

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
*/
}
