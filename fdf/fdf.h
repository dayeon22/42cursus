/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:29:41 by daypark           #+#    #+#             */
/*   Updated: 2021/09/18 15:47:14 by daypark          ###   ########.fr       */
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

# include "./lib/mlx/mlx.h"
# include "./lib/libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>

typedef struct	s_map
{
	int			**map;
	int			width;
	int			height;
}				t_map;

typedef struct	s_move
{
	int			x;
	int			y;
	float		zoom;
	float		altitude;
	float		projection;
}				t_move;

typedef struct	s_data //s_mlx 또는 s_fdf로 변경하기?
{ //근데 mlx와 image를 합쳐도 되나? imx하나에 img 여러개 같은데
	//예제 코드에서 구조체에 속하지 않은 것들
	void		*mlx;
	void		*mlx_win;

	//예제 코드에서 구조체에 속한 것들
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_map		*m; // 포인터로 안해도 될것같은데
	t_move		*move;
}				t_data;

typedef struct		s_line
{
	float			x0; //int vs float
	float			y0;
	int				z0;
	float			x1;
	float			y1;
	int				z1;
	float			dx;
	float			dy;
	int				f;
}					t_line;

/*
 * main.c
 */
void	init_move(t_move *move);
int		print_error(int errorcode);

/*
 * read_file.c
 */
void	read_map(char *file_name, t_map *m);
int		get_idx(char *str, int c);
int 	double_free(char **ptr, int n);
int		make_map(t_map *m);
void	input_map(int fd, t_map *m);
int		count_words(char *str);
int		get_width_height(char *file_name, t_map *m);

/*
 * draw.c
 */
void	draw(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	isometric(t_line *line, t_data *data);
void	parallel(t_line *line, t_data *data);

int key_press(int keycode, t_data *data);
void	set_line(t_data *data, int i, int j, int type);
unsigned int	get_color(int altitude);

void	bresenham_low(t_data *data, t_line *line);
void	bresenham_high(t_data *data, t_line *line);

#endif
