/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:12:35 by hyojeong          #+#    #+#             */
/*   Updated: 2022/04/14 12:45:26 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>

static void	print_plusflag(t_flag flag, int *printf_len)
{
	if (flag.plus)
	{
		write(1, &flag.plus, 1);
		*printf_len += 1;
	}
}

static void	decide_func(t_flag flag, long num)
{
	if (flag.hexa == 2)
		ft_put_x(num, flag);
	else
		ft_putnbr(num, flag);
}

static void	is_precision(t_flag flag, long num, long len, int *printf_len)
{
	if (!flag.left)
	{
		padding(flag.padding_left, flag.padding_right, printf_len, ' ');
		print_plusflag(flag, printf_len);
		ft_hexa(num, flag, printf_len);
		padding(flag.padding_right, len, printf_len, '0');
		decide_func(flag, num);
	}
	else
	{
		print_plusflag(flag, printf_len);
		ft_hexa(num, flag, printf_len);
		padding(flag.padding_right, len, printf_len, '0');
		decide_func(flag, num);
		padding(flag.padding_left, flag.padding_right, printf_len, ' ');
	}
}

static void	is_general(t_flag flag, long num, long len, int *printf_len)
{
	if (!flag.left)
	{
		if (flag.zero)
			print_plusflag(flag, printf_len);
		ft_hexa(num, flag, printf_len);
		if (flag.zero)
			padding(flag.padding_left, len, printf_len, '0');
		else
			padding(flag.padding_left, len, printf_len, ' ');
		if (!(flag.zero))
			print_plusflag(flag, printf_len);
		decide_func(flag, num);
	}
	else
	{
		print_plusflag(flag, printf_len);
		ft_hexa(num, flag, printf_len);
		decide_func(flag, num);
		padding(flag.padding_left, len, printf_len, ' ');
	}
}

void	print_decimal(va_list ap, t_flag *flag, int *printf_len)
{
	long	num;
	long	len;

	num = adjust_num(ap, *flag);
	len = adjust_len_flag(num, flag);
	if (flag->precision)
		is_precision(*flag, num, len, printf_len);
	else
		is_general(*flag, num, len, printf_len);
	*printf_len += len;
}
