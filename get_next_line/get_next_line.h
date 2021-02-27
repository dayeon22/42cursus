/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:16:40 by daypark           #+#    #+#             */
/*   Updated: 2021/02/27 04:50:59 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif

#ifndef OPEN_MAX
# define OPEN_MAX 256
#endif

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
//char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);

//여기서부터 추가한것
char *ft_strncpy(char *dst, char *src, int n);
char *ft_strjoin(char *s1, char *s2);
//여기까지

int		get_next_line(int fd, char **line);
int		split_line(char **save, char **line);
int		return_all(char **backup, char **line, int read_size);

#endif
