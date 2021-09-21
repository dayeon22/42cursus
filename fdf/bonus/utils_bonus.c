/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 18:58:34 by daypark           #+#    #+#             */
/*   Updated: 2021/09/22 02:38:51 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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

int	get_idx(char *str, int c)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (i);
	}
	return (i);
}

void	print_error(int errorcode)
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

void	print_instructions(void)
{
	ft_putendl_fd("", 1);
	ft_putendl_fd("======== fdf instructions ========", 1);
	ft_putendl_fd("move: arrow keys", 1);
	ft_putendl_fd("zoom/unzoom: +/-", 1);
	ft_putendl_fd("isometric/parallel: i/p", 1);
	ft_putendl_fd("high/low: h/l", 1);
	ft_putendl_fd("Press ESC to exit the program!", 1);
}
