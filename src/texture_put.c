/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:18:52 by ulfernan          #+#    #+#             */
/*   Updated: 2024/12/12 19:44:42 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

void	sprite_put(t_data_load *load, t_data_texture *sprite_texture, char option)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	fd = open(load->map, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		j = 0;
		while (line[j])
		{
			sprite_texture->y = sprite_texture->height * i;
			if ((char) line[j] == option)
			{
				sprite_texture->x = sprite_texture->width * j;
				mlx_put_image_to_window(load->mlx, load->win, sprite_texture->img, 
										(sprite_texture->width * j), (sprite_texture->height * i));
			}
			j++;
		}
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
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
}