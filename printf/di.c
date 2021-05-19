/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:11:51 by daypark           #+#    #+#             */
/*   Updated: 2021/05/19 21:12:47 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h> //지우기

int		get_len(int n, int base) //이걸 걍 i_to_s에 합쳐버리기?(합칠 때 ft_di 주의)
{
	int		len;

	len = 0;
	while (n)
	{
		n = n / base;
		len++;
	}
	return (len);
}

char	*i_to_s(int len, int n, int base)
{
	int		i;
	char	*s;

	s = (char *)malloc(sizeof(char) * len + 1); //free(다쓰고), 실패처리
	i = len;
	s[i] = 0;
	if (n < 0)
		n *= -1;
	while (n)
	{
		s[--i] = (n % base) + '0';
		n /= base;
	}
	while (i)
		s[--i] = '0';
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
	len = get_len(n, base);
	if (n < 0)
		len++;
	if (len < info->precision)
		len = info->precision;
	s = i_to_s(len, n, base);
	if (n < 0)
		s[0] = '-';
	return (print_di(s, len, info));
}

int		print_di(char *s, int len, t_info *info)
{
	int	i;
	int	ret;

	i = 0;
	if (len < info->width)
	{
		if (info->flags == '-')
			ft_putstr_fd(s, 1);
		while (i++ < info->width - len)
		{
			if (info->flags == '0' && info->flags != '-')
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
		}
		if (info->flags != '-')
			ft_putstr_fd(s, 1);
		ret = info->width;
	}
	else
		ft_putstr_fd(s, 1);
	return (len < info->width ? info->width : len); //삼항연산자
}