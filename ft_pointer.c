/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:50:02 by hyojeong          #+#    #+#             */
/*   Updated: 2022/04/12 12:20:53 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>

void	print_pointer(va_list ap, t_flag *flag)
{
	unsigned long	ptr;
	size_t	idx;
	int		cnt;
	
	cnt = 0;
	ptr = (unsigned long)va_arg(ap, void *);
	idx = 2;
	if (!(flag->minus))
	{
		while (flag->padding_left > 7 + idx) // 수수정  필필요요
		{
			write(1, " ", 1);
			idx++;
		}
		while (get_numlen(ptr, 1) + idx < 10)
		{
			write(1, "0", 1);
			idx++;
		}
		write(1, "0x", 2);
		ft_putnbr((ptr), 1);
		cnt++;
	}
	else
	{
		while (get_numlen(ptr, 1) + idx < 10)
		{
			write(1, "0", 1);
			idx++;
		}
		write(1, "0x", 2);
		ft_putnbr(ptr, 1);
		cnt++;
		while (flag->padding_left > 7 + idx)	// 수수정  필필요요
		{
			write(1, " ", 1);
			idx++;
		}
	}
}
