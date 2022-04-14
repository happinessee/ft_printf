/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 23:29:42 by hyojeong          #+#    #+#             */
/*   Updated: 2022/04/14 11:09:10 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>

void	ft_putchar(char c, int *printf_len)
{
	write(1, &c, 1);
	*printf_len += 1;
}

void	padding(long left, long right, int *printf_len, int c)
{
	while (left > right)
	{
		write(1, &padding, 1);
		(*printf_len)++;
		right++;
	}
}

void	print_char(va_list ap, t_flag *flag, int *printf_len)
{
	char	c;
	long	idx;

	idx = 0;
	c = va_arg(ap, int);
	if (flag->left)
	{
		ft_putchar(c, printf_len);
		padding(flag->padding_left, idx + 1, printf_len, ' ');
	}
	else
	{
		padding(flag->padding_left, idx + 1, printf_len, ' ');
		ft_putchar(c, printf_len);
	}
}
