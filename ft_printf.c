/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:58:39 by hyojeong          #+#    #+#             */
/*   Updated: 2022/04/06 17:24:55 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>

void	set_flag(va_list ap, char **str, int *printf_len, t_flag *flag)
{
	const char	*format = "# +-0";

	while (ft_strchr(format, *str))
	{
		if (*str == '-')
			flag->left = 1;
		if (*str == '+')
			flag->plus = 1;
		if (*str == ' ')
			flag->plus = 2;
		if (*str == '#')
			flag->hash = 1;
		if (*str == '0')
			flag->zero = 1;
		(*str)++;
	}
}

void	set_width(va_list ap, char **str, int *printf_len, t_flag *flag)
{
	const char	*format = "123456789.";
	int	right;

	right = 0;
	while (ft_strchr(format, *str))
	{
		if ((ft_strchr("123456789", *str)) && (right == 0))
			flag->padding_left = *str - '0';
		if (*str == '.')
			right = 1;
		if (ft_strchr("123456789") && (right == 1))
			flag->padding_right = *str - '0';
		(*str)++;
	}
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
