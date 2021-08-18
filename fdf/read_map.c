/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:36:55 by daypark           #+#    #+#             */
/*   Updated: 2021/08/16 17:52:15 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

/*
 * map에 관한 구조체 만드는 것도 좋을 듯
 * (변수선언으로 인한 줄 수도 줄이고, 파라미터로 사용시에도 편리)
 * map, width, height 세트로 많이 사용한다면 구조체로 묶어버리기
 */

int		read_map(char *file_name, t_map *m)
{
	int		fd;
	
	file_name = ft_strjoin("test_maps/", file_name); //leaks?(strjoin에 malloc있음)
	if (get_width_height(file_name, m))
		return (1);
	if ((fd = open(file_name, O_RDONLY)) == -1)
	{ //return (print_err(OPEN_FILE)); 처럼 함수를 따로 만드는것도 좋을 듯
		printf("Failed to open file\n");
		return (1);
	}
	return (input_map(fd, m));
}

int		input_map(int fd, t_map *m)
{
	int		i;
	int		j;
	char	*line;
	char	**words;

	m->map = (int **)malloc(sizeof(int *) * m->height);
	if (!m->map)
		return (1);
	i = -1;
	while (++i < m->height)
	{
		m->map[i] = (int *)malloc(sizeof(int) * m->width);
		if (!m->map[i]) //free 해줘야할듯
			return (1);
	}
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		words = ft_split(line, ' ');
		j = -1;
		while (++j < m->width)
			m->map[i][j] = ft_atoi(words[j]);
		i++; //free(line) 해주기
	}
	return (0);
}

int		get_width_height(char *file_name, t_map *m)
{
	char	*line;
	char	**words;
	int		fd;

	m->width = 0;
	m->height = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1)
	{
		printf("Failed to open file\n");
		return (1);
	}
	while (get_next_line(fd, &line) > 0)
	{
		m->height++;
		words = ft_split(line, ' ');
		while (words[m->width]) //width가 모든 줄에서 같은지 확인해야 할듯
			m->width++;
		//free(line)해주기
	}
	return (0);
}

/*
int		open_file(char *file_name)
{
	file_name = ft_strjoin("test_maps/", file_name);
	return (open(file_name, O_RDONLY));
}
*/
