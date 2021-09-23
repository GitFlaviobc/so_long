/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:59:06 by fbonini-          #+#    #+#             */
/*   Updated: 2021/09/07 15:30:18 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_key	*ft_alloc_keys(t_mem *mem)
{
	t_key	*keys;

	keys = (t_key *) malloc (sizeof(t_key));
	if (!keys)
	{
		ft_putstr_fd("Error.\nMemory allocation error.\n", 2);
		ft_end_game(mem);
	}
	ft_get_keys(&keys->key[0]);
	return (keys);
}

void	ft_get_keys(int *key)
{
	int	i;

	i = 0;
	key[i] = A;
	key[++i] = W;
	key[++i] = S;
	key[++i] = D;
	key[++i] = ESC;
}

int	ft_valid_key(t_mem *mem, int key)
{
	int	i;

	i = 0;
	while (i < TOTAL_ACTIONS)
	{
		if (key == mem->keys->key[i])
			return (i);
		i++;
	}
	return (i);
}
