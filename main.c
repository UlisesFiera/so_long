/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:34:24 by ulfernan          #+#    #+#             */
/*   Updated: 2024/11/28 11:34:24 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

void	*initialize(t_data *load)
{
	load->mlx = mlx_init();
	if (!load->mlx)
		return (NULL);
	load->win = mlx_new_window(load->mlx, 600, 400, "So long");
	if (!load->win)
	{
		free(load->mlx);
		return (NULL);
	}
	load->img = mlx_new_image(load->mlx, 600, 400);
	if (!load->img)
	{
		mlx_destroy_window(load->mlx, load->win);
		free(load->mlx);
		return (NULL);
	}
	load->addr = mlx_get_data_addr(load->img, &load->bits_per_pixel, &load->line_length,
								&load->endian);
	return (load->win);
}

int	main(void)
{
	t_data	load;

	if (!initialize(&load))
		return (0);
	ft_pixel_put(&load, 300, 200, 0x00FF0000);
	mlx_put_image_to_window(load.mlx, load.win, load.img, 0, 0);
	esc_window(&load);
	mlx_loop(load.mlx);
	return (0);
}
