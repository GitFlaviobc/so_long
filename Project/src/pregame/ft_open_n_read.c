/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_n_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 17:05:02 by fbonini-          #+#    #+#             */
/*   Updated: 2021/09/07 16:47:22 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_open_file(t_mem *mem, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error.\nFile descriptor error.\n", 2);
		ft_end_game(mem);
	}
	return (fd);
}

void	ft_read_file(int fd, t_mem *mem)
{
	char	*read_line;
	int		reading;
	int		line;

	line = 0;
	reading = 1;
	while (reading == 1)
	{
		reading = get_next_line(fd, &read_line);
		if (line == 0)
			mem->map->line_size = ft_strlen(read_line);
		if (ft_strlen(read_line) != mem->map->line_size)
		{
			ft_putstr_fd("Error.\nShape is not a rectangle.\n", 2);
			exit (1);
		}
		line++;
		free(read_line);
	}
	mem->map->col_numb = line;
	close(fd);
}

void	ft_read_design(int fd, t_mem *mem)
{
	char	*read_line;
	int		reading;
	int		i;

	reading = 1;
	i = 0;
	while (reading == 1)
	{
		reading = get_next_line(fd, &read_line);
		ft_strlcpy(mem->design_map[i], read_line, mem->map->line_size + 1);
		i++;
		free(read_line);
	}
	close(fd);
}
