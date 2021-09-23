/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 08:37:09 by fbonini-          #+#    #+#             */
/*   Updated: 2021/09/07 15:29:28 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_extension(char *file, char *ext)
{
	while (*file && *file != '.')
		file++;
	if (!ft_strncmp(file, ext, 4))
		return (SUCCESS);
	ft_putstr_fd("Error.\nWrong file extension.\n", 2);
	exit (EXIT_FAILURE);
}
