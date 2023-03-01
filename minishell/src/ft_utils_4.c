/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:13:07 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/17 14:13:09 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*select_path(t_env *env, char *str)
{
	int	i;

	i = -1;
	while (env->envp[++i])
		if (!ft_strncmp(env->envp[i], str, ft_strlen(str)))
			return (env->envp[i] + ft_strlen(str));
	return (NULL);
}

int	select_env_index(t_env *env, char *str)
{
	int		i;
	int		index;

	i = -1;
	index = -1;
	while (env->envp[++i])
		if (!ft_strncmp(env->envp[i], str, ft_strlen(str)))
			index = i;
	return (index);
}

int	two_point_size(char **s)
{
	int	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

int	file_delet(t_env *env)
{
	char	*n;
	char	*c;
	int		i;

	i = -1;
	while (++i < env->d_len)
	{
		n = ft_itoa(i);
		c = ft_strjoin(".temp_dless_", n);
		unlink(c);
		free_one_point(n);
		free_one_point(c);
	}
	env->d_len = 0;
	return (0);
}
