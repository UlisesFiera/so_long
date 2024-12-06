/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:11:09 by ulfernan          #+#    #+#             */
/*   Updated: 2024/12/06 11:36:04 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

int		player_load(t_data_load *load, t_data_texture *player_texture)
{
	player_texture->img = mlx_xpm_file_to_image(load->mlx, "./assets/player.xpm", 
										&player_texture->width, &player_texture->height);
	if (!player_texture->img)
	{
		mlx_destroy_window(load->mlx, load->win);
		free(load->mlx);
		return (1);
	}
	player_texture->addr = mlx_get_data_addr(player_texture->img, &player_texture->bits_per_pixel, 
									&player_texture->line_length, &player_texture->endian);
	texture_put(load, player_texture, 'P');
	return (0);
}

int		collectible_load(t_data_load *load, t_data_texture *collectible_texture)
{
	collectible_texture->img = mlx_xpm_file_to_image(load->mlx, "./assets/collectible.xpm", 
										&collectible_texture->width, &collectible_texture->height);
	if (!collectible_texture->img)
	{
		mlx_destroy_window(load->mlx, load->win);
		free(load->mlx);
		return (1);
	}
	collectible_texture->addr = mlx_get_data_addr(collectible_texture->img, &collectible_texture->bits_per_pixel, 
									&collectible_texture->line_length, &collectible_texture->endian);
	texture_put(load, collectible_texture, 'C');
	return (0);
}

int		wall_load(t_data_load *load, t_data_texture *wall_texture)
{
	wall_texture->img = mlx_xpm_file_to_image(load->mlx, "./assets/wall.xpm", 
										&wall_texture->width, &wall_texture->height);
	if (!wall_texture->img)
	{
		mlx_destroy_window(load->mlx, load->win);
		free(load->mlx);
		return (1);
	}
	wall_texture->addr = mlx_get_data_addr(wall_texture->img, &wall_texture->bits_per_pixel, 
									&wall_texture->line_length, &wall_texture->endian);
	texture_put(load, wall_texture, '1');
	return (0);
}

int		floor_load(t_data_load *load, t_data_texture *floor_texture)
{
	floor_texture->img = mlx_xpm_file_to_image(load->mlx, "./assets/floor_sprite.xpm", 
										&floor_texture->width, &floor_texture->height);
	if (!floor_texture->img)
	{
		mlx_destroy_window(load->mlx, load->win);
		free(load->mlx);
		return (1);
	}
	floor_texture->addr = mlx_get_data_addr(floor_texture->img, &floor_texture->bits_per_pixel, 
									&floor_texture->line_length, &floor_texture->endian);
	texture_put(load, floor_texture, '0');
	return (0);
}

int		load_textures(t_data_load *load)
{
	t_data_texture		floor_texture;
	t_data_texture		wall_texture;
	t_data_texture		collectible_texture;
	t_data_texture		player_texture;

	ft_memset(&floor_texture, 0, sizeof(t_data_texture));
	floor_load(load, &floor_texture);
	ft_memset(&wall_texture, 0, sizeof(t_data_texture));
	wall_load(load, &wall_texture);
	ft_memset(&collectible_texture, 0, sizeof(t_data_texture));
	collectible_load(load, &collectible_texture);
	ft_memset(&player_texture, 0, sizeof(t_data_texture));
	player_load(load, &player_texture);
	return (0);
}