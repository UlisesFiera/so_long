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
	int		i;
	int		j;
	int		y;
	int		x;

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
	i = 0;
	y = 0;
	while (i < load->map_height)
	{
		x = 0;
		j = 0;
		while (j < load->map_width)
		{
			mlx_put_image_to_window(load->mlx, load->win, floor_texture->img, x, y);
			x += floor_texture->width;
			j++;
		}
		y += floor_texture->height;
		i++;
	}
	return (0);
}

int		load_textures(t_data_load *load)
{
	t_data_texture		floor_texture;

	ft_memset(&floor_texture, 0, sizeof(t_data_texture));
	floor_load(load, &floor_texture);
	return (0);
}