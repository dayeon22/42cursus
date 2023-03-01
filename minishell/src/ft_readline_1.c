/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:11:26 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/18 16:57:58 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	signal_d_exit(t_env *env)
{
	ft_putstr_fd("\x1b[1A", 1);
	ft_putstr_fd("\033[11C", 1);
	write(1, "exit\n", 5);
	env->exit_n = 0;
	exit(env->exit_n);
}

static int	str_dollor_change(t_split *sp)
{
	char	**temp;

	while (sp)
	{
		if (sp->type == CHAR_WORD)
		{
			temp = sp->str;
			sp->str = apply_dollar(sp);
			if (!sp->str)
				return (e_code(sp->e, "dollor change malloc error", 1));
			free_two_point(temp);
		}
		sp = sp->next;
	}
	return (0);
}

void	get_readline(t_env *env, t_split *sp)
{
	char	*rl;
	int		x;

	while (1)
	{
		x = 0;
		rl = readline("minishell$ ");
		if (!rl)
			signal_d_exit(env);
		if (rl && ft_strlen(rl) > 0)
		{
			add_history(rl);
			sp = split_read_line(rl, sp, env);
			if (!x && signal_other(env, sp))
				x = 1;
			if (!x && str_dollor_change(sp))
				x = 1;
			if (!x && !check_list(sp))
				cmd_start(env, sp);
			free_cmd_list(&env, &sp);
		}
		if (!env->cat)
			get_termios_signal(env);
		free_one_point(rl);
	}
}
