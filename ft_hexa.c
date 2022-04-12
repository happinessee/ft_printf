/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:39:02 by hyojeong          #+#    #+#             */
/*   Updated: 2022/04/12 12:59:29 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>

void	ft_hexa(t_flag *flag)
{
	if (flag->hexa && flag->hash)
	{
		if (flag->hash == 1)
			write(1, "0x", 2);
		else
			write(1, "0X", 2);
	}
}