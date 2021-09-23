/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_movement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 20:11:46 by fbonini-          #+#    #+#             */
/*   Updated: 2021/09/14 16:59:00 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_enemy_movement(t_mem *mem, t_enemy *enemy)
{
	size_t	i;

	i = 0;
	while (i < mem->enemy_list->total)
	{
		mem->design_map[enemy->posx][enemy->posy] = '0';
		if (enemy->e_tag == 'V')
			ft_movement_v(mem, enemy);
		else if (enemy->e_tag == 'H')
			ft_movement_h(mem, enemy);
		enemy = enemy->next;
		i++;
	}
}

void	ft_movement_v(t_mem *mem, t_enemy *enemy)
{
	char	check_space;

	if (enemy->check == W)
	{
		check_space = ft_check_future_space(mem, 1, enemy->posx, enemy->posy);
		if (check_space != '1')
			enemy->posx -= 1;
		else
			enemy->check = S;
	}
	else
	{
		check_space = ft_check_future_space(mem, 2, enemy->posx, enemy->posy);
		if (check_space != '1')
			enemy->posx += 1;
		else
			enemy->check = W;
	}
	mem->design_map[enemy->posx][enemy->posy] = 'V';
	if (check_space == 'P')
		ft_end_game(mem);
}

void	ft_movement_h(t_mem *mem, t_enemy *enemy)
{
	char	check_space;

	if (enemy->check == A)
	{
		check_space = ft_check_future_space(mem, 0, enemy->posx, enemy->posy);
		if (check_space != '1')
			enemy->posy -= 1;
		else
			enemy->check = D;
	}
	else
	{
		check_space = ft_check_future_space(mem, 3, enemy->posx, enemy->posy);
		if (check_space != '1')
			enemy->posy += 1;
		else
			enemy->check = A;
	}
	mem->design_map[enemy->posx][enemy->posy] = 'H';
	if (check_space == 'P')
		ft_end_game(mem);
}
