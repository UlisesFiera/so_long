/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:18:52 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/05 14:04:55 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

void	sprite_put(
	t_data_load *load, t_data_texture *sprite_texture, char option)
{
	int		i;
	int		j;

	map_copy(load);
	i = 0;
	while (load->map_matrix[i])
	{
		j = 0;
		while (load->map_matrix[i][j])
		{
			if ((char) load->map_matrix[i][j] == option)
			{
				sprite_texture->x = sprite_texture->width * j;
				sprite_texture->y = sprite_texture->height * i;
				mlx_put_image_to_window(load->mlx, load->win,
					sprite_texture->img,
					sprite_texture->x, sprite_texture->y);
			}
			j++;
		}
		i++;
	}
	free_matrix(load);
}

void	texture_put(t_data_load *load, char option)
{
	if (option == '0')
		sprite_put(load, &load->floor_texture, option);
	if (option == '1')
		sprite_put(load, &load->wall_texture, option);
	if (option == 'P')
		sprite_put(load, &load->player_texture, option);
	if (option == 'C')
		sprite_put(load, &load->collectible_texture, option);
	if (option == 'E')
		sprite_put(load, &load->exit_texture, option);
}
