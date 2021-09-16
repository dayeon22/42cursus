/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:36:55 by daypark           #+#    #+#             */
/*   Updated: 2021/09/17 01:59:02 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

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
	return (0);
}

int		get_idx(char *str, int c)
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

int		input_map(int fd, t_map *m)
{
	int		i;
	int		j;
	char	*line;
	char	**words;

	m->map = (int **)malloc(sizeof(int *) * m->height);//free
	if (!m->map)
		return (1);
	i = -1;
	while (++i < m->height)
	{
		m->map[i] = (int *)malloc(sizeof(int) * m->width);
		if (!m->map[i]) //실패시 free
			return (1);
	}
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		words = ft_split(line, ' ');
		j = -1;
		while (++j < m->width)
		{
			words[j][get_idx(words[j], ',')] = '\0';
			m->map[i][j] = ft_atoi(words[j]);
		}
		i++;
		free(line);
		int k = 0;
		while (k < m->width)
			free(words[k++]);
		free(words);
	}
	free(line);
	return (0);
}

int		count_words(char *str)
{
	int i;
	int cnt;

	i = -1;
	cnt = 0;
	while (str[++i])
	{
		if (str[i] == ' ' && str[i + 1] && ft_isdigit(str[i + 1]))
			cnt++;
	}
	if (str[0] == ' ')
		return (cnt);
	else
		return (cnt + 1);
}

int		get_width_height(char *file_name, t_map *m)
{
	char	*line;
	int		fd;
	int		first_width;

	m->height = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1)
	{
		printf("Failed to open file\n");
		return (1);
	}
	if (get_next_line(fd, &line) > 0)
	{
		m->height++;
		first_width = count_words(line);
		free(line);
	}
	while (get_next_line(fd, &line) > 0)
	{
		m->height++;
		m->width = count_words(line);
		if (m->width != first_width)
			return (1);
		free(line);
	}
	free(line);
	return (0);
}
