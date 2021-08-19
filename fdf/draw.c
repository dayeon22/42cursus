/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 16:32:49 by daypark           #+#    #+#             */
/*   Updated: 2021/08/20 06:06:21 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

//void make_win(t_map *m);
//width,height 값 확인 후 최대크기 정함, window 생성

void	draw(t_map *m)
{
	t_data	data;
	int		i;
	int		j;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 1000, 1000, "test");
	data.img = mlx_new_image(data.mlx, 1000, 1000);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

	i = 0;
	while (i < m->height)
	{
		j = 0;
		while (j < m->width)
		{
			if (j != m->width - 1)
				draw_horizontal(&data, i, j, m);
			if (i != m->height - 1)
				draw_vertical(&data, i, j, m);
			j++;
		}
		i++;
	}
	mlx_loop(data.mlx);
	//mlx_put_image_to_window() 여기서 해주기
	//mlx_destroy_window 실행하고 종료하기
}

void	isometric(t_line *line)
{
	line->x0 = line->x0 * cos(0.5) - line->y0 * sin(0.5); //각도 변경하기
	line->y0 = line->x0 * sin(0.5) + line->y0 * cos(0.5);
	line->x1 = line->x1 * cos(0.5) - line->y1 * sin(0.5);
	line->y1 = line->x1 * sin(0.5) + line->y1 * cos(0.5);
}

void	draw_horizontal(t_data *data, int i, int j, t_map *m)
{
	t_line	line;

	line.x0 = 300 + j * 30;
	line.y0 = 200 + i * 30;
	line.x1 = line.x0 + 30;
	line.y1 = line.y0;

	isometric(&line);

	line.dx = line.x1 - line.x0;
	line.dy = line.y1 - line.y0;
	line.f = 2 * line.dy - line.dx;

	int x = line.x0;
	int y = line.y0;

	if (m->map[i][j] == 0)
		line.color = 0x00FFFFFF;
	else
		line.color = 0x00FF0000;

	while (x <= line.x1)
	{
		my_mlx_pixel_put(data, x, y, line.color);
		if (line.f < 0)
			line.f += 2 * line.dy;
		else
		{
			y++;
			line.f += 2 * (line.dy - line.dx);
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

void	draw_vertical(t_data *data, int i, int j, t_map *m)
{
	t_line	line;

	line.x0 = 300 + j * 30;
	line.y0 = 200 + i * 30;
	line.x1 = line.x0;
	line.y1 = line.y0 + 30;
	
	isometric(&line);

	line.dy = abs(line.x1 - line.x0); //음수나옴
	line.dx = line.y1 - line.y0;
	line.f = 2 * line.dy - line.dx;

	int x = line.x0;
	int y = line.y0;

	if (m->map[i][j] == 0)
		line.color = 0x00FFFFFF;
	else
		line.color = 0x00FF0000;
	
	while (y <= line.y1)
	{
		my_mlx_pixel_put(data, x, y, line.color);
		if (line.f < 0)
			line.f += 2 * line.dy;
		else
		{
			x--; //왼쪽으로 가야하니까
			line.f += 2 * (line.dy - line.dx);
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
