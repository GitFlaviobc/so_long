/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:42:10 by fbonini-          #+#    #+#             */
/*   Updated: 2021/09/15 10:52:39 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_up(t_mem *mem)
{
	ft_player_animation(mem, ft_player_ani_up);
	mem->player->posx -= 1;
	mem->moves++;
	return (0);
}

int	ft_move_down(t_mem *mem)
{
	ft_player_animation(mem, ft_player_ani_down);
	mem->player->posx += 1;
	mem->moves++;
	return (0);
}

int	ft_move_right(t_mem *mem)
{
	ft_player_animation(mem, ft_player_ani_right);
	mem->player->posy += 1;
	mem->moves++;
	return (0);
}

int	ft_move_left(t_mem *mem)
{
	ft_player_animation(mem, ft_player_ani_left);
	mem->player->posy -= 1;
	mem->moves++;
	return (0);
}

int	ft_player_action(int (*funct)(), t_mem *mem, char space)
{
	if (space != '1')
	{
		if (mem->design_map[mem->player->posx][mem->player->posy] != 'E')
			mem->design_map[mem->player->posx][mem->player->posy] = '0';
		funct(mem);
		if (mem->design_map[mem->player->posx][mem->player->posy] != 'E')
			mem->design_map[mem->player->posx][mem->player->posy] = 'P';
		if (space == 'C')
			ft_collect_item(mem, mem->item_list);
		if (space == 'H' || space == 'V')
			ft_end_game(mem);
		if (space == 'E')
			ft_check_exit(mem, mem->item_list->total);
	}
	return (0);
}
