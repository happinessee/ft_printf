/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:12:35 by hyojeong          #+#    #+#             */
/*   Updated: 2022/04/01 15:50:54 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(va_list ap, int flag)
{
	long		nb;
	const char	*hexa = "0123456789abcdef";
	int			mod;

	nb = va_arg(ap, long);
	if (flag)
		mod = 16;
	else
		mod = 10;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= mod)
		ft_putnbr(nb / mod, flag);
	write(1, &hexa[nb % mod], 1);
}
