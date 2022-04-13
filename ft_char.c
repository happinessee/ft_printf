/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 23:29:42 by hyojeong          #+#    #+#             */
/*   Updated: 2022/04/13 23:31:43 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>

void	ft_putchar(char c, int *printf_len)
{
	write(1, &c, 1);
	*printf_len += 1;
}

void	space_padding(long left, long right, int *printf_len)
{
	while (left > right)
	{
		write(1, " ", 1);
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
		space_padding(flag->padding_left, idx + 1, printf_len);
	}
	else
	{
		space_padding(flag->padding_left, idx + 1, printf_len);
		ft_putchar(c, printf_len);
	}
}
