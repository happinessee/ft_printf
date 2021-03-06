/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:30:26 by hyojeong          #+#    #+#             */
/*   Updated: 2022/04/27 11:38:32 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>

size_t	get_numlen(long num, int flag)
{
	size_t	len;
	int		mod;

	len = 0;
	mod = 10;
	if (flag)
		mod = 16;
	if (num == 0)
		len = 1;
	while (!(num == 0))
	{
		num = num / mod;
		len++;
	}
	return (len);
}

void	ft_putnbr(long num, t_flag flag)
{
	const char		*hexanum = "0123456789abcdef";
	long			nb;
	int				mod;

	nb = num;
	if (nb == 0 && flag.precision && flag.padding_right == 0)
		return ;
	mod = 10;
	if (flag.hexa)
		mod = 16;
	if (nb < 0)
		nb *= -1;
	if (nb >= mod)
	{
		ft_putnbr(nb / mod, flag);
	}
	write(1, &hexanum[(nb % mod)], 1);
}

void	ft_put_x(unsigned int num, t_flag flag)
{
	const char	*hexanum = "0123456789ABCDEF";
	long		nb;
	int			mod;

	nb = num;
	if (nb == 0 && flag.precision && flag.padding_right == 0)
		return ;
	mod = 10;
	if (flag.hexa)
		mod = 16;
	if (nb < 0)
		nb *= -1;
	if (nb >= mod)
	{
		ft_put_x(nb / mod, flag);
	}
	write(1, &hexanum[(nb % mod)], 1);
}

long	adjust_num(va_list ap, t_flag flag)
{
	long	num;

	if (flag.unsign || flag.hexa)
		num = va_arg(ap, unsigned int);
	else
		num = va_arg(ap, int);
	return (num);
}

long	adjust_len_flag(long num, t_flag *flag)
{
	long	len;

	len = get_numlen(num, flag->hexa);
	if (num < 0)
		flag->plus = '-';
	if (flag->precision && flag->padding_right == 0 && num == 0)
		len = 0;
	if (flag->padding_left < len)
		flag->padding_left = len;
	if (flag->padding_right < len)
		flag->padding_right = len;
	if (flag->hexa && flag->hash)
	{
		flag->padding_left -= 2;
		flag->plus = 0;
	}
	if (flag->plus || num < 0)
		flag->padding_left--;
	if (flag->padding_left < 0)
		flag->padding_left = 0;
	return (len);
}
