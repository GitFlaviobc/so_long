/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 08:45:10 by fbonini-          #+#    #+#             */
/*   Updated: 2021/09/14 12:46:44 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(const char *str1, const char *str2, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	if (len == 0)
		return (0);
	while (*s1 && *s2 && (*s1 == *s2) && len-- > 1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (fd < 0 || !s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_numblen(int numb)
{
	int	i;

	i = 0;
	if (numb == 0 || numb < 0)
		i++;
	while (numb != 0)
	{
		numb = numb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	n_size;
	size_t	i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n_size = ft_numblen(n);
	str = (char *) malloc ((n_size + 1) * sizeof(char));
	if (!str)
		return (0);
	str[n_size] = '\0';
	i = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
		i++;
	}
	while (n_size-- > i)
	{
		str[n_size] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
