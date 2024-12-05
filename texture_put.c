/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:18:52 by ulfernan          #+#    #+#             */
/*   Updated: 2024/12/05 15:18:52 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

void	texture_put(t_data_load *load, t_data_texture *floor_texture)
{
	int		i;
	int		j;
	int		x;
	int		y;

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
}