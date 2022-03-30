/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:58:39 by hyojeong          #+#    #+#             */
/*   Updated: 2022/03/30 17:32:15 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdlib.h>
#include <stdarg.h>

int branch(char *str, ...)
{

	return (1);
}

int	ft_printf(const char *str, ...)
{
	while (1)
	{
		if (str && !(str == '%'))
		{
			write(1, str, 1);
		}
		else
		{
			
		}
		str++;
	}
}
