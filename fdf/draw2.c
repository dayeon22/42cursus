/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 01:40:09 by daypark           #+#    #+#             */
/*   Updated: 2021/09/20 18:40:10 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	get_color(int altitude)
{
	if (altitude <= -10)
		return (0x000000FF);
	else if (-10 < altitude && altitude < 10)
		return (0x00FFFFFF);
	else
		return (0x00FF0000);
}

void	key_move_zoom(int keycode, t_data *data)
{
	if (keycode == UP)
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
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == UP || keycode == DOWN || keycode == LEFT || \
			keycode == RIGHT || keycode == PLUS || keycode == MINUS)
		key_move_zoom(keycode, data);
	else if (keycode == H)
		data->move->altitude *= 1.1;
	else if (keycode == L)
		data->move->altitude *= 0.9;
	else if (keycode == I)
		data->move->projection = ISOMETRIC;
	else if (keycode == P)
		data->move->projection = PARALLEL;
	else if (keycode == ESC)
		terminate(data);
	else
		return (0);
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->addr = mlx_get_data_addr
		(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	draw(data);
	return (0);
}

void	isometric(t_line *line, t_data *data)
{
	double	pre_x;
	double	pre_y;

	pre_x = line->x0 * data->move->zoom;
	pre_y = line->y0 * data->move->zoom;
	line->x0 = (pre_x - pre_y) * cos(0.523599) + data->move->x;
	line->y0 = -line->z0 * data->move->altitude + \
		(pre_x + pre_y) * sin(0.523599) + data->move->y;
	pre_x = line->x1 * data->move->zoom;
	pre_y = line->y1 * data->move->zoom;
	line->x1 = (pre_x - pre_y) * cos(0.523599) + data->move->x;
	line->y1 = -line->z1 * data->move->altitude + \
		(pre_x + pre_y) * sin(0.523599) + data->move->y;
}

void	parallel(t_line *line, t_data *data)
{
	line->x0 = line->x0 * data->move->zoom + data->move->x;
	line->y0 = line->y0 * data->move->zoom + data->move->y;
	line->x1 = line->x1 * data->move->zoom + data->move->x;
	line->y1 = line->y1 * data->move->zoom + data->move->y;
}
