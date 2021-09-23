/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_item.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 18:07:18 by fbonini-          #+#    #+#             */
/*   Updated: 2021/09/14 15:59:47 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_item_image(t_item *item, t_mem *mem)
{
	size_t	i;

	i = 0;
	while (i < mem->item_list->total)
	{
		item->img = ft_load_image(mem, mem->server->mlx, "art/item_m.xpm");
		item = item->next;
		i++;
	}
}

int	ft_put_item_image(t_item *item, t_mem *mem)
{
	size_t	i;

	i = 0;
	while (i < mem->item_list->total)
	{
		ft_put_img(mem, item->img.img, item->posy, item->posx);
		item = item->next;
		i++;
	}
	return (0);
}

void	ft_collect_item(t_mem *mem, t_item_list *list)
{
	t_item	*item;

	item = NULL;
	item = ft_get_item_pos(item, list, mem->player->posx, mem->player->posy);
	ft_dstr_item(mem, list, item);
	mem->design_map[mem->player->posx][mem->player->posy] = '0';
}

t_item	*ft_get_item_pos(t_item *item, t_item_list *list, int x, int y)
{
	item = list->first;
	while (item->posx != x || item->posy != y)
	{
		item = item->next;
	}
	return (item);
}

void	ft_dstr_item(t_mem *mem, t_item_list *list, t_item *get_item)
{
	if (get_item->img.img)
		mlx_destroy_image(mem->server->mlx, get_item->img.img);
	if (list->first == get_item)
	{
		if (list->last == get_item)
		{
			list->first = NULL;
			list->last = NULL;
		}
		else
		{
			list->first = get_item->next;
			list->last->next = get_item->next;
			get_item->next->prev = list->last;
		}
	}
	else
	{
		if (list->last == get_item)
			list->last = get_item->prev;
		get_item->prev->next = get_item->next;
		get_item->next->prev = get_item->prev;
	}
	list->total--;
	free(get_item);
}
