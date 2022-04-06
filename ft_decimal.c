/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:12:35 by hyojeong          #+#    #+#             */
/*   Updated: 2022/04/06 17:29:32 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	while (!(num == 0))
	{
		num = num / mod;
		len++;
	}
	if (num == 0)
		len = 1;
	return (len);
}

char	*change_nbr_str(int num, int flag)
{
	long		nb;
	const char	*hexa = "0123456789abcdef";
	int			mod;
	char		*str;
	size_t		len;

	nb = num;
	len = get_numlen(nb, flag);
	str = malloc(sizeof(char) * (len + 1));
	mod = 10;
	if (flag)
		mod = 16;
	if (nb < 0)
		nb *= -1;
	while (nb >= mod)
	{
		*str = hexa[(nb % mod)];
		str++;
		nb = nb / mod;
	}
	str = '\0';
	return (str);
}

void	print_decimal(va_list ap, t_flag *flag)
{
	char	*res;
	long	num;
	size_t	len;
	size_t	idx;

	idx = 0;
	num = va_arg(ap, long);
	len = get_numlen(num, flag->hexa);
	res = change_nbr_str(num, flag->hexa);
	if (flag->padding_left < len)		// 최소, 최대 넓이보다 실제 출력할 숫자가 더 길때 
		flag->padding_left = 0;
	if (flag->padding_right < len)
		flag->padding_right = 0;
	if (!flag->left)		// 왼쪽 정렬 ('-') 플래그가 아닐 때
	{
		while (flag->zero && flag->padding_left > idx + len)
		{
			write(1, "0", 1);
			idx++;

		}
	}
}