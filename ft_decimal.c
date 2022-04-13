/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:12:35 by hyojeong          #+#    #+#             */
/*   Updated: 2022/04/13 13:00:24 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>
#include <stdlib.h>

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

void	ft_putnbr(long num, int hexa)
{
	const char		*hexanum = "0123456789abcdef";
	long			nb;
	int				mod;

	nb = num;
	mod = 10;
	if (hexa)
		mod = 16;
	if (nb < 0)
		nb *= -1;
	if (nb >= mod)
	{
		ft_putnbr(nb / mod, hexa);
	}
	write(1, &hexanum[(nb % mod)], 1);
}

void	ft_put_X(unsigned int num, int hexa)
{
	const char	*hexanum = "0123456789ABCDEF";
	long		nb;
	int			mod;

	nb = num;
	mod = 10;
	if (hexa)
		mod = 16;
	if (nb < 0)
		nb *= -1;
	if (nb >= mod)
	{
		ft_put_X(nb / mod, hexa);
	}
	write(1, &hexanum[(nb % mod)], 1);
}

void	print_decimal(va_list ap, t_flag *flag, int *printf_len)
{
	long	num;
	long	len;
	long	idx;

	idx = 0;
	if (flag->unsign || flag->hexa)
		num = va_arg(ap, unsigned int);
	else
		num = va_arg(ap, int);
	if (num < 0)
		flag->plus = '-';
	len = get_numlen(num, flag->hexa);
	if (flag->padding_left < len)		// 최소, 최대 넓이보다 실제 출력할 숫자가 더 길때 
		flag->padding_left = 0;
	if (flag->padding_right < len)
		flag->padding_right = 0;
	if (flag->hexa && flag->hash)
	{ 
		flag->padding_left -= 2;
		flag->plus = 0;
	}
	if (flag->plus || num < 0)		//  +, -, ' ' 기호가 있다면 padding 개수를 줄여주어야 함.
		flag->padding_left--;
	if (flag->padding_left < 0)
		flag->padding_left = 0;
	if (!flag->left)		// 왼쪽 정렬 ('-') 플래그가 아닐 때
	{
		if (flag->padding_right)	// 최소  넓넓이이가  존존재재할할때때
		{
			while (flag->padding_left > flag->padding_right + idx)
			{
				write(1, " ", 1);
				(*printf_len)++;
				idx++;
			}
			if (flag->plus)
			{
				write(1, &flag->plus, 1);
				(*printf_len)++;
			}
			idx = 0;
			ft_hexa(flag, printf_len);
			while (flag->padding_right > len + idx)
			{
				write(1, "0", 1);
				(*printf_len)++;
				idx++;
			}
			if (flag->hexa == 2)
				ft_put_X(num, flag->hexa);
			else
				ft_putnbr(num, flag->hexa);
		}
		else
		{
			if (flag->zero && flag->plus)
			{
				write(1, &flag->plus, 1);
				(*printf_len)++;
			}
			ft_hexa(flag, printf_len);
			while (flag->zero && flag->padding_left > len + idx)
			{
				write(1, "0", 1);
				(*printf_len)++;
				idx++;
			}
			while (flag->padding_left > len + idx)
			{
				write(1, " ", 1);
				(*printf_len)++;
				idx++;
			}
			if (!(flag->zero) && flag->plus)
			{
				write(1, &flag->plus, 1);
				(*printf_len)++;
			}
			if (flag->hexa == 2)
				ft_put_X(num, flag->hexa);
			else
				ft_putnbr(num, flag->hexa);
		}
	}
	else	// '-' flag 로 왼쪽 정렬일때
	{
		if (flag->padding_right)
		{
			if (flag->plus)
			{
				write(1, &flag->plus, 1);
				(*printf_len)++;
			}
			ft_hexa(flag, printf_len);
			while (flag->padding_right > len + idx)
			{
				write(1, "0", 1);
				(*printf_len)++;
				idx++;
			}
			if (flag->hexa == 2)
				ft_put_X(num, flag->hexa);
			else
				ft_putnbr(num, flag->hexa);
			while (flag->padding_left > flag->padding_right + idx)
			{
				write(1, " ", 1);
				(*printf_len)++;
				idx++;
			}
		}
		else
		{
			if (flag->plus)
			{
				write(1, &flag->plus, 1);
				(*printf_len)++;
			}
			ft_hexa(flag, printf_len);
			if (flag->hexa == 2)
				ft_put_X(num, flag->hexa);
			else
				ft_putnbr(num, flag->hexa);
			while (flag->padding_left > len + idx)
			{
				write(1, " ", 1);
				(*printf_len)++;
				idx++;
			}
		}
	}
	*printf_len += get_numlen(num, flag->hexa);
}
