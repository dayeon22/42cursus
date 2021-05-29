/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:22:58 by daypark           #+#    #+#             */
/*   Updated: 2021/05/29 05:33:48 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define _DEC "0123456789"
# define _HEX_U "0123456789ABCDEF"
# define _HEX_L "0123456789abcdef"

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
int		find_pct(char *fmt, t_info *info, va_list ap);
void	set_fwp(char *fmt, t_info *info, va_list *ap);
int		print_by_type(va_list *ap, t_info *info);
void	init_info(t_info *info);

//print_cs.c
int		ft_c(int c, t_info *info);
int		ft_s(char *str, t_info *info);

//print_di.c
int		ft_di(int n, t_info *info);
int		get_len(unsigned int n, int base, t_info *info, int m_flag);
char	*i_to_s(int len, unsigned int n, int base, t_info *info, int m_flag);
int		print_di(char *s, int len, t_info *info, int m_flag);

int		ft_ux(unsigned int n, t_info *info);

int		get_len_p(unsigned long long n, int base, t_info *info);
char	*p_to_s(int len, unsigned long long n, int base);
int		ft_p(unsigned long long n, t_info *info);

void	asterisk(char *str, t_info *info, va_list *ap);
#endif
