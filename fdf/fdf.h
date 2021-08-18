/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:29:41 by daypark           #+#    #+#             */
/*   Updated: 2021/08/18 19:20:41 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./lib/mlx/mlx.h"
# include "./lib/libft/libft.h"
# include <fcntl.h>


typedef struct	s_data //s_mlx 또는 s_fdf로 변경하기?
{
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

typedef struct	s_line
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			dx;
	int			dy;
	int			df1;
	int			df2;
	int			f;
	long		color; //unsigned long?
}				t_line;

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
void	bresenham_h(t_line *line, t_data *data);
void	bresenham_v(t_line *line, t_data *data);

#endif
