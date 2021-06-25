/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diux.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:11:51 by daypark           #+#    #+#             */
/*   Updated: 2021/06/04 15:32:11 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_len(unsigned int n, int base, t_info *in, int m)
{
	int				len;
	unsigned int	temp;

	len = 0;
	temp = n;
	while (temp)
	{
		temp = temp / base;
		len++;
	}
	len = (in->p > len) ? in->p : len;
	len += m && ((in->f == '0' && in->p < 0) || in->f != '0' || in->w <= len);
	len = (in->p < 0 && n == 0) ? 1 : len;
	return (len);
}

int		i_to_s(unsigned int n, int base, t_info *in, int m)
{
	int		i;
	char	*s;
	char	*b;
	int		len;

	len = get_len(n, base, in, m);
	if (!(s = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	i = len;
	s[i] = 0;
	b = _DEC;
	if (in->t == 'x')
		b = _HEX_L;
	else if (in->t == 'X')
		b = _HEX_U;
	while (n)
	{
		s[--i] = b[n % base];
		n /= base;
	}
	while (i)
		s[--i] = '0';
	if (m && ((in->f != '0' && in->p < 0) || in->f != '0' || in->w <= len))
		s[0] = '-';
	return (print_diuxp(s, len, in, m));
}

int		ft_di(int n, t_info *in)
{
	int		m;

	m = 0;
	if (n < 0)
	{
		m = 1;
		n *= -1;
	}
	return (i_to_s(n, 10, in, m));
}

int		ft_ux(unsigned int n, t_info *in)
{
	int		base;

	base = 10;
	if (in->t == 'x' || in->t == 'X')
		base = 16;
	return (i_to_s(n, base, in, 0));
}

int		print_diuxp(char *s, int l, t_info *in, int m)
{
	int	i;

	i = 0;
	if (l < in->w)
	{
		if (in->f == '-')
			ft_putstr_fd(s, 1);
		while (i++ < in->w - l)
		{
			if (i == in->w - l && m && in->f == '0' && in->p >= 0)
				ft_putchar_fd('-', 1);
			else if (i == 1 && m && in->f == '0' && in->p < 0)
				ft_putchar_fd('-', 1);
			else if (in->f == '0' && in->p < 0)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
		}
		if (in->f != '-')
			ft_putstr_fd(s, 1);
	}
	else
		ft_putstr_fd(s, 1);
	free(s);
	return (l < in->w ? in->w : l);
}
