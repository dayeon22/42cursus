/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:23:49 by daypark           #+#    #+#             */
/*   Updated: 2021/05/07 10:34:54 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void init_info(t_info *info)
{
	info->flags = 0;
	info->width = 0;
	info->precision = 0;
	info->type = 0;
}

//문제점
//1. width와 precision이 한 자리 수가 아닐 때
//	width와 precision이 있다는것만 체크해두고 나중에 처리한다.
//2. 만약 width와 precision을 여기서 처리했을 때 포인터를 자릿수만큼 이동해야 하는데 그걸어떻게해
//3. 아님 put_fwp를 하나하나 호출하지 말고 한번에 다 처리해버리기?
/*
void set_fwp(char *fmt, t_info *info)
{
	//flags
	if (*fmt == '0' && !(info->flags == '-')) //precision도 0이 올수 있으니 걸러야함
		info->flags = '0';
	else if (*fmt == '-' || (*fmt == '0' && info->flags == '-'))
		info->flags = '-';

	//width
	else if ('1' <= *fmt && *fmt <= '9')
		info->width = width * 10 + *fmt - '0';

	//precision
	else if (*fmt == '.')
	{
		fmt++;
		if ('0' <= *fmt && *fmt <= '9')
			info->precision = precision * 10 + *fmt - '0';
	}
}
*/
void set_fwp(char *str, t_info *info)
{

}

//int	find_pct(char *fmt, t_info *info, va_list *ap)
void	find_pct(char *fmt, t_info *info)
{
	int	i;
	int j;
	char *str;
	int cnt;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] && fmt[i] == '%')
		{
			init_info(info);
			j = 0;
			cnt = 0;
			while (fmt[++i] && !(ft_strchr("cspdiuxX", fmt[i])))
				cnt++
			str = (char *)malloc(sizeof(char) * cnt + 1); //동적할당 실패시 뭘 리턴할지
			i -= cnt;
			while (j < cnt) //줄이 부족하면 위 while문을 그대로 가져다 쓰기(대신 속도 느려짐)
				str[j++] = str[i++];
			set_fwp(str, info);

			//type을 넣어주기
			info->type = fmt[i++];
			//여기서 info를 참고해 가변인자를 출력하는 함수를 호출하면 될 듯!
		}
		i++;
	}
}

// 일단 리턴 없이 출력만 하느라 void형인데
// 나중에 출력 길이만큼 리턴해주고 함수의 리턴형을 int로 바꾸기
// t_info 인자를 받는 것도 main함수에서 테스트를 하기 위함이니 나중에 지우기
void	ft_printf(t_info *info, const char *fmt, ...)
{
//	t_info	info;
	va_list	ap;
	//int		ret;

	va_start(ap, fmt);
	find_pct((char *)fmt, info);
	va_end(ap);
	//return (ret);
}

#include <stdio.h>
int main()
{
	t_info info;

	ft_printf(&info, "%4.6d", 123);
	printf("flags:%c, width:%d, precision:%d, type:%c\n", info.flags, info.width, info.precision, info.type);
}
