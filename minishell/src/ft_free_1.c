/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:10:38 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/17 14:10:39 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	free_one_point(void *s)
{
	if (s)
		free(s);
	return (0);
}

int	free_two_point(char **s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		free(s[i]);
		s[i] = 0;
		i++;
	}
	if (s)
		free(s);
	return (0);
}

void	free_cmd_list(t_env **env, t_split **sp)
{
	sp_list_clear(sp);
	free_two_point((*env)->s_op);
	(*env)->s_op = 0;
	if ((*env)->i_fd > 0 && !close((*env)->i_fd))
		(*env)->i_fd = -42;
	if ((*env)->o_fd > 0 && !close((*env)->o_fd))
		(*env)->o_fd = -42;
	(*env)->d_len = 0;
	(*env)->d_count = 0;
	(*env)->cat = 0;
	(*env)->s_op = 0;
	(*env)->d_eof = 0;
}
