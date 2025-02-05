/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:11:08 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/05 13:33:48 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

int	collectible_load(t_data_load *load)
{
	load->collectible_texture.img = mlx_xpm_file_to_image(
			load->mlx, "./assets/collectible.xpm",
			&load->collectible_texture.width,
			&load->collectible_texture.height);
	if (!load->collectible_texture.img)
		return (1);
	load->collectible_texture.addr = mlx_get_data_addr(
			load->collectible_texture.img,
			&load->collectible_texture.bits_per_pixel,
			&load->collectible_texture.line_length,
			&load->collectible_texture.endian);
	texture_put(load, 'C');
	return (0);
}

int	wall_load(t_data_load *load)
{
	load->wall_texture.img = mlx_xpm_file_to_image(
			load->mlx, "./assets/wall.xpm",
			&load->wall_texture.width,
			&load->wall_texture.height);
	if (!load->wall_texture.img)
		return (1);
	load->wall_texture.addr = mlx_get_data_addr(
			load->wall_texture.img,
			&load->wall_texture.bits_per_pixel,
			&load->wall_texture.line_length, &load->wall_texture.endian);
	texture_put(load, '1');
	return (0);
}

int	floor_load(t_data_load *load)
{
	load->floor_texture.img = mlx_xpm_file_to_image(
			load->mlx, "./assets/floor.xpm",
			&load->floor_texture.width,
			&load->floor_texture.height);
	if (!load->floor_texture.img)
		return (1);
	load->floor_texture.addr = mlx_get_data_addr(
			load->floor_texture.img,
			&load->floor_texture.bits_per_pixel,
			&load->floor_texture.line_length, &load->floor_texture.endian);
	texture_put(load, '0');
	return (0);
}

int	exit_load(t_data_load *load)
{
	load->exit_texture.img = mlx_xpm_file_to_image(
			load->mlx, "./assets/exit.xpm",
			&load->exit_texture.width,
			&load->exit_texture.height);
	if (!load->exit_texture.img)
		return (1);
	load->exit_texture.addr = mlx_get_data_addr(
			load->exit_texture.img,
			&load->exit_texture.bits_per_pixel,
			&load->exit_texture.line_length, &load->exit_texture.endian);
	texture_put(load, 'E');
	return (0);
}

int	background(t_data_load *load)
{
	if (collectible_load(load) || wall_load(load)
		|| floor_load(load) || exit_load(load))
		return (1);
	return (0);
}
