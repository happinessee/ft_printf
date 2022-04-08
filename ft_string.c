/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:17:47 by hyojeong          #+#    #+#             */
/*   Updated: 2022/04/08 17:49:05 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	size_t	idx;

	idx = 0;
	while (str[idx])
	{
		write(1, &str[idx], 1);
		idx++;
	}
}

print_char(va_list ap, t_flag *flag)
{
	
}

void	print_str(va_list ap, t_flag *flag)
{
	char	*str;
	size_t	idx;
	size_t	len;

	idx = 0;
	str = va_arg(ap, char *);
	len = ft_strlen(str);
	if (flag->minus)	// 왼쪽 정렬이라면?
	{
		if (flag->padding_right)	// '.' 옵션이 있어서 최소 출력 길이가 존재한다면
		{
			while (flag->padding_right > idx)
			{
				write(1, &(*str), 1);
				str++;
				idx++;
			}
			while (flag->padding_left > flag->padding_right + idx)
			{
				write(1, " ", 1);
				idx++;
			}
		}
		else
		{
			if (flag->padding_left < len)
				ft_putstr(str);
			else
			{
				ft_putstr(str);
				while (flag->padding_left > len + idx)
				{
					write(1, " ", 1);
					idx++;
				}
			}
		}
	}
	else	// 왼쪽 정렬이 아니라면??
	{
		if (flag->padding_right)
		{
			while (flag->padding_left > flag->padding_right + idx)
			{
				write(1, " ", 1);
				idx++;
			}
			idx = 0;
			while (flag->padding_right > idx)
			{
				write(1, &(*str), 1);
				str++;
				idx++;
			}
		}
		else
		{
			if (flag->padding_left < len)
				ft_putstr(str);
			else
			{
				ft_putstr(str);
				while (flag->padding_left > len + idx)
				{
					write(1, " ", 1);
					idx++;
				}
			}
		}
	}
}