/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:11:51 by daypark           #+#    #+#             */
/*   Updated: 2021/05/29 19:36:54 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_info(t_info *info)
{
	info->f = 0;
	info->w = -1;
	info->p = -1;
	info->t = 0;
}

void	set_f(char *s, t_info *info, va_list ap)
{
	int	i;
	int minus;

	i = 0;
	minus = 0;
	while (s[i] == '-' || s[i] == '0')
	{
		if (s[i++] == '0')
			info->f = '0';
		else
			minus = 1;
	}
	if (minus)
		info->f = '-';
	set_wp(s, info, ap, i);
}

void	set_wp(char *s, t_info *info, va_list ap, int i)
{
	int		n;

	n = 0;
	while (ft_isdigit(s[i]) || s[i] == '.' || s[i] == '*' || s[i] == ' ')
	{
		if (s[i] == '.')
		{
			info->w = n;
			n = 0;
		}
		else if (ft_isdigit(s[i]))
			n = n * 10 + s[i] - '0';
		i++;
	}
	if (ft_strchr(s, '.'))
		info->p = n;
	else
		info->w = n;
	asterisk(s, info, ap);
}

void	asterisk(char *s, t_info *info, va_list ap)
{
	int		i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '*')
		{
			if (i != 0 && s[i - 1] == '.')
			{
				info->p = va_arg(ap, int);
				if (info->p < 0)
					info->p = -1;
			}
			else
			{
				info->w = va_arg(ap, int);
				if (info->w < 0)
				{
					info->f = '-';
					info->w *= -1;
				}
			}
		}
	}
}
