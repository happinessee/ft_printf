/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:50:02 by hyojeong          #+#    #+#             */
/*   Updated: 2022/04/14 10:13:44 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>

void	ft_putptr(size_t num, int hexa)
{
	const char		*hexanum = "0123456789abcdef";
	size_t			nb;
	int				mod;

	nb = num;
	mod = 10;
	if (hexa)
		mod = 16;
	if (nb < 0)
		nb *= -1;
	if (nb >= (size_t)mod)
	{
		ft_putptr(nb / mod, hexa);
	}
	write(1, &hexanum[(nb % mod)], 1);
}

size_t	get_unsignedlen(size_t num, int flag)
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

void	action(unsigned long ptr, int *printf_len)
{
	write(1, "0x", 2);
	*printf_len += 2;
	ft_putptr((ptr), 1);
	*printf_len += get_unsignedlen(ptr, 1);
}

void	print_pointer(va_list ap, t_flag *flag, int *printf_len)
{
	unsigned long	ptr;

	ptr = (unsigned long)va_arg(ap, void *);
	if (!(flag->left))
	{
		space_padding(flag->padding_left, \
			(get_unsignedlen(ptr, 1) + 2), printf_len);
		action(ptr, printf_len);
	}
	else
	{
		action(ptr, printf_len);
		space_padding(flag->padding_left, \
			(get_unsignedlen(ptr, 1) + 2), printf_len);
	}
}
