/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_item_animation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:32:24 by fbonini-          #+#    #+#             */
/*   Updated: 2021/09/14 17:29:02 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_item_mid(t_item *item, t_mem *mem)
{
	size_t	i;

	i = 0;
	while (i < mem->item_list->total)
	{
		mlx_destroy_image(mem->server->mlx, item->img.img);
		item->img = ft_load_image(mem, mem->server->mlx, "art/item_m.xpm");
		item = item->next;
		i++;
	}
}

void	ft_load_item_left(t_item *item, t_mem *mem)
{
	size_t	i;

	i = 0;
	while (i < mem->item_list->total)
	{
		mlx_destroy_image(mem->server->mlx, item->img.img);
		item->img = ft_load_image(mem, mem->server->mlx, "art/item_l.xpm");
		item = item->next;
		i++;
	}
}

void	ft_load_item_right(t_item *item, t_mem *mem)
{
	size_t	i;

	i = 0;
	while (i < mem->item_list->total)
	{
		mlx_destroy_image(mem->server->mlx, item->img.img);
		item->img = ft_load_image(mem, mem->server->mlx, "art/item_r.xpm");
		item = item->next;
		i++;
	}
}

int	ft_item_animation(t_item_list *list, t_mem *mem)
{
	if (mem->frames % 5100 == 0)
		ft_load_item_left(list->first, mem);
	else if (mem->frames % 3400 == 0)
		ft_load_item_right(list->first, mem);
	else if (mem->frames == 1700)
		ft_load_item_mid(list->first, mem);
	ft_put_item_image(list->first, mem);
	return (0);
}
