/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:13:17 by jawpark           #+#    #+#             */
/*   Updated: 2023/03/01 23:51:39 by dayeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void print_banner() {
	ft_putstr_fd("            _       _     _          _ _ \n", 1);
	ft_putstr_fd("  _ __ ___ (_)_ __ (_)___| |__   ___| | |\n", 1);
	ft_putstr_fd(" | '_ ` _ \\| | '_ \\| / __| '_ \\ / _ \\ | |\n", 1);
	ft_putstr_fd(" | | | | | | | | | | \\__ \\ | | |  __/ | |\n", 1);
	ft_putstr_fd(" |_| |_| |_|_|_| |_|_|___/_| |_|\\___|_|_|\n", 1);
	ft_putstr_fd("                                         \n", 1);	
}

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
	print_banner();
	get_readline(&env, &sp);
	exit(0);
}
