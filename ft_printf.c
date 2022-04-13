/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:58:39 by hyojeong          #+#    #+#             */
/*   Updated: 2022/04/13 15:04:11 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>
#include <stdlib.h>

// flag option들을 지정해주는 함수
void	set_flag(char **str, t_flag *flag)
{
	const char	*format = "# +-0";

	while (ft_strchr(format, **str))
	{
		if (**str == '-')
			flag->left = 1;
		if (**str == '+')
			flag->plus = '+';
		if (**str == ' ')
			flag->plus = ' ';
		if (**str == '#')
			flag->hash = 1;
		if (**str == '0')
			flag->zero = 1;
		(*str)++;
	}
}

// 너비를 계산해주는 함수
void	set_width(char **str, t_flag *flag)
{
	const char	*format = "0123456789.";

	while (ft_strchr(format, **str))
	{
		if ((ft_strchr("0123456789", **str)) && (flag->precision == 0))
			flag->padding_left = (flag->padding_left * 10) + **str - '0';
		if (**str == '.')
			flag->precision = 1;
		if (ft_strchr("0123456789", **str) && (flag->precision == 1))
			flag->padding_right = (flag->padding_right * 10) + **str - '0';
		(*str)++;
	}
}

t_flag	make_flag(char **str)
{
	t_flag	flag;

	ft_memset(&flag, 0, sizeof(t_flag));
	set_flag(str, &flag);
	set_width(str, &flag);
	return (flag);
}

void	branch(va_list ap, const char **str, int *printf_len)
{
	t_flag	flag;

	(void)printf_len;
	flag = make_flag((char **)str);
	if (**str == 's')
		print_str(ap, &flag, printf_len);
	else if (**str == 'c')
		print_char(ap, &flag, printf_len);
	else if (**str == 'd' || **str == 'i' || **str == 'u' || **str == 'x' || **str == 'X')
	{
		if (**str == 'x')
			flag.hexa = 1;
		else if (**str == 'X')
			flag.hexa = 2;
		else if (**str == 'u')
			flag.unsign = 1;
		print_decimal(ap, &flag, printf_len);
	}
	else if (**str == '%')
	{
		write(1, "%", 1);
		(*printf_len)++;
	}
	else if (**str == 'p')
		print_pointer(ap, &flag, printf_len);
	(*str)++;
}
// 메인 함수
int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		printf_len;
	
	printf_len = 0;	
	if (str == 0)
		return (-1);
	va_start(ap, str);
	{
		while (*str)
		{
			if (!(*str == '%'))
			{
				write(1, str, 1);
				str++;
				printf_len++;
			}
			else
			{
				str++;
				branch(ap, &str, &printf_len);
			}
		}
	}
	va_end(ap);
	return (printf_len);
}
