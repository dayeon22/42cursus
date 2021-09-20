/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 16:57:56 by daypark           #+#    #+#             */
/*   Updated: 2021/09/20 18:56:14 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		print_error(ARGC_ERROR);
	init(&data);
	read_map(argv[1], data.m);
	print_instructions();
	draw(&data);
	mlx_hook(data.mlx_win, 2, 1L << 0, &key_press, &data);
	mlx_hook(data.mlx_win, 17, 0, &terminate, &data);
	mlx_loop(data.mlx);
}

void	init(t_data *data)
{
	data->m = (t_map *)malloc(sizeof(t_map));
	data->move = (t_move *)malloc(sizeof(t_move));
	if (!data->m || !data->move)
		print_error(ETC_ERROR);
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->addr = mlx_get_data_addr(data->img,
			&data->bits_per_pixel, &data->line_length, &data->endian);
	data->move->x = WIN_WIDTH / 2;
	data->move->y = WIN_HEIGHT / 2;
	data->move->zoom = 30;
	data->move->altitude = 1;
	data->move->projection = ISOMETRIC;
}

int	terminate(t_data *data)
{
	int	i;

	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->m && data->m->map)
	{
		i = 0;
		while (i < data->m->height && data->m->map[i])
		{
			if (data->m->map[i])
				free(data->m->map[i]);
			i++;
		}
		free(data->m->map);
	}
	if (data->m)
		free(data->m);
	if (data->move)
		free(data->move);
	exit(0);
}
