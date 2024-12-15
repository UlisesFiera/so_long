/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:28:29 by ulfernan          #+#    #+#             */
/*   Updated: 2024/12/15 20:53:42 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

void	redraw(t_data_load *load, int new_x, int new_y)
{
	static int	count = 1;

	mlx_put_image_to_window(load->mlx, load->win, load->floor_texture.img,
		load->player_texture.x, load->player_texture.y);
	load->player_texture.x = new_x;
	load->player_texture.y = new_y;
	mlx_put_image_to_window(load->mlx, load->win, load->player_texture.img,
		new_x, new_y);
	ft_printf("Player steps: %d\n", count++);
}

void	move(int keycode, t_data_load *load)
{
	int	new_x;
	int	new_y;

	new_x = load->player_texture.x;
	new_y = load->player_texture.y;
	if (keycode == 119 || keycode == 115 || keycode == 97 || keycode == 100)
	{
		if (keycode == 119)
			new_y -= load->pixel_y;
		else if (keycode == 115)
			new_y += load->pixel_y;
		else if (keycode == 97)
			new_x -= load->pixel_x;
		else if (keycode == 100)
			new_x += load->pixel_x;
		if (!collision(load, new_x, new_y))
			redraw(load, new_x, new_y);
	}
}
