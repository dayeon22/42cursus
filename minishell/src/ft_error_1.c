/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:58:55 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/17 13:58:58 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	e_code(t_env *env, char *str, int code)
{
	env->exit_n = code;
	write(2, "minishell: ", ft_strlen("minishell: "));
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	return (env->exit_n);
}

void	finish_exit(t_env **env, t_split **sp, int check)
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
	if (check == 0)
	{
		tcsetattr(STDIN_FILENO, TCSANOW, &(*env)->old_term);
		exit((*env)->exit_n);
	}
}
