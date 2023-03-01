/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:13:39 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/18 09:59:19 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <sys/stat.h>
# include <string.h>
# include <fcntl.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "./struct.h"
# include "./functions.h"
# define CHAR_PIPE -1
# define CHAR_LESS -2
# define CHAR_DLESS -3
# define CHAR_GREAT -4
# define CHAR_DGREAT -5
# define CHAR_WORD -6
# define PWD_SIZE 1024

#endif
