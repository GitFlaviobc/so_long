/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:01:23 by fbonini-          #+#    #+#             */
/*   Updated: 2021/09/14 15:10:09 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_end_game(t_mem *mem)
{
	ft_destroy_game(mem);
	ft_free_game(mem);
	exit(0);
}

void	ft_destroy_game(t_mem *mem)
{
	while (mem->item_list->total != 0)
		ft_dstr_item(mem, mem->item_list, mem->item_list->first);
	while (mem->enemy_list->total != 0)
		ft_dstr_enemy(mem, mem->enemy_list, mem->enemy_list->first);
	if (mem->win_img->img)
		mlx_destroy_image(mem->server->mlx, mem->win_img->img);
	if (mem->player->img.img)
		mlx_destroy_image(mem->server->mlx, mem->player->img.img);
	if (mem->gate->img.img)
		mlx_destroy_image(mem->server->mlx, mem->gate->img.img);
	if (mem->map->wall.img)
		mlx_destroy_image(mem->server->mlx, mem->map->wall.img);
	if (mem->map->floor.img)
		mlx_destroy_image(mem->server->mlx, mem->map->floor.img);
	if (mem->server->win)
		mlx_destroy_window(mem->server->mlx, mem->server->win);
	if (mem->server->mlx)
		mlx_destroy_display(mem->server->mlx);
}

void	ft_free_map_design(t_mem *mem)
{
	int	i;

	i = mem->map->col_numb - 1;
	while (i >= 0)
	{
		free(mem->design_map[i]);
		i--;
	}
	free(mem->design_map);
}

void	ft_free_game(t_mem *mem)
{
	if (mem->win_img)
		free(mem->win_img);
	if (mem->player)
		free(mem->player);
	if (mem->item_list)
		free(mem->item_list);
	if (mem->keys)
		free(mem->keys);
	if (mem->actions)
		free(mem->actions);
	if (mem->design_map)
		ft_free_map_design(mem);
	if (mem->map)
		free(mem->map);
	if (mem->server)
		free(mem->server);
}
