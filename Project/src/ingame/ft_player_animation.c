/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_animation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 19:11:29 by fbonini-          #+#    #+#             */
/*   Updated: 2021/09/14 15:54:30 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_player_animation(t_mem *mem, int (*funct)())
{
	return (funct(mem));
}

int	ft_player_ani_up(t_mem *mem)
{
	mem->ani_player = 1;
	mlx_destroy_image(mem->server->mlx, mem->player->img.img);
	mem->player->img = ft_load_image(mem, mem->server->mlx, "art/chk_u00.xpm");
	ft_render_next_frame(mem);
	mlx_destroy_image(mem->server->mlx, mem->player->img.img);
	mem->player->img = ft_load_image(mem, mem->server->mlx, "art/chk_u01.xpm");
	ft_render_next_frame(mem);
	mlx_destroy_image(mem->server->mlx, mem->player->img.img);
	mem->player->img = ft_load_image(mem, mem->server->mlx, "art/chk_u02.xpm");
	ft_render_next_frame(mem);
	mlx_destroy_image(mem->server->mlx, mem->player->img.img);
	mem->player->img = ft_load_image(mem, mem->server->mlx, "art/chk_u00.xpm");
	mem->ani_player = 0;
	return (0);
}

int	ft_player_ani_right(t_mem *mem)
{
	mem->ani_player = 1;
	mlx_destroy_image(mem->server->mlx, mem->player->img.img);
	mem->player->img = ft_load_image(mem, mem->server->mlx, "art/chk_r00.xpm");
	ft_render_next_frame(mem);
	mlx_destroy_image(mem->server->mlx, mem->player->img.img);
	mem->player->img = ft_load_image(mem, mem->server->mlx, "art/chk_r01.xpm");
	ft_render_next_frame(mem);
	mlx_destroy_image(mem->server->mlx, mem->player->img.img);
	mem->player->img = ft_load_image(mem, mem->server->mlx, "art/chk_r02.xpm");
	ft_render_next_frame(mem);
	mlx_destroy_image(mem->server->mlx, mem->player->img.img);
	mem->player->img = ft_load_image(mem, mem->server->mlx, "art/chk_r00.xpm");
	mem->ani_player = 0;
	return (0);
}

int	ft_player_ani_left(t_mem *mem)
{
	mem->ani_player = 1;
	mlx_destroy_image(mem->server->mlx, mem->player->img.img);
	mem->player->img = ft_load_image(mem, mem->server->mlx, "art/chk_l00.xpm");
	ft_render_next_frame(mem);
	mlx_destroy_image(mem->server->mlx, mem->player->img.img);
	mem->player->img = ft_load_image(mem, mem->server->mlx, "art/chk_l01.xpm");
	ft_render_next_frame(mem);
	mlx_destroy_image(mem->server->mlx, mem->player->img.img);
	mem->player->img = ft_load_image(mem, mem->server->mlx, "art/chk_l02.xpm");
	ft_render_next_frame(mem);
	mlx_destroy_image(mem->server->mlx, mem->player->img.img);
	mem->player->img = ft_load_image(mem, mem->server->mlx, "art/chk_l00.xpm");
	mem->ani_player = 0;
	return (0);
}

int	ft_player_ani_down(t_mem *mem)
{
	mem->ani_player = 1;
	mlx_destroy_image(mem->server->mlx, mem->player->img.img);
	mem->player->img = ft_load_image(mem, mem->server->mlx, "art/chk_d00.xpm");
	ft_render_next_frame(mem);
	mlx_destroy_image(mem->server->mlx, mem->player->img.img);
	mem->player->img = ft_load_image(mem, mem->server->mlx, "art/chk_d01.xpm");
	ft_render_next_frame(mem);
	mlx_destroy_image(mem->server->mlx, mem->player->img.img);
	mem->player->img = ft_load_image(mem, mem->server->mlx, "art/chk_d02.xpm");
	ft_render_next_frame(mem);
	mlx_destroy_image(mem->server->mlx, mem->player->img.img);
	mem->player->img = ft_load_image(mem, mem->server->mlx, "art/chk_d00.xpm");
	mem->ani_player = 0;
	return (0);
}
