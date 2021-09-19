/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 16:57:56 by daypark           #+#    #+#             */
/*   Updated: 2021/09/20 02:36:52 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc != 2)
		print_error(ARGC_ERROR);
	data = (t_data *)malloc(sizeof(t_data));
	data->m = (t_map *)malloc(sizeof(t_map));
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->addr = mlx_get_data_addr(data->img,
			&data->bits_per_pixel, &data->line_length, &data->endian);
	data->move = (t_move *)malloc(sizeof(t_move));
	read_map(argv[1], data->m);
	init_move(data->move);
	print_instructions();
	draw(data);
	mlx_hook(data->mlx_win, 2, 1L << 0, &key_press, data);
	mlx_loop(data->mlx);
}

void	init_move(t_move *move)
{
	move->x = WIN_WIDTH / 2;
	move->y = WIN_HEIGHT / 2;
	move->zoom = 30;
	move->altitude = 1;
	move->projection = ISOMETRIC;
}

int	print_error(int errorcode)
{
	if (errorcode == ARGC_ERROR)
		ft_putstr_fd("Wrong format!!! [./fdf file_name]", 2);
	else if (errorcode == OPEN_FILE_ERROR)
		ft_putstr_fd("Failed to open the file", 2);
	else if (errorcode == FDF_WRONG_FORMAT_ERROR)
		ft_putstr_fd("The fdf file has wrong format!", 2);
	else if (errorcode == ETC_ERROR)
		ft_putstr_fd("error!", 2);
	exit(0);
}

int	get_idx(char *str, int c)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (i);
	}
	return (-1);
}

void	print_instructions(void)
{
	ft_putendl_fd("", 1);
	ft_putendl_fd("======== fdf instructions ========", 1);
	ft_putendl_fd("move: arrow", 1);
	ft_putendl_fd("zoom/unzoom: +/-", 1);
	ft_putendl_fd("isometric/parallel: i/p", 1);
	ft_putendl_fd("high/low: h/l", 1);
	ft_putendl_fd("Press ESC to exit the program!", 1);
}
