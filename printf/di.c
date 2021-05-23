/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:11:51 by daypark           #+#    #+#             */
/*   Updated: 2021/05/23 18:06:32 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h> //지우기

int		get_len(int n, int base, t_info *info)
{
	int	len;
	int	temp;

	temp = n;
	len = 0;
	while (temp)
	{
		temp = temp / base;
		len++;
	}
	len = (info->precision > len) ? info->precision : len;
	len += (n < 0) ? 1 : 0;
	len = (info->precision == -1 && n == 0) ? 1 : len;
	return (len);
}

char	*i_to_s(int len, int n, int base)
{
	int		i;
	char	*s;
	int		temp;

	s = (char *)malloc(sizeof(char) * len + 1); //free(다쓰고), 실패처리
	i = len;
	s[i] = 0;
	temp = n < 0 ? -n : n;
	while (temp)
	{
		s[--i] = (temp % base) + '0';
		temp /= base;
	}
	while (i)
		s[--i] = '0';
	if (n < 0)
		s[0] = '-';
	return (s);
}

int		ft_di(int n, t_info *info)
{
	int		len;
	char	*s;
	int		base;

	base = 10;
	if (info->type == 'u')
		base = 8;
	if (info->type == 'p' || info->type == 'x' || info->type == 'X')
		base = 16;
	len = get_len(n, base, info);
	s = i_to_s(len, n, base);
	
	return (print_di(n, s, len, info));
}

int		print_di(int n, char *s, int len, t_info *info)
{
	int	i;
	n = 0;

	i = 0;
	if (len < info->width)
	{
		if (info->flags == '-')
			ft_putstr_fd(s, 1);
		while (i++ < info->width - len)
		{
			if (info->flags == '0' && info->precision == -1)
				ft_putchar_fd('0', 1);
			else if (info->flags == '0' && i == 1 && n < 0)
				ft_putchar_fd('-', 1);
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