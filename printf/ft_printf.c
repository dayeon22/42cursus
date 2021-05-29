/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:23:49 by daypark           #+#    #+#             */
/*   Updated: 2021/05/29 15:20:30 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h> //지우기!!

void init_info(t_info *info)
{
	info->flags = 0;
	info->width = -1;
	info->precision = -1;
	info->type = 0;
}

void	set_fwp(char *str, t_info *info, va_list ap)
{
	int	i;
	int minus;
	int n;
	
	i = 0;
	minus = 0;
	while (str[i] == '-' || str[i] == '0') //여기 뭔가 간단하게 고칠 수 있을 듯
	{
		if (str[i++] == '0')
			info->flags = '0';
		else
			minus = 1;
	}
	if (minus)
		info->flags = '-';
	n = 0;
	while (ft_isdigit(str[i]) || str[i] == '.' || str[i] == '*' || str[i] == ' ')
	{
		if (str[i] == '.')
		{
			info->width = n;
			n = 0;
		}
		else if (ft_isdigit(str[i]))
			n = n * 10 + str[i] - '0';
		i++;
	}
	if (ft_strchr(str, '.'))
		info->precision = n;
	else
		info->width = n;
	asterisk(str, info, ap);
}

void asterisk(char *str, t_info *info, va_list ap)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '*')
		{
			if (i != 0 && str[i - 1] == '.')
			{
				info->precision = va_arg(ap, int);
				if (info->precision < 0)
					info->precision = -1;
			}
			else
			{
				info->width = va_arg(ap, int);
				if (info->width < 0)
				{
					info->flags = '-';
					info->width *= -1;
				}
			}
		}
		i++;
	}
}

int		print_by_type(va_list ap, t_info *info)
{
	if (info->type == 'c')
		return (ft_c(va_arg(ap, int), info));
	else if (info->type == 's')
		return (ft_s(va_arg(ap, char *), info));
	else if (info->type == 'd' || info->type == 'i')
		return (ft_di(va_arg(ap, int), info));
	else if (info->type == 'x' || info->type == 'X' || info->type == 'u')
		return (ft_ux(va_arg(ap, unsigned int), info));
	else if (info->type == 'p')
		return (ft_p(va_arg(ap, unsigned long long), info));
	else if (info->type == '%')
		return (ft_c('%', info));
	return (0);
}

int		find_pct(char *fmt, t_info *info, va_list ap)
{
	int	i;
	char *str;
	int idx;
	int ret;

	i = -1;
	ret = 0;
	while (fmt[++i])
	{
		if (fmt[i] == '%')
		{
			init_info(info);
			idx = ++i;
			while (fmt[i] && !(ft_strchr("cspdiuxX%", fmt[i])))
				i++;
			if (!(str = (char *)malloc(sizeof(char) * i - idx + 1)))
				return (0);
			ft_strlcpy(str, &fmt[idx], i - idx + 1);
			set_fwp(str, info, ap);
			free(str);
			if (!fmt[i])
				break;
			info->type = fmt[i];	
			ret += print_by_type(ap, info);
		}
		else
		{
			ft_putchar_fd(fmt[i], 1); //함수 리턴값을 1로 바꾸고 ret+=ft어쩌고
			ret++;
		}
	}
	return (ret);
}

int		ft_printf(const char *fmt, ...)
{
	t_info	info;
	va_list	ap;
	int		ret;

	va_start(ap, fmt);
	ret = find_pct((char *)fmt, &info, ap);
	va_end(ap);
	return (ret);
}