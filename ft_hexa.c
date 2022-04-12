/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:39:02 by hyojeong          #+#    #+#             */
/*   Updated: 2022/04/12 18:44:16 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>

void	ft_hexa(t_flag *flag, int *printf_len)
{
	if (flag->hexa && flag->hash)
	{
		if (flag->hash == 1)
			write(1, "0x", 2);
		else
			write(1, "0X", 2);
		*printf_len += 2;
	}
}

void	ft_put_uxX(unsigned int num, int hexa)
{
	const char		*hexanum = "0123456789abcdef";
	unsigned int	nb;
	unsigned int	mod;

	nb = num;
	mod = 10;
	if (hexa)
		mod = 16;
	if (nb >= mod)
	{
		ft_put_uxX(nb / mod, hexa);
	}
	write(1, &hexanum[(nb % mod)], 1);
}