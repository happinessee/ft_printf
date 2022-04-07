/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:12:51 by hyojeong          #+#    #+#             */
/*   Updated: 2022/04/07 18:50:56 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char *str)
{
	size_t	cnt;

	cnt = 0;
	if (str == 0)
		return (0);
	while (str[cnt])
		cnt++;
	return (cnt);
}

char	*ft_strchr(const char *s, int c)
{
	int		idx;

	idx = 0;
	while (s[idx])
	{
		if (s[idx] == (char)c)
			return ((char *)&s[idx]);
		idx++;
	}
	if (s[idx] == (char)c)
		return ((char *)&s[idx]);
	return (0);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*memory;

	i = 0;
	memory = (unsigned char *)b;
	while (i < len)
	{
		memory[i] = c;
		i++;
	}
	return (memory);
}

size_t  ft_strlcat(char *dst, const char *src, size_t dstsize)
{
        size_t  index;
        size_t  dst_len;
        size_t  src_len;

        index = 0;
        dst_len = ft_strlen(dst);
        src_len = ft_strlen((char *)src);
        if (dstsize <= dst_len)
                return (src_len + dstsize);
        if (dst == 0 || src == 0)
                return (0);
        while (src[index] && dst_len + index + 1 < dstsize)
        {
                dst[dst_len + index] = src[index];
                index++;
        }
        dst[dst_len + index] = 0;
        return (dst_len + src_len);
}
