/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:22:58 by daypark           #+#    #+#             */
/*   Updated: 2021/05/07 10:34:56 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct	s_info
{
	char		flags;
	int			width;
	int			precision;
	char		type;
}				t_info;

void	ft_printf(t_info *info, const char *fmt, ...);
void	find_pct(char *fmt, t_info *info);
void	set_fwp(char *fmt, t_info *info);
void	init_info(t_info *info);

#endif
