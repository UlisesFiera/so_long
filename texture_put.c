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

void	texture_put(t_data_load *load, t_data_texture *texture, int option)
{
	if (option == 0)
		floor_put(&load, &texture);
	if (option == 1)
		sprite_put(&load, &texture, option);
}

void	floor_put(t_data_load *load, t_data_texture *floor_texture)
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

void	sprite_put(t_data_load *load, t_data_texture *sprite_texture, int option)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	option = 1;
	fd = open(load->map, O_RDONLY);
	line = get_next_line;
	i = 0;
	while (line != NULL)
	{
		j = 0;
		while (line[j++])
		{
			if (line[j] == option)
			mlx_put_image_to_window(load->mlx, load->win, sprite_texture->img, 
									(sprite_texture->width * j), (sprite_texture->width * i));
		}
		i++;
		free(line);
		line = get_next_line;
	}
	close(fd);
}