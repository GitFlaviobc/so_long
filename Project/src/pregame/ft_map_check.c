/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:55:31 by fbonini-          #+#    #+#             */
/*   Updated: 2021/09/14 15:56:26 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_check(t_mem *mem)
{
	ft_wall_check(mem, mem->map->col_numb, mem->map->line_size);
	ft_check_element(mem, 'P', &mem->player->posx, &mem->player->posy);
	ft_check_element(mem, 'E', &mem->gate->posx, &mem->gate->posy);
	ft_list_check(mem);
}

void	ft_wall_check(t_mem *mem, size_t col, size_t line)
{
	size_t	i;

	i = 0;
	while (i < line)
	{
		if (mem->design_map[0][i] != '1' || mem->design_map[col - 1][i] != '1')
		{
			ft_putstr_fd("Error.\nInvalid map, fix outside the walls.\n", 2);
			ft_end_game(mem);
		}
		i++;
	}
	i = 0;
	while (i < col)
	{
		if (mem->design_map[i][0] != '1' || mem->design_map[i][line - 1] != '1')
		{
			ft_putstr_fd("Error.\nInvalid map, fix outside the walls.\n", 2);
			ft_end_game(mem);
		}
		i++;
	}
}

void	ft_check_element(t_mem *mem, char tag, int *x, int *y)
{
	size_t	i;
	size_t	j;
	int		has_it;

	i = 0;
	has_it = 0;
	while (i < mem->map->col_numb)
	{
		j = 0;
		while (j < mem->map->line_size)
		{
			if (mem->design_map[i][j] == tag)
			{
				has_it = 1;
				*x = i;
				*y = j;
			}
			else if (mem->design_map[i][j] == tag)
				mem->design_map[i][j] = mem->map->f_tag;
			j++;
		}
		i++;
	}
	ft_error_map(mem, has_it);
}

void	ft_list_check(t_mem *mem)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < mem->map->col_numb)
	{
		j = 0;
		while (j < mem->map->line_size)
		{
			if (mem->design_map[i][j] == mem->item_list->i_tag)
				ft_fill_item_list(mem, i, j);
			if (mem->design_map[i][j] == 'H' || mem->design_map[i][j] == 'V')
				ft_fill_enemy_list(mem, i, j, mem->design_map[i][j]);
			j++;
		}
		i++;
	}
	ft_error_map(mem, mem->item_list->total);
}

void	ft_error_map(t_mem *mem, int check)
{
	if (check == 0)
	{
		ft_putstr_fd("Error.\nInvalid map, missing main elements.\n", 2);
		ft_end_game(mem);
	}
}
