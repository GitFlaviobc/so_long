/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_exit_gate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:58:47 by fbonini-          #+#    #+#             */
/*   Updated: 2021/09/14 15:57:01 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_gate	*ft_alloc_exit_gate(t_mem *mem)
{
	t_gate	*gate;

	gate = (t_gate *)malloc(sizeof(t_gate));
	if (!gate)
	{
		ft_putstr_fd("Error.\nMemory allocation error.\n", 2);
		ft_end_game(mem);
	}
	gate->posx = 0;
	gate->posy = 0;
	gate->tag = 'E';
	return (gate);
}
