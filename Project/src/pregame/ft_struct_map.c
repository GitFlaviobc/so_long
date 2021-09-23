/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 10:28:08 by fbonini-          #+#    #+#             */
/*   Updated: 2021/09/07 16:47:57 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*ft_alloc_map(t_mem *mem)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
	{
		ft_putstr_fd("Error.\nMemory allocation error.\n", 2);
		ft_end_game(mem);
	}
	map->line = 0;
	map->col = 0;
	map->col_numb = 0;
	map->line_size = 0;
	map->w_tag = 1;
	map->f_tag = 0;
	return (map);
}

void	ft_alloc_mapdesign(t_mem *mem)
{
	size_t	i;

	i = 0;
	mem->design_map = (char **)malloc(mem->map->col_numb * sizeof(char *));
	while (i < mem->map->col_numb)
	{
		mem->design_map[i] = malloc((mem->map->line_size + 1) * sizeof(char));
		i++;
	}
}
