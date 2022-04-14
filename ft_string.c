/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:17:47 by hyojeong          #+#    #+#             */
/*   Updated: 2022/04/14 11:10:02 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>

void	ft_putstr(char *str, long len, int *printf_len)
{
	if (str == 0)
	{
		write(1, "(null)", len);
		*printf_len += len;
		return ;
	}
	write(1, str, len);
	*printf_len += len;
}

static long	set_len_precision(t_flag *flag, char *str)
{
	long	len;

	len = ft_strlen(str);
	if (str == 0)
	{
		if (flag->precision)
		{
			if (flag->padding_right < 7)
				len = flag->padding_right;
			else
			{
				len = 6;
				flag->padding_right = 6;
			}
		}
		else
			len = 6;
	}
	if (str && flag->padding_right > len)
		flag->padding_right = len;
	return (len);
}

static void	is_precision(t_flag flag, char *str, int *printf_len)
{
	if (flag.left)
	{
		if (flag.padding_right > 0)
			ft_putstr(str, flag.padding_right, printf_len);
		padding(flag.padding_left, flag.padding_right, printf_len, ' ');
	}
	else
	{
		padding(flag.padding_left, flag.padding_right, printf_len, ' ');
		if (flag.padding_right > 0)
			ft_putstr(str, flag.padding_right, printf_len);
	}
}

static void	is_general(t_flag flag, char *str, long len, int *printf_len)
{
	if (flag.left)
	{
		if (flag.padding_left < len)
			ft_putstr(str, len, printf_len);
		else
		{
			ft_putstr(str, len, printf_len);
			padding(flag.padding_left, 0, printf_len, ' ');
		}
	}
	else
	{
		if (flag.padding_left < len)
			ft_putstr(str, len, printf_len);
		else
		{
			padding(flag.padding_left, 0, printf_len, ' ');
			ft_putstr(str, len, printf_len);
		}
	}
}

void	print_str(va_list ap, t_flag *flag, int *printf_len)
{
	char	*str;
	long	len;

	str = va_arg(ap, char *);
	len = set_len_precision(flag, str);
	if (flag->precision)
		have_precision(*flag, str, printf_len);
	else
		is_general(*flag, str, len, printf_len);
}
