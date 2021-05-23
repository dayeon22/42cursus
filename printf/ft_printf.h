/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:22:58 by daypark           #+#    #+#             */
/*   Updated: 2021/05/23 18:06:04 by daypark          ###   ########.fr       */
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

//ft_printf.c
//int		ft_printf(t_info *info, const char *fmt, ...);
int		ft_printf(const char *fmt, ...);
int		find_pct(char *fmt, t_info *info, va_list *ap);
void	set_fwp(char *fmt, t_info *info);
int		print_by_type(va_list *ap, t_info *info);
void	init_info(t_info *info);

//print_cs.c
int		ft_c(int c, t_info *info);
int		ft_s(char *str, t_info *info);

//print_di.c
int		ft_di(int n, t_info *info);
int		get_len(int n, int base, t_info *info);
char	*i_to_s(int len, int n, int base);
int		print_di(int n, char *s, int len, t_info *info);

//void	ft_ux(unsigned int n, t_info *info);
//void	ft_p(unsigned long long n, t_info *info);

//int		add_minus(char **s, int n, t_info *info);

#endif