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

void	mapping(t_data *img, t_data *load)
{
	img->img = mlx_xpm_file_to_image(img->mlx, "./image_test.xpm", 
										img->img_width, img->img_height);
	if (!img->img)
	{
		mlx_destroy_window(load->mlx, load->win);
		free(load->mlx);
		return ();
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
									&img->endian);
		mlx_put_image_to_window(load->mlx, load->win, img->img, 0, 0);
}

void	initialize(t_data *load)
{
	load->mlx = mlx_init();
	if (!load->mlx)
		return ();
	load->win = mlx_new_window(load->mlx, 600, 400, "So long");
	if (!load->win)
	{
		free(load->mlx);
		return ();
	}
	return (load->win);
}

int	main(void)
{
	t_data	load;
	t_data	img;

	if (!initialize(&load))
		return (0);
	if (!mapping(&img, &load))
		return (0);
	esc_window(&load);
	mlx_loop(load.mlx);
	mlx_destroy_display(load.mlx);
	free(load.mlx);
	return (0);
}



// ft_pixel_put(&load, 300, 200, 0x00FF0000);