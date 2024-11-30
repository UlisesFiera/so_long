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

void	*mapping(t_data_load *load)
{
	load->img = mlx_xpm_file_to_image(load->mlx, "./image_test.xpm", 
										&load->img_width, &load->img_height);
	if (!load->img)
	{
		mlx_destroy_window(load->mlx, load->win);
		free(load->mlx);
		return (NULL);
	}
	load->addr = mlx_get_data_addr(load->img, &load->bits_per_pixel, &load->line_length,
									&load->endian);
	mlx_put_image_to_window(load->mlx, load->win, load->img, 0, 0);
}

void	*initialize(t_data_load *load)
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
	return (load->win);
}

int	main(void)
{
	t_data_load	load;

	if (!initialize(&load))
		return (0);
	if (!mapping(&load))
		return (0);
	esc_window(&load);
	mlx_loop(load.mlx);
	mlx_destroy_display(load.mlx);
	free(load.mlx);
	return (0);
}



// ft_pixel_put(&load, 300, 200, 0x00FF0000);