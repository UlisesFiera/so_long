/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:11:09 by ulfernan          #+#    #+#             */
/*   Updated: 2024/11/30 13:11:09 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*img_load(t_data_load *load)
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