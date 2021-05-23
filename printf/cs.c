/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:13:15 by daypark           #+#    #+#             */
/*   Updated: 2021/05/21 20:22:19 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h> //지우기

int	ft_c(int c, t_info *info)
{
	int	i;
	int ret;

	i = 0;
	ret = 0;
	if (info->flags == '-')
		ft_putchar_fd(c, 1);
	while (++i < info->width)
	{
		ft_putchar_fd(' ', 1);
		ret++;
	}
	if (info->flags != '-')
		ft_putchar_fd(c, 1);
	return (ret + 1);
}

int	ft_s(char *str, t_info *info)
{
	int		len;
	char	*prt;
	int		i;

	if (!str)
		str = "(null)";
	i = 0;
	len = ft_strlen(str);
	if (0 <= info->precision && len > info->precision)
		len = info->precision;
	prt = (char *)malloc(sizeof(char) * len + 1); //실패시
	ft_strlcpy(prt, str, len + 1);
	if (len < info->width)
	{
		if (info->flags == '-')
			ft_putstr_fd(prt, 1);
		while (i++ < info->width - len)
			info->flags != '0' ? ft_putchar_fd(' ', 1) : ft_putchar_fd('0', 1);
		if (info->flags != '-')
			ft_putstr_fd(prt, 1);
	}
	else
		ft_putstr_fd(prt, 1);
	free(prt);
	return (len < info->width ? info->width : len);
}
