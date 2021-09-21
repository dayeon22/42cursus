/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 16:32:49 by daypark           #+#    #+#             */
/*   Updated: 2021/09/20 18:01:04 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_data *data)
{
	int		i;
	int		j;

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

void	set_line(t_data *data, int i, int j, int type)
{
	t_line	line;

	line.x0 = j;
	line.y0 = i;
	line.z0 = data->m->map[i][j];
	line.x1 = j;
	line.y1 = i;
	if (type == 0)
		line.x1++;
	else
		line.y1++;
	line.z1 = data->m->map[line.y1][line.x1];
	if (data->move->projection == ISOMETRIC)
		isometric(&line, data);
	else
		parallel(&line, data);
	line.dx = abs(line.x1 - line.x0);
	line.dy = abs(line.y1 - line.y0);
	if (line.dy < line.dx)
		bresenham_low(data, &line);
	else
		bresenham_high(data, &line);
}

void	bresenham_high(t_data *data, t_line *line)
{
	int		x;
	int		y;

	x = line->x0;
	y = line->y0;
	line->xadd = 1;
	if (line->x1 < line->x0)
		line->xadd = -1;
	line->yadd = 1;
	if (line->y1 < line->y0)
		line->yadd = -1;
	line->f = 2 * line->dx - line->dy;
	while (y != line->y1)
	{
		my_mlx_pixel_put(data, x, y, get_color(line->z0));
		if (line->f <= 0)
			line->f += 2 * line->dx;
		else
		{
			x += line->xadd;
			line->f += 2 * (line->dx - line->dy);
		}
		y += line->yadd;
	}
}

void	bresenham_low(t_data *data, t_line *line)
{
	int		x;
	int		y;

	x = line->x0;
	y = line->y0;
	line->xadd = 1;
	if (line->x1 < line->x0)
		line->xadd = -1;
	line->yadd = 1;
	if (line->y1 < line->y0)
		line->yadd = -1;
	line->f = 2 * line->dy - line->dx;
	while (x != line->x1)
	{
		my_mlx_pixel_put(data, x, y, get_color(line->z0));
		if (line->f <= 0)
			line->f += 2 * line->dy;
		else
		{
			y += line->yadd;
			line->f += 2 * (line->dy - line->dx);
		}
		x += line->xadd;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (0 < x && x < WIN_WIDTH && 0 < y && y < WIN_HEIGHT)
	{
		dst = data->addr + (y * data->line_length + \
			x * (data->bits_per_pixel / 8));
		*(unsigned int *) dst = color;
	}
}
