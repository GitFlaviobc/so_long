/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 14:09:20 by fbonini-          #+#    #+#             */
/*   Updated: 2021/09/14 17:29:16 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_render_next_frame(t_mem *mem)
{
	if (mem->frames % 1700 == 0 || mem->ani_player != 0)
	{
		ft_put_img(mem, mem->win_img->img, 0, 0);
		ft_print_map(mem);
		ft_put_img(mem, mem->gate->img.img, mem->gate->posy, mem->gate->posx);
		ft_put_img(mem, mem->player->img.img,
			mem->player->posy,
			mem->player->posx);
		ft_item_animation(mem->item_list, mem);
		if (mem->frames % 3400 == 0)
			ft_enemy_movement(mem, mem->enemy_list->first);
		ft_put_enemy_image(mem->enemy_list->first, mem);
		ft_print_total_moves(mem->moves, mem);
	}
	mem->frames++;
	if (mem->frames > 6800)
		mem->frames = 1700;
	return (SUCCESS);
}

void	ft_print_total_moves(int moves, t_mem *mem)
{
	char	*print;

	print = ft_itoa(moves);
	mlx_string_put(mem->server->mlx, mem->server->win, 64, 64, YELLOW, print);
	free(print);
}

int	ft_key_hook(int key, t_mem *mem)
{
	int		check_key;
	int		x;
	int		y;
	char	check_space;

	x = mem->player->posx;
	y = mem->player->posy;
	check_space = '\0';
	check_key = ft_valid_key(mem, key);
	if (check_key < TOTAL_ACTIONS)
	{
		if (check_key < 4)
			check_space = ft_check_future_space(mem, check_key, x, y);
		ft_player_action(mem->actions->function[check_key], mem, check_space);
	}
	return (SUCCESS);
}

void	ft_loop_game(t_mem *mem)
{
	mlx_hook(mem->server->win, 2, 1L << 0, ft_key_hook, mem);
	mlx_hook(mem->server->win, 17, 1L << 2, ft_end_game, mem);
	mlx_loop_hook(mem->server->mlx, ft_render_next_frame, mem);
	mlx_loop(mem->server->mlx);
}
