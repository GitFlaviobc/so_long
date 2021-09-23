/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:06:22 by fbonini-          #+#    #+#             */
/*   Updated: 2021/09/15 09:57:01 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_enemy_image(t_enemy *enemy, t_mem *mem)
{
	size_t	i;

	i = 0;
	while (i < mem->enemy_list->total)
	{
		if (enemy->e_tag == 'H')
			enemy->img = ft_load_image(mem, mem->server->mlx, "art/enmy01.xpm");
		else
			enemy->img = ft_load_image(mem, mem->server->mlx, "art/enmy02.xpm");
		enemy = enemy->next;
		i++;
	}
}

int	ft_put_enemy_image(t_enemy *enemy, t_mem *mem)
{
	size_t	i;

	i = 0;
	while (i < mem->enemy_list->total)
	{
		ft_put_img(mem, enemy->img.img, enemy->posy, enemy->posx);
		enemy = enemy->next;
		i++;
	}
	return (0);
}

void	ft_dstr_enemy(t_mem *mem, t_enemy_list *list, t_enemy *enemy)
{
	if (enemy->img.img)
		mlx_destroy_image(mem->server->mlx, enemy->img.img);
	if (list->first == enemy)
	{
		if (list->last == enemy)
		{
			list->first = NULL;
			list->last = NULL;
		}
		else
		{
			list->first = enemy->next;
			list->last->next = enemy->next;
			enemy->next->prev = list->last;
		}
	}
	else
	{
		if (list->last == enemy)
			list->last = enemy->prev;
		enemy->prev->next = enemy->next;
		enemy->next->prev = enemy->prev;
	}
	list->total--;
	free(enemy);
}
