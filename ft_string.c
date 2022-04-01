/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:17:47 by hyojeong          #+#    #+#             */
/*   Updated: 2022/04/01 15:46:33 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(va_list ap)
{
	char	c;

	c = va_arg(ap, char);
	write(1, &c, 1);
}

void	ft_putstr(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	size_t	idx;

	idx = 0;
	while (str[idx])
	{
		write(1, &str[idx], 1);
		idx++;
	}
}