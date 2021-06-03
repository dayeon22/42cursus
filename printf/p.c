/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:11:51 by daypark           #+#    #+#             */
/*   Updated: 2021/06/03 18:15:02 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_len_p(unsigned long long n, int base, t_info *info)
{
	int	len;

	if (info->p < 0 && n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n = n / base;
		len++;
	}
	len = (info->p > len) ? info->p : len;
	return (len);
}

char	*p_to_s(int len, unsigned long long n, int base)
{
	int		i;
	char	*s;
	char	*b;

	if (!(s = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = len;
	s[i] = 0;
	b = _HEX_L;
	while (n)
	{
		s[--i] = b[n % base];
		n /= base;
	}
	while (i)
		s[--i] = '0';
	return (s);
}

int		ft_p(unsigned long long n, t_info *info)
{
	int		len;
	char	*s;
	char	*str;
	int		i;
	int		j;

	len = get_len_p(n, 16, info);
	if (!(s = p_to_s(len, n, 16)))
		return (0);
	if (!(str = (char *)malloc(sizeof(char) * len + 3)))
		return (0);
	i = 0;
	j = 0;
	str[i++] = '0';
	str[i++] = 'x';
	while (s[j])
		str[i++] = s[j++];
	str[i] = 0;
	len += 2;
	free(s);
	return (print_diuxp(str, len, info, 0));
}
