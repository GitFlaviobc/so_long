/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_mem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 10:50:12 by fbonini-          #+#    #+#             */
/*   Updated: 2021/09/14 14:58:29 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_struct_memmory(t_mem *mem)
{
	mem->player = ft_alloc_player(mem);
	mem->item_list = ft_alloc_item_list(mem);
	mem->enemy_list = ft_alloc_enemy_list(mem);
	mem->gate = ft_alloc_exit_gate(mem);
	mem->win_img = ft_alloc_image(mem);
	mem->map = ft_alloc_map(mem);
	mem->server = ft_alloc_server(mem);
	mem->keys = ft_alloc_keys(mem);
	mem->actions = ft_alloc_actions(mem);
	mem->moves = 0;
	mem->frames = 0;
	mem->ani_player = 0;
}

t_image	*ft_alloc_image(t_mem *mem)
{
	t_image	*image;

	image = (t_image *) malloc(sizeof(t_image));
	if (!image)
	{
		ft_putstr_fd("Error.\nMemory allocation error.\n", 2);
		ft_end_game(mem);
	}
	image->img = NULL;
	image->addr = NULL;
	image->bits_per_pixel = 0;
	image->line_length = 0;
	image->endian = 0;
	image->width = 0;
	image->height = 0;
	return (image);
}

t_server	*ft_alloc_server(t_mem *mem)
{
	t_server	*server;

	server = (t_server *) malloc(sizeof(t_server));
	if (!server)
	{
		ft_putstr_fd("Error.\nMemory allocation error.\n", 2);
		ft_end_game(mem);
	}
	server->mlx = NULL;
	server->win = NULL;
	return (server);
}
