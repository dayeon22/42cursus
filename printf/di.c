/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:11:51 by daypark           #+#    #+#             */
/*   Updated: 2021/05/26 16:04:51 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h> //지우기

int		get_len(unsigned int n, int base, t_info *info, int m_flag)
{
	int	len;
	unsigned int temp;

	len = 0;
	temp = n;
	while (temp)
	{
		temp = temp / base;
		len++;
	}
	len = (info->precision > len) ? info->precision : len;
	len += m_flag && ((info->flags == '0' && info->precision == -1) || info->flags != '0' || info->width <= len);
	len = (info->precision == -1 && n == 0) ? 1 : len;
	return (len);
}

char	*i_to_s(int len, unsigned int n, int base, t_info *info, int m_flag)
{
	int		i;
	char	*s;
	char	*b;

	s = (char *)malloc(sizeof(char) * len + 1); //free(다쓰고), 실패처리
	i = len;
	s[i] = 0;
	b = _DEC;
	if (info->type == 'x' || info->type == 'p')
		b = _HEX_L;
	else if (info->type == 'X')
		b = _HEX_U;
	while (n)
	{
		s[--i] = b[n % base];
		n /= base;
	}
	while (i)
		s[--i] = '0';
	if (m_flag && ((info->flags != '0' && info->precision == -1) || info->flags != '0' || info->width <= len))
		s[0] = '-';
	return (s);
}

int		ft_di(int n, t_info *info)
{
	int		len;
	char	*s;
	int		base;
	int		m_flag;

	base = 10;
	m_flag = 0;
	if (n < 0)
	{
		m_flag = 1;
		n *= -1;
	}
	len = get_len(n, base, info, m_flag);
	s = i_to_s(len, n, base, info, m_flag);
	return (print_di(s, len, info, m_flag));
}

int		ft_ux(unsigned int n, t_info *info)
{
	int		len;
	char	*s;
	int		base;
	int		m_flag;

	m_flag = 0;
	base = 10;
	if (info->type == 'x' || info->type == 'X')
		base = 16;
	len = get_len(n, base, info, m_flag);
	s = i_to_s(len, n, base, info, m_flag);
	return (print_di(s, len, info, m_flag));
}



int		print_di(char *s, int len, t_info *info, int m_flag)
{
	int	i;

	i = 0;
	if (len < info->width)
	{
		if (info->flags == '-')
			ft_putstr_fd(s, 1);
		while (i++ < info->width - len)
		{
			if  (i == 1 && m_flag && info->flags == '0' && info->precision == -1 && info->width > len)
				ft_putchar_fd('-', 1);
			else if (i == info->width - len && m_flag && info->flags == '0' && info->precision >= 0 && info->width > len)
				ft_putchar_fd('-', 1);
			else if (info->flags == '0' && info->precision == -1)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
		}
		if (info->flags != '-')
			ft_putstr_fd(s, 1);
	}
	else
		ft_putstr_fd(s, 1);
	return (len < info->width ? info->width : len); //삼항연산자
}
