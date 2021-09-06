/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 16:32:49 by daypark           #+#    #+#             */
/*   Updated: 2021/09/06 18:27:07 by daypark          ###   ########.fr       */
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
	data.mlx_win = mlx_new_window(data.mlx, 1280, 1024, "fdf"); //1280 * 1024
	data.img = mlx_new_image(data.mlx, 1280, 1024); //1920 * 1080
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
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	int cnt = 0;
	mlx_key_hook(data.mlx_win, &key_press, &cnt);
	mlx_loop(data.mlx);
	//mlx_destroy_window 실행하고 종료하기
}

int key_press(int keycode, t_data *data, int *cnt)
{
	if (keycode == 0)
		printf("A pushed %d\n", *cnt);
	data->endian = 0;
	return (0);
}

void	isometric(t_line *line)
{
    int previous_x;
    int previous_y;

    previous_x = line->x0 * 30;
    previous_y = line->y0 * 30;
    line->x0 = (previous_x - previous_y) * cos(0.523599) + 640;
    line->y0 = -line->z0 + (previous_x + previous_y) * sin(0.523599) + 512;

	previous_x = line->x1 * 30;
	previous_y = line->y1 * 30;
	line->x1 = (previous_x - previous_y) * cos(0.523599) + 640;
	line->y1 = -line->z1 + (previous_x + previous_y) * sin(0.523599) + 512;
}

void	set_line(t_line *line, int i, int j, t_map *m, int type) //isometric, horizontal과 합치기
{
	line->x0 = j;
	line->y0 = i;
	line->z0 = m->map[i][j];
	if (type == 0)
	{
		line->x1 = j + 1;
		line->y1 = i;
	}
	else
	{
		line->x1 = j;
		line->y1 = i + 1;
	}
	line->z1 = m->map[(int)line->y1][(int)line->x1];
}

unsigned int	get_color(int altitude)
{
	if (altitude <= -10)
		return (0x000000FF);
	else if (-10 < altitude && altitude < 10)
		return (0x00FFFFFF);
	else
		return (0x00FF0000);
}

//horizontal, vertical로 나누지 말고 기울기를 기준으로 나눠야 함
void	draw_horizontal(t_data *data, int i, int j, t_map *m)
{
	t_line	line;

	set_line(&line, i, j, m, 0);
	isometric(&line);
	line.dx = abs((int)line.x1 - (int)line.x0);
	line.dy = abs((int)line.y1 - (int)line.y0);
	int xadd = (int)line.x1 - (int)line.x0 > 0 ? 1 : -1;
	int yadd = (int)line.y1 - (int)line.y0 > 0 ? 1 : -1;
	line.f = 2 * line.dy - line.dx;
	int x = line.x0;
	int y = line.y0;

	while (x != (int)line.x1) // x < line.x1
	{
		if (0 < x && x < 1280 && 0 < y && y < 1024)
			my_mlx_pixel_put(data, x, y, get_color(line.z0));
		if (line.f < 0)
			line.f += 2 * line.dy;
		else
		{
			y += yadd;
			line.f += 2 * (line.dy - line.dx);
		}
		x += xadd;
	}
}

void	draw_vertical(t_data *data, int i, int j, t_map *m)
{
	t_line	line;

	set_line(&line, i, j, m, 1);
	isometric(&line);
	line.dx = abs((int)line.x1 - (int)line.x0);
	line.dy = abs((int)line.y1 - (int)line.y0);
	int xadd = (int)line.x1 - (int)line.x0 > 0 ? 1 : -1;
	int yadd = (int)line.y1 - (int)line.y0 > 0 ? 1 : -1;
	line.f = 2 * line.dx - line.dy;
	int x = line.x0;
	int y = line.y0;

	while (x != (int)line.x1) // >
	{
		if (0 < x && x < 1280 && 0 < y && y < 1024)
			my_mlx_pixel_put(data, x, y, get_color(line.z0));
		if (line.f < 0)
			line.f += 2 * line.dy;
		else
		{
			y += yadd;
			line.f += 2 * (line.dy - line.dx);
		}
		x += xadd;
	}
}
