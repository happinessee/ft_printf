/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:59:39 by hyojeong          #+#    #+#             */
/*   Updated: 2022/04/06 17:32:39 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stddef.h>
#include <stdarg.h>

int		ft_printf(const char *str, ...);

size_t	ft_strlen(char *str);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar(va_list ap);
void	ft_putstr(va_list ap);
void	print_decimal(va_list ap, t_flag *flag);

typedef	struct s_flag
{
	long	hexa;
	int		decimal;
	int		zero;
	int		padding_left;
	int		padding_right;
	int		left;
	int		width;
	int		space;
	int		plus;
	int		hash;
	int		precision;
	int		minus;
}	t_flag;

#endif
