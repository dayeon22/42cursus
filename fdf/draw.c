/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 16:32:49 by daypark           #+#    #+#             */
/*   Updated: 2021/08/18 19:29:07 by daypark          ###   ########.fr       */
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
	//mlx_destroy_window 실행하고 종료하기
}

void	draw_horizontal(t_data *data, int i, int j, t_map *m)
{
	t_line	line;

	//x, y값 설정
	line.x0 = j * 30;
	line.y0 = i * 30;
	line.x1 = line.x0 + 30;
	line.y1 = line.y0; //y좌표는 그대로
	line.dx = line.x1 - line.x0;
	line.dy = line.y1 - line.y0;

	line.df1 = 2 * line.dy;
	line.df2 = 2 * (line.dy - line.dx);
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
			line.f += line.df1;
		else
		{
			y++;
			line.f += line.df2;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

void	draw_vertical(t_data *data, int i, int j, t_map *m)
{
	t_line	line;

	//x, y값 설정(줄 여유있으면 width, height, f까지)
	line.x0 = j * 30;
	line.y0 = i * 30;
	line.x1 = line.x0;
	line.y1 = line.y0 + 30;
	line.dy = line.x1 - line.x0;
	line.dx = line.y1 - line.y0;

	line.df1 = 2 * line.dy; //이러지말고 아예 width와 height를 swap?
	line.df2 = 2 * (line.dy - line.dx);
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
			line.f += line.df1;
		else
		{
			x++;
			line.f += line.df2;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
