/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 16:32:49 by daypark           #+#    #+#             */
/*   Updated: 2021/09/18 16:26:33 by daypark          ###   ########.fr       */
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

void	draw(t_data *data)
{
	int		i;
	int		j;
	//t_line line;

	i = 0;
	while (i < data->m->height)
	{
		j = 0;
		while (j < data->m->width)
		{
			if (j != data->m->width - 1)
				set_line(data, i, j, 0);
			if (i != data->m->height - 1)
				set_line(data, i, j, 1);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

int		key_press(int keycode, t_data *data)
{
	if (keycode == UP) //overflow 일어나는 것 같음. long, double형으로 변경하기
		data->move->y -= 5;
	else if (keycode == DOWN)
		data->move->y += 5;
	else if (keycode == LEFT)
		data->move->x -= 5;
	else if (keycode == RIGHT)
		data->move->x += 5;
	else if (keycode == PLUS)
		data->move->zoom *= 1.1;
	else if (keycode == MINUS)
		data->move->zoom *= 0.9;
	else if (keycode == H)
		data->move->altitude *= 1.1;
	else if (keycode == L)
		data->move->altitude *= 0.9;
	else if (keycode == I)
		data->move->projection = ISOMETRIC;
	else if (keycode == P)
		data->move->projection = PARALLEL;
	else if (keycode == ESC)
		exit(0); //mlx_destroy_window(), free() 해야함
	else
		return (0);
	//mlx_clear_window(data->mlx, data->mlx_win);
	//기존 image destry 해야 할듯
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	draw(data);
	return (0);
}

void	isometric(t_line *line, t_data *data)
{
    int pre_x;
    int pre_y;

    pre_x = line->x0 * data->move->zoom;
    pre_y = line->y0 * data->move->zoom;
    line->x0 = (pre_x - pre_y) * cos(0.523599) + data->move->x;
    line->y0 = -line->z0 * data->move->altitude+ (pre_x + pre_y) * sin(0.523599) + data->move->y;

	pre_x = line->x1 * data->move->zoom;
	pre_y = line->y1 * data->move->zoom;
	line->x1 = (pre_x - pre_y) * cos(0.523599) + data->move->x;
	line->y1 = -line->z1 * data->move->altitude+ (pre_x + pre_y) * sin(0.523599) + data->move->y;
}

void	parallel(t_line *line, t_data *data)
{
	line->x0 = line->x0 * data->move->zoom + data->move->x;
	line->y0 = line->y0 * data->move->zoom + data->move->y;
	line->x1 = line->x1 * data->move->zoom + data->move->x;
	line->y1 = line->y1 * data->move->zoom + data->move->y;
}

void	set_line(t_data *data, int i, int j, int type)
{
	t_line line;

	line.x0 = j;
	line.y0 = i;
	line.z0 = data->m->map[i][j];
	line.x1 = j;
	line.y1 = i;
	if (type == 0)
		line.x1++;
	else
		line.y1++;
	line.z1 = data->m->map[(int)line.y1][(int)line.x1];
	if (data->move->projection == ISOMETRIC)
		isometric(&line, data);
	else
		parallel(&line, data);
  	line.dx = fabsf(line.x1 - line.x0);
  	line.dy = fabsf(line.y1 - line.y0);
	if (line.dy < line.dx)
		bresenham_low(data, &line);
	else
		bresenham_high(data, &line);
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

void	bresenham_low(t_data *data, t_line *line)
{
	int	x;
	int	y;
	int	xadd;
	int	yadd;
	float f;

	x = line->x0;
	y = line->y0;
	xadd = line->x1 > line->x0 ? 1 : -1;
	yadd = line->y1 > line->y0 ? 1 : -1;
	f = 2 * line->dy - line->dx;
	while (x != (int)line->x1)
	{
		if (0 < x && x < WIN_WIDTH && 0 < y && y < WIN_HEIGHT)
			my_mlx_pixel_put(data, x, y, get_color(line->z0));
		if (f <= 0)
			f += 2 * line->dy;
		else
		{
			y += yadd;
			f += 2 * (line->dy - line->dx);
		}
		x += xadd;
	}
}

void	bresenham_high(t_data *data, t_line *line)
{
	int	x;
	int	y;
	int	xadd;
	int	yadd;
	float f;

	x = line->x0;
	y = line->y0;
	xadd = line->x1 > line->x0 ? 1 : -1;
	yadd = line->y1 > line->y0 ? 1 : -1;
	f = 2 * line->dx - line->dy;
	while (y != (int)line->y1)
	{
		if (0 < x && x < WIN_WIDTH && 0 < y && y < WIN_HEIGHT)
			my_mlx_pixel_put(data, x, y, get_color(line->z0));
		if (f <= 0)
			f += 2 * line->dx;
		else
		{
			x += xadd;
			f += 2 * (line->dx - line->dy);
		}
		y += yadd;
	}
}
