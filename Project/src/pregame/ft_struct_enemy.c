/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_enemy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:54:17 by fbonini-          #+#    #+#             */
/*   Updated: 2021/09/14 15:56:54 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_enemy_list	*ft_alloc_enemy_list(t_mem *mem)
{
	t_enemy_list	*enemy_list;

	enemy_list = (t_enemy_list *)malloc(sizeof(t_enemy_list));
	if (!enemy_list)
	{
		ft_putstr_fd("Error.\nMemory allocation error.\n", 2);
		ft_end_game(mem);
	}
	enemy_list->first = NULL;
	enemy_list->last = NULL;
	enemy_list->total = 0;
	return (enemy_list);
}

t_enemy	*ft_alloc_enemy(t_mem *mem, int i, int j, char tag)
{
	t_enemy	*enemy;

	enemy = (t_enemy *) malloc (sizeof(t_enemy));
	if (!enemy)
	{
		ft_putstr_fd("Error.\nMemory allocation error.\n", 2);
		ft_end_game(mem);
	}
	enemy->posx = i;
	enemy->posy = j;
	enemy->next = enemy;
	enemy->prev = enemy;
	enemy->e_tag = tag;
	if (tag == 'V')
		enemy->check = W;
	else
		enemy->check = A;
	return (enemy);
}

void	ft_fill_enemy_list(t_mem *mem, int i, int j, char tag)
{
	t_enemy	*enemy;

	enemy = ft_alloc_enemy(mem, i, j, tag);
	if (mem->enemy_list->total == 0)
		mem->enemy_list->last = enemy;
	else
	{
		enemy->next = mem->enemy_list->first;
		mem->enemy_list->first->prev = enemy;
		enemy->prev = mem->enemy_list->last;
		mem->enemy_list->last->next = enemy;
	}
	mem->enemy_list->first = enemy;
	mem->enemy_list->total++;
}
