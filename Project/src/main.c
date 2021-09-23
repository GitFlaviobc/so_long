/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 16:33:22 by fbonini-          #+#    #+#             */
/*   Updated: 2021/09/07 15:27:00 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mem	mem;
	int		fd;

	if (argc == 2)
	{
		ft_check_extension(argv[1], ".ber");
		ft_struct_memmory(&mem);
		fd = ft_open_file(&mem, argv);
		ft_read_file(fd, &mem);
		ft_alloc_mapdesign(&mem);
		fd = ft_open_file(&mem, argv);
		ft_read_design(fd, &mem);
		ft_map_check(&mem);
		ft_game_start(&mem);
	}
	else
		ft_putstr_fd("Error.\nPlease, use 2 arguments.\n", 2);
	return (0);
}
