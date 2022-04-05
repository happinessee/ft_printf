/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:58:39 by hyojeong          #+#    #+#             */
/*   Updated: 2022/04/05 12:47:44 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format(char *str, va_list ap, int *printf_len)
{
	if (*str == "c")
		return (ft_putchar(ap));
	else if (*str == "s")
		return (ft_putstr(ap));
	else if (*str == "p")
		return (ft_putpoint(ap));
	else if (*str == "d")
		return (ft_putnum(ap));
	else if (*str == "x" || *str == "X")
		return (ft_putnum(ap));
	return (1);
}

int branch(char *str, va_list ap, int *printf_len)
{
	t_flag	option;

	option = {0, };
	while (!(str == 'd'))
	{
		if (str == ' ')
			option.space = 1;
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		printf_len;
	t_flag	flag;
	
	printf_len = 0;
	if (str == 0)
		return (-1);
	va_start(ap, str);
	{
		while (str)
		{
			if (!(str == '%'))
			{
				write(1, str, 1);
				str++;
				printf_len++;
			}
			else
			{
				str++;
				branch(ap, str, &printf_len);
			}
		}
	}
	va_end(ap);
	return (printf_len);
}
