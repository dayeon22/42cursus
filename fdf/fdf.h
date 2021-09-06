/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:29:41 by daypark           #+#    #+#             */
/*   Updated: 2021/08/30 21:42:52 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./lib/mlx/mlx.h"
# include "./lib/libft/libft.h"
# include <fcntl.h>
# include <math.h>


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
}				t_data;

typedef struct	s_map
{
	int			**map;
	int			width;
	int			height;
}				t_map;

typedef struct		s_line
{
	float			x0; //int vs float
	float			y0;
	int				z0;
	float			x1;
	float			y1;
	int				z1;
	int				dx;
	int				dy;
	int				f;
	double			slope;
	unsigned int	color;
}					t_line;

/*
 * read_file.c
 */
int		read_map(char *file_name, t_map *m);
int		input_map(int fd, t_map *m);
int		get_width_height(char *file_name, t_map *m);

/*
 * draw.c
 */
void	draw(t_map *m);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	draw_vertical(t_data *data, int i, int j, t_map *m);
void	draw_horizontal(t_data *data, int i, int j, t_map *m);

void	isometric(t_line *line);

//static void iso(int *x, int *y, int z);

#endif
