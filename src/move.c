/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:28:29 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/12 19:24:44 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

int	exit_player_load(t_data_load *load, int new_x, int new_y)
{
	load->exit_player_texture.img = mlx_xpm_file_to_image(
			load->mlx, "./assets/exit_player.xpm",
			&load->exit_player_texture.width,
			&load->exit_player_texture.height);
	if (!load->exit_player_texture.img)
		return (1);
	load->exit_player_texture.addr = mlx_get_data_addr(
			load->exit_player_texture.img,
			&load->exit_player_texture.bits_per_pixel,
			&load->exit_player_texture.line_length, &load->wall_texture.endian);
	mlx_put_image_to_window(load->mlx, load->win, load->exit_player_texture.img,
		new_x, new_y);
	return (0);
}

void	redraw(t_data_load *load, int new_x, int new_y)
{
	static int	count = 1;

	mlx_put_image_to_window(load->mlx, load->win, load->floor_texture.img,
		load->player_texture.x, load->player_texture.y);
	load->player_texture.x = new_x;
	load->player_texture.y = new_y;
	mlx_put_image_to_window(load->mlx, load->win, load->player_texture.img,
		new_x, new_y);
	load->player_texture.x = new_x;
	load->player_texture.y = new_y;
	if (((load->player_texture.x == load->exit_texture.x)
			&& (load->player_texture.y == load->exit_texture.y)))
		exit_player_load(load, new_x, new_y);
	else if (!((load->player_texture.x == load->exit_texture.x)
			&& (load->player_texture.y == load->exit_texture.y)))
		texture_put(load, 'E');
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
