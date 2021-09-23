/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_n_print_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 17:25:31 by fbonini-          #+#    #+#             */
/*   Updated: 2021/09/11 18:19:45 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	ft_load_image(t_mem *mem, void *mlx, char *path)
{
	t_image	image;

	image.img = mlx_xpm_file_to_image(mlx, path, &image.width, &image.height);
	if (!image.img)
	{
		ft_putstr_fd("Error.\nCould not load image.\n", 2);
		ft_end_game(mem);
	}
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	return (image);
}

void	ft_put_img(t_mem *mem, void *img, int posY, int posX)
{
	mlx_put_image_to_window(mem->server->mlx, mem->server->win,
		img, 64 * posY, 64 * posX);
}

void	ft_print_map(t_mem *mem)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < mem->map->line_size)
	{
		j = 0;
		while (j < mem->map->col_numb)
		{
			if (mem->design_map[j][i] == '1')
				ft_put_img(mem, mem->map->wall.img, i, j);
			else
				ft_put_img(mem, mem->map->floor.img, i, j);
			j++;
		}
		i++;
	}
}
