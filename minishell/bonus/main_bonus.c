/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:13:17 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/17 14:13:19 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_env	env;
	t_split	sp;

	(void)argc;
	(void)argv;
	if ((copy_envp(&env, envp)))
		exit(1);
	set_termios(&env);
	get_termios_signal(&env);
	get_readline(&env, &sp);
	exit(0);
}
