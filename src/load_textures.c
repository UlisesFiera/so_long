/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:11:09 by ulfernan          #+#    #+#             */
/*   Updated: 2024/12/12 16:19:16 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

int		player_load(t_data_load *load)
{
	load->player_texture.img = mlx_xpm_file_to_image(load->mlx, "./assets/player.xpm", 
										&load->player_texture.width, &load->player_texture.height);
	if (!load->player_texture.img)
		return (1);
	load->player_texture.addr = mlx_get_data_addr(load->player_texture.img, &load->player_texture.bits_per_pixel, 
									&load->player_texture.line_length, &load->player_texture.endian);
	texture_put(load, 'P');
	return (0);
}

int		collectible_load(t_data_load *load)
{
	load->collectible_texture.img = mlx_xpm_file_to_image(load->mlx, "./assets/collectible.xpm", 
										&load->collectible_texture.width, &load->collectible_texture.height);
	if (!load->collectible_texture.img)
		return (1);
	load->collectible_texture.addr = mlx_get_data_addr(load->collectible_texture.img, &load->collectible_texture.bits_per_pixel, 
									&load->collectible_texture.line_length, &load->collectible_texture.endian);
	texture_put(load, 'C');
	return (0);
}

int		wall_load(t_data_load *load)
{
	load->wall_texture.img = mlx_xpm_file_to_image(load->mlx, "./assets/wall.xpm", 
										&load->wall_texture.width, &load->wall_texture.height);
	if (!load->wall_texture.img)
		return (1);
	load->wall_texture.addr = mlx_get_data_addr(load->wall_texture.img, &load->wall_texture.bits_per_pixel, 
									&load->wall_texture.line_length, &load->wall_texture.endian);
	texture_put(load, '1');
	return (0);
}

int		floor_load(t_data_load *load)
{
	load->floor_texture.img = mlx_xpm_file_to_image(load->mlx, "./assets/floor_sprite.xpm", 
										&load->floor_texture.width, &load->floor_texture.height);
	if (!load->floor_texture.img)
		return (1);
	load->floor_texture.addr = mlx_get_data_addr(load->floor_texture.img, &load->floor_texture.bits_per_pixel, 
									&load->floor_texture.line_length, &load->floor_texture.endian);
	texture_put(load, '0');
	return (0);
}

int		load_textures(t_data_load *load)
{
	if (floor_load(load) || wall_load(load) || collectible_load(load) || player_load(load))
	{
		free_load(load);
		return (1);
	}
	return (0);
}


	