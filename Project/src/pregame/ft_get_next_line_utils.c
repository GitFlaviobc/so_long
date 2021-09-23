/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 16:08:45 by fbonini-          #+#    #+#             */
/*   Updated: 2021/09/05 19:10:03 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(str) + 1;
	ptr = (char *) malloc (len * sizeof(char));
	if (ptr)
	{
		ft_strlcpy(ptr, str, len);
		return (ptr);
	}
	return (0);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	size_t	src_len;

	if (src == 0 || dest == 0)
		return (0);
	src_len = ft_strlen(src);
	if (src_len + 1 < len)
		ft_memcpy(dest, src, src_len + 1);
	else if (len != 0)
	{
		ft_memcpy(dest, src, len - 1);
		dest[len - 1] = '\0';
	}
	return (src_len);
}

size_t	ft_strlen(const char *s)
{
	const char	*str;

	str = s;
	while (*str != '\0')
		str++;
	return (str - s);
}

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char		*dest_cpy;
	unsigned const char	*src_cpy;

	dest_cpy = dest;
	src_cpy = src;
	if (dest == src)
		return (dest);
	while (len-- > 0)
	{
		*dest_cpy++ = *src_cpy++;
	}
	return (dest);
}

char	*ft_strchr(const char *src, int c)
{
	unsigned char	*u_src;
	unsigned char	u_c;

	u_src = (unsigned char *)src;
	u_c = (unsigned char)c;
	if (*u_src == u_c)
		return ((char *)src);
	while (*u_src)
	{
		if (*u_src == u_c)
			return ((char *)u_src);
		u_src++;
	}
	if (u_c == '\0')
		return ((char *)u_src);
	return (0);
}
