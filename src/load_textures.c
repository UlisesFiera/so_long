/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:11:09 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/19 07:58:41 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

int	player_load(t_data_load *load)
{
	load->player_texture.img = mlx_xpm_file_to_image(
			load->mlx, "./assets/player.xpm",
			&load->player_texture.width, &load->player_texture.height);
	if (!load->player_texture.img)
		return (1);
	load->player_texture.addr = mlx_get_data_addr(
			load->player_texture.img, &load->player_texture.bits_per_pixel,
			&load->player_texture.line_length, &load->player_texture.endian);
	texture_put(load, 'P');
	return (0);
}

int	load_textures(t_data_load *load)
{
	if (player_load(load))
	{
		free_load(load);
		return (1);
	}
	if (background(load))
	{
		free_load(load);
		return (1);
	}
	return (0);
}
