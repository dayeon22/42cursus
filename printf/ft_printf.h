/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:22:58 by daypark           #+#    #+#             */
/*   Updated: 2021/06/03 17:30:37 by daypark          ###   ########.fr       */
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
	char		f;
	int			w;
	int			p;
	char		t;
}				t_info;

int				ft_printf(const char *fmt, ...);
int				find_pct(char *fmt, t_info *info, va_list ap);
int				print_by_type(va_list ap, t_info *info);
int				make_str(int idx, char *fmt, t_info *info, va_list ap);

void			set_init(t_info *info);
void			set_wp(char *s, t_info *info, va_list ap, int i);
void			set_f(char *str, t_info *info, va_list ap);
void			asterisk(char *str, t_info *info, va_list ap);

int				ft_c(int c, t_info *info);
int				ft_s(char *str, t_info *info);

int				ft_di(int n, t_info *info);
int				ft_ux(unsigned int n, t_info *info);
int				get_len(unsigned int n, int base, t_info *info, int m_flag);
int				i_to_s(unsigned int n, int base, t_info *info, int m_flag);
int				print_diuxp(char *s, int len, t_info *info, int m_flag);

int				ft_p(unsigned long long n, t_info *info);
int				get_len_p(unsigned long long n, int base, t_info *info);
char			*p_to_s(int len, unsigned long long n, int base);

#endif
