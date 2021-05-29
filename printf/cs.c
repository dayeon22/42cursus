/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:13:15 by daypark           #+#    #+#             */
/*   Updated: 2021/05/29 16:30:26 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_c(int c, t_info *info)
{
	int	i;

	i = 0;
	if (info->f == '-')
		ft_putchar_fd(c, 1);
	while (++i < info->w)
		info->f != '0' ? ft_putchar_fd(' ', 1) : ft_putchar_fd('0', 1);
	if (info->f != '-')
		ft_putchar_fd(c, 1);
	return (info->w > 1 ? info->w : 1);
}

int	ft_s(char *str, t_info *info)
{
	int		len;
	char	*prt;
	int		i;

	if (!str)
		str = "(null)";
	i = 0;
	len = (0 <= info->p && (int)ft_strlen(str) > info->p) ?\
		info->p : ft_strlen(str);
	if (!(prt = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	ft_strlcpy(prt, str, len + 1);
	if (len < info->w)
	{
		if (info->f == '-')
			ft_putstr_fd(prt, 1);
		while (i++ < info->w - len)
			info->f != '0' ? ft_putchar_fd(' ', 1) : ft_putchar_fd('0', 1);
		if (info->f != '-')
			ft_putstr_fd(prt, 1);
	}
	else
		ft_putstr_fd(prt, 1);
	free(prt);
	return (len < info->w ? info->w : len);
}
