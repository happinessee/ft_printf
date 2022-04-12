/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:59:39 by hyojeong          #+#    #+#             */
/*   Updated: 2022/04/12 18:40:25 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stddef.h>
#include <stdarg.h>

typedef	struct s_flag
{
	long	hexa;
	int		unsign;
	int		decimal;
	int		zero;
	long	padding_left;
	long	padding_right;
	int		left;
	int		width;
	char	plus;	// ' ', '+' 플래그는 동시에 사용 불가능하므로 겹치게 지정해줄것임. (d, i)
	int		hash;
	int		precision;
	int		minus;
}	t_flag;

int		ft_printf(const char *str, ...);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(char *str);
size_t	get_numlen(long num, int flag);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putnbr(long num, int hexa);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	print_char(va_list ap, t_flag *flag, int *printf_len);
void	print_str(va_list ap, t_flag *flag, int *printf_len);
void	print_decimal(va_list ap, t_flag *flag, int *printf_len);
void	print_pointer(va_list ap, t_flag *flag, int *printf_len);
void	ft_putptr(size_t num, int hexa);
void	ft_put_uxX(unsigned int num, int hexa);
size_t	get_unsignedlen(size_t num, int mod);
void	ft_hexa(t_flag *flag, int *printf_len);
size_t  ft_strlcat1(char *dst, const char *src, size_t dstsize);

#endif
