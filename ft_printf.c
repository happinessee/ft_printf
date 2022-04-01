/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:58:39 by hyojeong          #+#    #+#             */
/*   Updated: 2022/04/01 14:34:23 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdarg.h>

int	format(char *str, va_list ap, int *printf_len)
{

	return (1);
}

int branch(char *str, va_list ap, int *printf_len)
{
	t_list	option;

	ft_memset(option, 0,)
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		printf_len;

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
