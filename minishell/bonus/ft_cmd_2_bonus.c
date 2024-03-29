/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:09:00 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/17 14:09:03 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	command_exit(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (0);
}

static char	*connection_order(char *str, char *order)
{
	char	*path;
	int		size;

	size = ft_strlen(str) + ft_strlen(order) + 2;
	path = (char *)malloc(sizeof(char) * size);
	if (!path)
		return (0);
	ft_strlcpy(path, str, size);
	ft_strlcat(path, "/", size);
	ft_strlcat(path, order, size);
	return (path);
}

int	bin_complete(char *order, char **bin_path, char **path)
{
	int			i;
	struct stat	buf;

	i = -1;
	while (bin_path[++i])
	{
		*path = connection_order(bin_path[i], order);
		if (!(*path))
			return (-1);
		if (stat(*path, &buf) == 0)
			return (1);
		free_one_point(*path);
	}
	*path = 0;
	return (0);
}
