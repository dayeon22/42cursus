/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:11:51 by daypark           #+#    #+#             */
/*   Updated: 2021/05/18 19:02:53 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_len(int n, t_info *info)
{
	int		base;
	int		cnt;
	int		tmp;
	char	*s;

	cnt = 0;
	base = 10;
	if (info->t == 'u')
		base = 8;
	tmp = n;
	while (tmp)
	{
		tmp = tmp / base;
		cnt++;
	}
	if (cnt < info->precision)
		cnt = info->precision;
	i_to_s(cnt, n, s);
	print_di(s, cnt, info);
}

void	i_to_s(int jari, int n, char *s)
{
	int	i;

	s = (char *)malloc(sizeof(char) * jari + 1); //free(다쓰고)
	i = jari - 1;
	s[jari] = 0;
	while (n)
	{
		s[i--] = n % 10;
		n /= 10;
	}
	while (i)
		s[i--] = '0';
}


void	print_di(char *s, int n, t_info *info)
{
	if (n < info->width)
	{
		if (info->flags == '-')
			fd_putstr_fd(s, 1);
		while (i++ < info->width - n)
		{
			if (info->flags == '0' && info->flags != '-')
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
		}
		if (info->flags != '-')
			ft_putstr_fd(s, 1);
	}
	else
		ft_putstr_fd(s, 1);
}
