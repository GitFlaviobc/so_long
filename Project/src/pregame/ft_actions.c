/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:58:09 by fbonini-          #+#    #+#             */
/*   Updated: 2021/09/14 14:58:28 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_actions	*ft_alloc_actions(t_mem *mem)
{
	t_actions	*action;

	action = (t_actions *) malloc (sizeof(t_actions));
	if (!action)
	{
		ft_putstr_fd("Error.\nMemory allocation error.\n", 2);
		ft_end_game(mem);
	}
	ft_get_actions(&action->function[0]);
	return (action);
}

void	ft_get_actions(t_funct *function)
{
	int	i;

	i = 0;
	function[i] = &ft_move_left;
	function[++i] = &ft_move_up;
	function[++i] = &ft_move_down;
	function[++i] = &ft_move_right;
	function[++i] = &ft_end_game;
}
