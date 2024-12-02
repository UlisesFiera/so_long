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
	int		y;
	int		x;
	

	y = 645;
	x = 456;
	floor_texture->img = mlx_xpm_file_to_image(load->mlx, "./assets/floor.xpm", 
										&floor_texture->width, &floor_texture->height);
	if (!floor_texture->img)
	{
		mlx_destroy_window(load->mlx, load->win);
		free(load->mlx);
		return (1);
	}
	mlx_new_image(load->mlx, 96, 98);
	floor_texture->addr = mlx_get_data_addr(floor_texture->img, &floor_texture->bits_per_pixel, 
									&floor_texture->line_length, &floor_texture->endian);
	
	mlx_put_image_to_window(load->mlx, load->win, floor_texture->img, 0, 0);
	return (0);
}

int		load_textures(t_data_load *load)
{
	t_data_texture		floor_texture;

	ft_memset(&floor_texture, 0, sizeof(t_data_texture));
	floor_load(load, &floor_texture);
	return (0);
}