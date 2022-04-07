/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:12:35 by hyojeong          #+#    #+#             */
/*   Updated: 2022/04/07 18:52:16 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>
#include <stdlib.h>

size_t	get_numlen(size_t num, int flag)
{
	size_t	len;
	int		mod;

	len = 0;
	mod = 10;
	if (flag)
		mod = 16;
	if (num < 0)
		len++;
	if (num == 0)
		len = 1;
	while (!(num == 0))
	{
		num = num / mod;
		len++;
	}
	return (len);
}

char	*itoa(int num, int hexa, t_flag *flag)
{
	const char	*hexanum = "0123456789abcdef";
	long		nb;
	int			mod;
	char		*str;
	size_t		len;

	nb = num;
	len = get_numlen(nb, hexa);
	str = malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	mod = 10;
	if (hexa)
		mod = 16;
	if (nb < 0)
	{
		nb *= -1;
		flag->minus = 1;
	}
	while (nb >= mod)
	{
		ft_strlcat(str, &hexanum[(nb % mod)], ft_strlen(str) + 1);
		nb = nb / mod;
	}
	*str = '\0';
	return (str);
}

void	print_decimal(va_list ap, t_flag *flag)
{
	char	*res;
	long	num;
	size_t	len;
	size_t	idx;

	idx = 0;
	num = va_arg(ap, int);
	len = get_numlen(num, flag->hexa);
	res = itoa(num, flag->hexa, flag);
	if (flag->padding_left < len)		// 최소, 최대 넓이보다 실제 출력할 숫자가 더 길때 
		flag->padding_left = 0;
	if (flag->padding_right < len)
		flag->padding_right = 0;
	if (flag->plus || num < 0)		//  +, -, ' ' 기호가 있다면 padding 개수를 줄여주어야 함.
		flag->padding_left--;
	if (!flag->left)		// 왼쪽 정렬 ('-') 플래그가 아닐 때
	{
		while (flag->padding_left > flag->padding_right + idx) // width space padding
		{
			write(1, " ", 1);
			idx++;
		}
		if (flag->plus && !(flag->minus == 1))
			write(1, &flag->plus, 1);
		idx = 0;
		while (flag->zero && (flag->padding_right >= idx + len)) // zero flag padding
		{
			write(1, "0", 1);
			idx++;
		}
		while (!(flag->plus) && (flag->padding_right >= idx + len)) // space flag padding
		{
			write(1, " ", 1);
			idx++;
		}
		ft_putstr(res);
	}
	else	// '-' flag 로 왼쪽 정렬일때
	{
		if (flag->plus && !(flag->minus == 1))
			write(1, &flag->plus, 1);
		while (flag->zero && (flag->padding_right >= idx + len)) // zero flag padding
		{
			write(1, "0", 1);
			idx++;
		}
		while (!(flag->plus) && (flag->padding_right >= idx + len)) // space flag padding
		{
			write(1, " ", 1);
			idx++;
		}
		ft_putstr(res);
		idx = 0;
		while (flag->padding_left > flag->padding_right + idx)
		{
			write(1, " ", 1);
			idx++;
		}
	}
}