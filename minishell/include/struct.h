/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawpark <jawpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:13:45 by jawpark           #+#    #+#             */
/*   Updated: 2021/12/18 09:59:33 by jawpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <termios.h>

typedef struct s_env
{
	char			**envp;
	int				exit_c;
	int				exit_n;
	int				i_fd;
	int				o_fd;
	char			**s_op;
	char			**d_eof;
	int				d_len;
	int				d_count;
	int				cat;
	struct termios	old_term;
	struct termios	new_term;
}					t_env;

typedef struct s_split
{
	char			**str;
	int				type;
	char			*quotes;
	char			**dollar;
	char			**c_vlaue;
	int				c_len;
	struct s_env	*e;
	struct s_split	*next;
}				t_split;

#endif
