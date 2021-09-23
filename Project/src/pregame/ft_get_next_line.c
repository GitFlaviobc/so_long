/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 16:08:19 by fbonini-          #+#    #+#             */
/*   Updated: 2021/09/14 15:39:50 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (0);
	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = (char *) malloc ((s1_len + s2_len + 1) * sizeof(char));
	if (!ptr)
		return (0);
	while (i < (s1_len + s2_len))
	{
		if (i < s1_len)
			ptr[i] = *s1++;
		else
			ptr[i] = *s2++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	ptr = (char *) malloc ((len + 1) * sizeof(char));
	if (!ptr)
	{
		free(ptr);
		return (0);
	}
	while (s[i] != '\0' && i < len)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static int	ft_readbuffer(int fd, char *temp_read, char **str_to_line, int *n)
{
	char	*tmp_string;

	while (*n > 0)
	{
		*n = read(fd, temp_read, BUFFER_SIZE);
		if (*n < 0)
		{
			free(temp_read);
			return (0);
		}
		temp_read[*n] = '\0';
		if (*str_to_line == 0)
			*str_to_line = ft_strdup(temp_read);
		else
		{
			tmp_string = ft_strjoin(*str_to_line, temp_read);
			free(*str_to_line);
			*str_to_line = tmp_string;
		}
		if (ft_strchr(temp_read, '\n'))
			break ;
	}
	free(temp_read);
	return (1);
}

static char	*ft_add_to_line(char *str_to_line, char **line)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (str_to_line[i] != '\n' && str_to_line[i] != '\0')
		i++;
	if (str_to_line[i] == '\n')
	{
		*line = ft_substr(str_to_line, i);
		tmp = ft_strdup(&str_to_line[i + 1]);
		free(str_to_line);
	}
	else
	{
		*line = ft_strdup(str_to_line);
		free(str_to_line);
	}
	return (tmp);
}

int	get_next_line(int fd, char **line)
{
	char		*temp_read;
	static char	*str_to_line[256];
	int			n;

	n = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd > 256)
		return (-1);
	temp_read = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp_read)
		return (-1);
	if (!ft_readbuffer(fd, temp_read, &str_to_line[fd], &n))
		return (-1);
	str_to_line[fd] = ft_add_to_line(str_to_line[fd], line);
	if (n == 0 && !str_to_line[fd])
	{
		free(str_to_line[fd]);
		return (0);
	}
	return (1);
}
