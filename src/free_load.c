/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:59:46 by ulfernan          #+#    #+#             */
/*   Updated: 2024/12/12 18:16:47 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

void	free_load(t_data_load *load)
{
	if (load->player_texture.img)
		mlx_destroy_image(load->mlx, load->player_texture.img);
	if (load->wall_texture.img)
		mlx_destroy_image(load->mlx, load->wall_texture.img);
	if (load->floor_texture.img)
		mlx_destroy_image(load->mlx, load->floor_texture.img);
	if (load->collectible_texture.img)
		mlx_destroy_image(load->mlx, load->collectible_texture.img);
	if (load->win)
		mlx_destroy_window(load->mlx, load->win);
	if (load->mlx)
		mlx_destroy_display(load->mlx);
	free(load->mlx);

}