/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:39:02 by hyojeong          #+#    #+#             */
/*   Updated: 2022/04/14 10:15:18 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>

void	ft_hexa(long num, t_flag *flag, int *printf_len)
{
	if (flag->hexa && flag->hash && num)
	{
		if (flag->hexa == 1)
			write(1, "0x", 2);
		else
			write(1, "0X", 2);
		*printf_len += 2;
	}
}
