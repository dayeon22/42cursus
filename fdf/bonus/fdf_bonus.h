/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:29:41 by daypark           #+#    #+#             */
/*   Updated: 2021/09/22 02:37:13 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_WIDTH 1000
# define WIN_HEIGHT 800

# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define PLUS 24
# define MINUS 27
# define H 4 
# define L 37
# define I 34
# define P 35
# define ESC 53

# define ISOMETRIC 0
# define PARALLEL 1

# define ARGC_ERROR 0
# define OPEN_FILE_ERROR 1
# define FDF_WRONG_FORMAT_ERROR 2
# define ETC_ERROR 3

# include "../lib/mlx/mlx.h"
# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>

typedef struct s_map
{
	int		**map;
	int		width;
	int		height;
}			t_map;

typedef struct s_move
{
	int		x;
	int		y;
	float	zoom;
	float	altitude;
	float	projection;
}			t_move;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_map		*m;
	t_move		*move;
}				t_data;

typedef struct s_line
{
	int		x0;
	int		y0;
	int		z0;
	int		x1;
	int		y1;
	int		z1;
	int		dx;
	int		dy;
	int		xadd;
	int		yadd;
	int		f;
}			t_line;

/*
 * main.c
 */
void			init(t_data *data);
int				terminate(t_data *data);

/*
 * read_file.c
 */
void			read_map(char *file_name, t_map *m);
int				make_map(t_map *m);
void			input_map(int fd, t_map *m);
int				get_width_height(char *file_name, t_map *m);

/*
 * draw1.c
 */
void			draw(t_data *data);
void			set_line(t_data *data, int i, int j, int type);
void			bresenham_high(t_data *data, t_line *line);
void			bresenham_low(t_data *data, t_line *line);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);

/*
 * draw2.c
 */
unsigned int	get_color(int altitude);
void			key_move_zoom(int keycode, t_data *data);
int				key_press(int keycode, t_data *data);
void			isometric(t_line *line, t_data *data);
void			parallel(t_line *line, t_data *data);

/*
 * utils.c
 */
int				count_words(char *str);
int				get_idx(char *str, int c);
void			print_error(int errorcode);
void			print_instructions(void);

#endif
