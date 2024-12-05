/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:11:09 by ulfernan          #+#    #+#             */
/*   Updated: 2024/11/30 13:11:09 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

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
	texture_put(load, floor_texture);
	return (0);
}

int		load_textures(t_data_load *load)
{
	t_data_texture		floor_texture;
	t_data_texture		wall_texture;

	ft_memset(&floor_texture, 0, sizeof(t_data_texture));
	floor_load(load, &floor_texture);
	ft_memset(&wall_texture, 0, sizeof(t_data_texture));
	wall_load(load, &wall_texture);
	return (0);
}