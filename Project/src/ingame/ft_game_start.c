/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:08:59 by fbonini-          #+#    #+#             */
/*   Updated: 2021/09/14 15:52:11 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_game_start(t_mem *mem)
{
	ft_init_setup(mem, mem->map->line_size * 64, mem->map->col_numb * 64);
	ft_get_game_image(mem);
	ft_loop_game(mem);
	return (SUCCESS);
}

void	ft_init_setup(t_mem *mem, int hori_size, int vert_size)
{
	mem->server->mlx = mlx_init();
	mem->server->win = mlx_new_window(mem->server->mlx, hori_size,
			vert_size, "so_long");
	mem->win_img->img = mlx_new_image(mem->server->mlx, hori_size,
			vert_size);
	mem->win_img->addr = mlx_get_data_addr(mem->win_img->img,
			&mem->win_img->bits_per_pixel,
			&mem->win_img->line_length,
			&mem->win_img->endian);
}

void	ft_get_game_image(t_mem *mem)
{
	mem->map->wall = ft_load_image(mem, mem->server->mlx, "art/wall.xpm");
	mem->map->floor = ft_load_image(mem, mem->server->mlx, "art/grass.xpm");
	mem->player->img = ft_load_image(mem, mem->server->mlx, "art/chk_d00.xpm");
	mem->gate->img = ft_load_image(mem, mem->server->mlx, "art/nest.xpm");
	ft_load_item_image(mem->item_list->first, mem);
	ft_load_enemy_image(mem->enemy_list->first, mem);
}
