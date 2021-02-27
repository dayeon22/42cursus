/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:02:14 by daypark           #+#    #+#             */
/*   Updated: 2021/02/27 03:55:25 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		split_line(char **save, char **line)
{
	char	*newline_pos;
	char	*temp;

	newline_pos = ft_strchr(*save, '\n');
	*newline_pos = '\0';
	*line = ft_strdup(*save);
	
	if (ft_strlen(newline_pos + 1) == 0)
	{
		free(*save);
		*save = 0;
		return (1);
	}
	temp = ft_strdup(newline_pos + 1);
	free(*save);
	*save = temp;
	return (1);
}

int		return_all(char **save, char **line, int bytes)
{
	if (bytes < 0)
		return (-1);
	if (*save && ft_strchr(*save, '\n'))
		return (split_line(save, line));
	else if (*save)
	{
		*line = *save;
		*save = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*save[OPEN_MAX];
	int			bytes;
	char		*temp;

 	if ((fd < 0) || !(line) || (BUFFER_SIZE <= 0))
		return (-1);
	while ((bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes] = '\0';
		temp = !(save[fd]) ? ft_strdup(buf) : ft_strjoin(save[fd], buf);
		if (save[fd])
			free(save[fd]);
		save[fd] = temp;
		
		if (ft_strchr(save[fd], '\n'))
			return (split_line(&save[fd], line));
	}
	//system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	return (return_all(&save[fd], line, bytes));
}

/*
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	char *line = 0;
	int ret;
	int fd;

	fd = open("testfile", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	return (0);
}
*/



