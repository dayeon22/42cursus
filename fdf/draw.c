/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 16:32:49 by daypark           #+#    #+#             */
/*   Updated: 2021/09/14 02:02:01 by daypark          ###   ########.fr       */
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
			{	
				draw_horizontal(data, i, j);
			}
			if (i != data->m->height - 1)
			{
				draw_vertical(data, i, j);
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	//mlx_destroy_window 실행하고 종료하기
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
    line->y0 = -line->z0 + (pre_x + pre_y) * sin(0.523599) + data->move->y;

	pre_x = line->x1 * data->move->zoom;
	pre_y = line->y1 * data->move->zoom;
	line->x1 = (pre_x - pre_y) * cos(0.523599) + data->move->x;
	line->y1 = -line->z1 + (pre_x + pre_y) * sin(0.523599) + data->move->y;
}

void	parallel(t_line *line, t_data *data)
{
	line->x0 = line->x0 * data->move->zoom + data->move->x;
	line->y0 = line->y0 * data->move->zoom + data->move->y;
	line->x1 = line->x1 * data->move->zoom + data->move->x;
	line->y1 = line->y1 * data->move->zoom + data->move->y;
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

void	bresenham(t_data *data, t_line *line)
{
	int xadd = (int)line->x1 - (int)line->x0 > 0 ? 1 : -1;
	int yadd = (int)line->y1 - (int)line->y0 > 0 ? 1 : -1;
	int x = line->x0;
	int y = line->y0;

	while (x != (int)line->x1) // x < line.x1
	{
		if (0 < x && x < WIN_WIDTH && 0 < y && y < WIN_HEIGHT)
		{
			//printf("%d %d\n", x, y);
			my_mlx_pixel_put(data, x, y, get_color(line->z0));
		}
		if (line->f < 0)
			line->f = line->f + 2 * line->dx;
		else
		{
			y += yadd;
			line->f = line->f + 2 * (line->dy - line->dx);
		}
		x += xadd;
	}	
}

void	bresenham_low(t_data *data, t_line *line)
{
	int	x;
	int	y;
	int	xadd;
	int	yadd;

	x = line->x0;
	y = line->y0;
	xadd = line->x1 > line->x0 ? 1 : -1;
	yadd = line->y1 > line->y0 ? 1 : -1;

	line->f = 2 * line->dy - line->dx;

	while (x != (int)line->x1)
	{
		if (0 < x && x < WIN_WIDTH && 0 < y && y < WIN_HEIGHT)
			my_mlx_pixel_put(data, x, y, get_color(line->z0));
		if (line->f <= 0)
			line->f += 2 * line->dy;
		else
		{
			y += yadd;
			line->f += 2 * (line->dy - line->dx);
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

	x = line->x0;
	y = line->y0;
	xadd = line->x1 > line->x0 ? 1 : -1;
	yadd = line->y1 > line->y0 ? 1 : -1;

	line->f = 2 * line->dx - line->dy;

	while (y != (int)line->y1)
	{
		if (0 < x && x < WIN_WIDTH && 0 < y && y < WIN_HEIGHT)
			my_mlx_pixel_put(data, x, y, get_color(line->z0));
		if (line->f <= 0)
			line->f += 2 * line->dx;
		else
		{
			x += xadd;
			line->f += 2 * (line->dx - line->dy);
		}
		y += yadd;
	}
}

//horizontal, vertical로 나누지 말고 기울기를 기준으로 나눠야 함
void	draw_horizontal(t_data *data, int i, int j)
{
	t_line	line;

	set_line(&line, i, j, data->m, 0);
	isometric(&line, data);
	//parallel(&line, data);
	line.dx = fabsf(line.x1 - line.x0);
	line.dy = fabsf(line.y1 - line.y0);

	if (line.dy < line.dx)
		bresenham_low(data, &line);
	else
		bresenham_high(data, &line);

	//printf("%f %f %f %f\n", line.x0, line.y0, line.x1, line.y1);

	//bresenham(data, &line);

/*
	int xadd = (int)line.x1 - (int)line.x0 > 0 ? 1 : -1;
	int yadd = (int)line.y1 - (int)line.y0 > 0 ? 1 : -1;
	line.f = 2 * line.dy - line.dx;
	int x = line.x0;
	int y = line.y0;

	while (x != (int)line.x1) // x < line.x1
	{
		if (0 < x && x < WIN_WIDTH && 0 < y && y < WIN_HEIGHT)
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
*/	
}

void	draw_vertical(t_data *data, int i, int j)
{
	t_line	line;

	set_line(&line, i, j, data->m, 1);
	isometric(&line, data);
	//parallel(&line, data);
	line.dx = fabsf(line.x1 - line.x0);
	line.dy = fabsf(line.y1 - line.y0);

	if(line.dy < line.dx)
		bresenham_low(data, &line);
	else
		bresenham_high(data, &line);

	//printf("%f %f %f %f\n", line.x0, line.y0, line.x1, line.y1);

	//bresenham(data, &line);

/*
	int xadd = (int)line.x1 - (int)line.x0 > 0 ? 1 : -1;
	int yadd = (int)line.y1 - (int)line.y0 > 0 ? 1 : -1;
	line.f = 2 * line.dx - line.dy;
	int x = line.x0;
	int y = line.y0;

	while (x != (int)line.x1) // >
	{
		if (0 < x && x < WIN_WIDTH && 0 < y && y < WIN_HEIGHT)
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
*/	
}

