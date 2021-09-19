/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:36:55 by daypark           #+#    #+#             */
/*   Updated: 2021/09/19 23:54:22 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_map(char *file_name, t_map *m)
{
	int		fd;

	file_name = ft_strjoin("test_maps/", file_name);
	get_width_height(file_name, m);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		print_error(OPEN_FILE_ERROR);
	free(file_name);
	if (make_map(m) == 1)
		print_error(ETC_ERROR);
	input_map(fd, m);
}

int	make_map(t_map *m)
{
	int	i;

	m->map = (int **)malloc(sizeof(int *) * m->height);
	if (!m->map)
		return (1);
	i = -1;
	while (++i < m->height)
	{
		m->map[i] = (int *)malloc(sizeof(int) * m->width);
		if (!m->map[i])
		{
			while (--i >= 0)
				free(m->map[i]);
			return (1);
		}
	}
	return (0);
}

void	input_map(int fd, t_map *m)
{
	int		i;
	int		j;
	char	*line;
	char	**words;

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
		while (j >= 0)
			free(words[j--]);
		free(words);
	}
	free(line);
}

int	count_words(char *str)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	while (str[++i])
	{
		if (str[i] == ' ' && str[i + 1] && \
			(ft_isdigit(str[i + 1]) || str[i + 1] == '-'))
			cnt++;
	}
	if (str[0] == ' ')
		return (cnt);
	else
		return (cnt + 1);
}

int	get_width_height(char *file_name, t_map *m)
{
	char	*line;
	int		fd;
	int		first_width;

	m->height = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		print_error(OPEN_FILE_ERROR);
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
			print_error(FDF_WRONG_FORMAT_ERROR);
		free(line);
	}
	free(line);
	return (0);
}
