/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:13:15 by daypark           #+#    #+#             */
/*   Updated: 2021/05/11 01:16:20 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(int c, t_info *info)
{
	int	i;

	i = 1;
	if (info->flags == '-')
		ft_putchar_fd(c, 1);
	while (i++ < info->width)
		ft_putchar_fd(' ', 1);
	if (info->flags != '-')
		ft_putchar_fd(c, 1);
}

void	print_s(char *str, t_info *info)
{
	int		n;
	char	*prt;
	int		i;

	i = 0;
	if (ft_strlen(str) > info->precision)
		n = info->precision;
	else
		n = ft_strlen(str);
	prt = (char *)malloc(sizeof(char) * n + 1); //실패시
	ft_strlcpy(prt, str, n + 1);
	if (n < info->width)
	{
		if (info->flags == '-')
			ft_putstr_fd(prt, 1);
		while (i++ < info->width - n)
			ft_putchar_fd(' ', 1);
		if (info->flags != '-')
			ft_putstr_fd(prt, 1);
	}
	else
		ft_putstr_fd(prt, 1);
	free(prt);
}

