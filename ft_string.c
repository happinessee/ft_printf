/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:17:47 by hyojeong          #+#    #+#             */
/*   Updated: 2022/04/12 18:43:53 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	size_t	idx;

	idx = 0;
	if (str == 0)
	{
		write(1, "(null)", 6);
		return ;
	}
	while (str[idx])
	{
		write(1, &str[idx], 1);
		idx++;
	}
}

void	print_char(va_list ap, t_flag *flag, int *printf_len)
{
	char	c;
	long	idx;

	idx = 0;
	c = va_arg(ap, int);
	if (flag->minus)
	{
		ft_putchar(c);
		while (flag->padding_left > idx + 1)
		{
			write(1, " ", 1);
			(*printf_len)++;
			idx++;
		}
	}
	else
	{
		while (flag->padding_left > idx + 1)
		{
			write(1, " ", 1);
			(*printf_len)++;
			idx++;
		}
		ft_putchar(c);
		(*printf_len)++;
	}
}

void	print_str(va_list ap, t_flag *flag, int *printf_len)
{
	char	*str;
	long	idx;
	long	len;

	idx = 0;
	str = va_arg(ap, char *);
	len = ft_strlen(str);
	*printf_len += len;
	if (str == 0)
	{
		*printf_len += 6;
		len = 6;
	}
	if (flag->minus)	// 왼쪽 정렬이라면?
	{
		if (flag->padding_right)	// '.' 옵션이 있어서 최소 출력 길이가 존재한다면
		{
			while (flag->padding_right > idx)
			{
				write(1, &(*str), 1);
				(*printf_len)++;
				str++;
				idx++;
			}
			while (flag->padding_left > flag->padding_right + idx)
			{
				write(1, " ", 1);
				(*printf_len)++;
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
					(*printf_len)++;
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
				(*printf_len)++;
				idx++;
			}
			idx = 0;
			while (flag->padding_right > idx)
			{
				write(1, &(*str), 1);
				(*printf_len)++;
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
				while (flag->padding_left > len + idx)
				{
					write(1, " ", 1);
					(*printf_len)++;
					idx++;
				}
				ft_putstr(str);
			}
		}
	}
}