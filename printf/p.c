#include "ft_printf.h"

int		get_len_p(unsigned long long n, int base, t_info *info)
{
	int	len;
	unsigned long long temp;

	len = 0;
	temp = n;
	while (temp)
	{
		temp = temp / base;
		len++;
	}
	len = (info->precision > len) ? info->precision : len;
	len = (info->precision == -1 && n == 0) ? 1 : len;
	return (len);
}

char	*p_to_s(int len, unsigned long long n, int base)
{
	int		i;
	char	*s;
	char	*b;

	s = (char *)malloc(sizeof(char) * len + 1); //free(다쓰고), 실패처리
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

	len = get_len_p(n, 16, info);
	s = p_to_s(len, n, 16);
	str = (char *)malloc(sizeof(char) * len + 3);
	i = 0;
	str[i++] = '0';
	str[i++] = 'x';
	while (*s)
		str[i++] = *s++;
	str[i] = 0;
	len += 2;
	return (print_di(str, len, info, 0));
}
