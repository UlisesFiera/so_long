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

void	*floor(t_data_load *load)
{
	load->img = mlx_xpm_file_to_image(load->mlx, "./assets/floor.xpm", 
										456, 645);
	if (!load->img)
	{
		mlx_destroy_window(load->mlx, load->win);
		free(load->mlx);
		return (0);
	}
	load->addr = mlx_get_data_addr(load->img, &load->bits_per_pixel, &load->line_length,
									&load->endian);
	mlx_put_image_to_window(load->mlx, load->win, load->img, 0, 0);
	return (0);
}

int		load_textures(t_data_load *load)
{
	floor(&load);
}