/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:59:39 by hyojeong          #+#    #+#             */
/*   Updated: 2022/04/14 11:37:45 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stddef.h>
#include <stdarg.h>

typedef struct s_flag
{
	long	hexa;
	int		unsign;
	int		decimal;
	int		zero;
	long	padding_left;
	long	padding_right;
	int		left;
	int		width;
	char	plus;
	int		hash;
	int		precision;
}	t_flag;

int		ft_printf(const char *str, ...);

void	ft_putchar(char c, int *printf_len);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(char *str);
size_t	ft_strlcat1(char *dst, const char *src, size_t dstsize);
void	*ft_memset(void *b, int c, size_t len);

size_t	get_numlen(long num, int flag);
size_t	get_unsignedlen(size_t num, int mod);
void	ft_putnbr(long num, t_flag flag);
void	ft_putstr(char *s, long len, int *printf_len);
void	ft_putptr(size_t num, int hexa);
void	ft_hexa(long num, t_flag *flag, int *printf_len);

void	print_percent(int *printf_len);
void	print_char(va_list ap, t_flag *flag, int *printf_len);
void	print_str(va_list ap, t_flag *flag, int *printf_len);
void	print_decimal(va_list ap, t_flag *flag, int *printf_len);
void	print_pointer(va_list ap, t_flag *flag, int *printf_len);
void	padding(long left, long right, int *printf_len, int c);
#endif
