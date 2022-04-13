/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:17:47 by hyojeong          #+#    #+#             */
/*   Updated: 2022/04/13 17:27:33 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str, long len)
{
	if (str == 0)
	{
		write(1, "(null)", len);
		return ;
	}
	write(1, str, len);
}

void	print_char(va_list ap, t_flag *flag, int *printf_len)
{
	char	c;
	long	idx;

	idx = 0;
	c = va_arg(ap, int);
	if (flag->left)
	{
		ft_putchar(c);
		(*printf_len)++;
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
	if (str == 0)
	{
		if (flag->precision)
		{
			if (flag->padding_right < 7)
				len = flag->padding_right;
			else
			{
				len = 6;
				flag->padding_right = 6;
			}
		}
		else
			len = 6;
	}
	if (str && flag->padding_right > len)
		flag->padding_right = len;
	if (flag->left)	// 왼쪽 정렬이라면?
	{
		if (flag->precision)	// '.' 옵션이 있어서 최소 출력 길이가 존재한다면
		{
			if (flag->padding_right > idx)
			{
				ft_putstr(str, flag->padding_right);
				*printf_len += flag->padding_right;
				str += flag->padding_right;
				idx += flag->padding_right;
			}
			while (flag->padding_left > idx)
			{
				write(1, " ", 1);
				(*printf_len)++;
				idx++;
			}
		}
		else
		{
			if (flag->padding_left < len)
			{
				ft_putstr(str, len);
				*printf_len += len;
			}
			else
			{
				ft_putstr(str, len);
				*printf_len += len;
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
		if (flag->precision)
		{
			while (flag->padding_left > flag->padding_right + idx)
			{
				write(1, " ", 1);
				(*printf_len)++;
				idx++;
			}
			idx = 0;
			if (flag->padding_right > idx)
			{
				ft_putstr(str, flag->padding_right);
				*printf_len += flag->padding_right;
				str += flag->padding_right;
				idx++;
			}
		}
		else
		{
			if (flag->padding_left < len)
			{
				ft_putstr(str, len);
				*printf_len += len;
			}
			else
			{
				while (flag->padding_left > len + idx)
				{
					write(1, " ", 1);
					(*printf_len)++;
					idx++;
				}
				ft_putstr(str, len);
				*printf_len += len;
			}
		}
	}
}