/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:50:02 by hyojeong          #+#    #+#             */
/*   Updated: 2022/04/08 21:13:30 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>

void	print_pointer(va_list ap, t_flag *flag)
{
	unsigned char	*ptr;
	size_t	idx;
	int		cnt;
	
	cnt = 0;
	ptr = va_arg(ap, unsigned char *);
	write(1, "0x", 2);
	idx = 2;
	if (!(flag->minus))
	{
		while (flag->padding_left > 12 + idx)
		{
			write(1, " ", 1);
			idx++;
		}
		while (cnt < 6)
		{
			ft_putnbr(*ptr, 1);
			ptr++;
			cnt++;
		}
	}
	else
	{
		while (cnt < 6)
		{
			ft_putnbr(*ptr, 1);
			ptr++;
			cnt++;
		}
		while (flag->padding_left > 12 + idx)
		{
			write(1, " ", 1);
			idx++;
		}
	}
}