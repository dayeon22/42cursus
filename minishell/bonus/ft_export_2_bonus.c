/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:10:26 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/17 14:10:28 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	sort_env(char **envp, int envp_len)
{
	int		i;
	int		j;
	char	*temp;

	i = -1;
	while (++i < envp_len - 1)
	{
		j = -1;
		while (++j < envp_len - i - 1)
		{
			if (ft_strcmp(envp[j], envp[j + 1]) == 1)
			{
				temp = envp[j];
				envp[j] = envp[j + 1];
				envp[j + 1] = temp;
			}
		}
	}
}

static void	print_env(char **envp)
{
	int		i;
	char	*equ_pos;

	i = -1;
	equ_pos = NULL;
	while (envp[++i])
	{
		ft_putstr_fd("declare -x ", 1);
		equ_pos = ft_strchr(envp[i], '=');
		if (!equ_pos)
			printf("%s\n", envp[i]);
		else
		{
			write(1, envp[i], equ_pos - envp[i] + 1);
			printf("\"%s\"\n", equ_pos + 1);
		}
	}
}

int	print_sorted_env(t_env *env)
{
	char	**new_envp;
	int		i;

	new_envp = (char **)malloc(sizeof(char *) * \
		(two_point_size(env->envp) + 1));
	if (!new_envp)
		return (e_code(env, "sort env malloc error", 1));
	i = -1;
	while (++i <= two_point_size(env->envp))
		new_envp[i] = 0;
	i = -1;
	while (env->envp[++i])
	{
		new_envp[i] = ft_strdup(env->envp[i]);
		if (!new_envp && !free_two_point(new_envp))
			return (e_code(env, "sort env malloc error", 1));
	}
	new_envp[i] = NULL;
	sort_env(new_envp, i);
	print_env(new_envp);
	free_two_point(new_envp);
	env->exit_n = 0;
	return (0);
}
