/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_item.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:54:06 by fbonini-          #+#    #+#             */
/*   Updated: 2021/09/14 15:57:09 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_item_list	*ft_alloc_item_list(t_mem *mem)
{
	t_item_list	*item_list;

	item_list = (t_item_list *)malloc(sizeof(t_item_list));
	if (!item_list)
	{
		ft_putstr_fd("Error.\nMemory allocation error.\n", 2);
		ft_end_game(mem);
	}
	item_list->first = NULL;
	item_list->last = NULL;
	item_list->total = 0;
	item_list->i_tag = 'C';
	return (item_list);
}

t_item	*ft_alloc_item(t_mem *mem, int i, int j)
{
	t_item	*item;

	item = (t_item *) malloc (sizeof(t_item));
	if (!item)
	{
		ft_putstr_fd("Error.\nMemory allocation error.\n", 2);
		ft_end_game(mem);
	}
	item->posx = i;
	item->posy = j;
	item->next = item;
	item->prev = item;
	return (item);
}

void	ft_fill_item_list(t_mem *mem, int i, int j)
{
	t_item	*item;

	item = ft_alloc_item(mem, i, j);
	if (mem->item_list->total == 0)
		mem->item_list->last = item;
	else
	{
		item->next = mem->item_list->first;
		mem->item_list->first->prev = item;
		item->prev = mem->item_list->last;
		mem->item_list->last->next = item;
	}
	mem->item_list->first = item;
	mem->item_list->total++;
}
