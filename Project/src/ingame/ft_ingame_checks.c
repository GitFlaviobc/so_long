/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ingame_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:32:53 by fbonini-          #+#    #+#             */
/*   Updated: 2021/09/14 10:36:14 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	ft_check_future_space(t_mem *mem, int key, int x, int y)
{
	char	move;
	char	*get_move;

	get_move = (char *) malloc ((MOVEMENTS + 1) * sizeof(char));
	if (!get_move)
	{
		ft_putstr_fd("Error.\nMemory allocation error.\n", 2);
		ft_end_game(mem);
	}
	get_move[0] = mem->design_map[x][y - 1];
	get_move[1] = mem->design_map[x - 1][y];
	get_move[2] = mem->design_map[x + 1][y];
	get_move[3] = mem->design_map[x][y + 1];
	get_move[4] = '\0';
	move = get_move[key];
	free(get_move);
	return (move);
}

void	ft_check_exit(t_mem *mem, unsigned int items)
{
	if (items == 0)
		ft_end_game(mem);
}
