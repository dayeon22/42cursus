/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:23:49 by daypark           #+#    #+#             */
/*   Updated: 2021/05/29 19:36:05 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_by_t(va_list ap, t_info *info)
{
	if (info->t == 'c')
		return (ft_c(va_arg(ap, int), info));
	else if (info->t == 's')
		return (ft_s(va_arg(ap, char *), info));
	else if (info->t == 'd' || info->t == 'i')
		return (ft_di(va_arg(ap, int), info));
	else if (info->t == 'x' || info->t == 'X' || info->t == 'u')
		return (ft_ux(va_arg(ap, unsigned int), info));
	else if (info->t == 'p')
		return (ft_p(va_arg(ap, unsigned long long), info));
	else if (info->t == '%')
		return (ft_c('%', info));
	return (0);
}

void	make_str(int idx, char *fmt, t_info *info, va_list ap)
{
	char	*str;
	int		i;

	i = idx;
	while (fmt[i] && !(ft_strchr("cspdiuxX%", fmt[i])))
		i++;
	init_info(info);
	if (!(str = (char *)malloc(sizeof(char) * i - idx + 1)))
		return ;
	ft_strlcpy(str, &fmt[idx], i - idx + 1);
	set_f(str, info, ap);
	free(str);
}

int		find_pct(char *fmt, t_info *info, va_list ap)
{
	int		i;
	int		idx;
	int		ret;

	i = -1;
	ret = 0;
	while (fmt[++i])
	{
		if (fmt[i] == '%')
		{
			idx = ++i;
			while (fmt[i] && !(ft_strchr("cspdiuxX%", fmt[i])))
				i++;
			make_str(idx, fmt, info, ap);
			if (!fmt[i])
				break ;
			info->t = fmt[i];
			ret += print_by_t(ap, info);
		}
		else
			ret += ft_putchar_fd(fmt[i], 1);
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
