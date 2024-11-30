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

void	*initialize(t_data_load *load)
{
	load->mlx = mlx_init();
	if (!load->mlx)
		return (NULL);
	load->win = mlx_new_window(load->mlx, load->img_height, load->img_width, "./so long");
	if (!load->win)
	{
		free(load->mlx);
		return (NULL);
	}
	return (load->win);
}

void	*mapping(char *map, t_data_load load)
{
	int		fd;
	char	*line;
	int		pixel;

	pixel = 16;
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		perror("Couldn't read file");
		return (NULL);
	}
	while ((!line = get_next_line(fd)))
	{
		load->img_height++;
		load->img_width = ft_strlen(line);
		free(line);
	}
	close (fd);
	load->img_height * pixel;
	load->img_width * pixel;
}


int		main(int argc, char **argv)
{
	t_data_load	load;
	
	load.map = argv[1];
	if (!mapping(load.map, &load))
		return (0);
	if (!initialize(&load))
		return (0);
	esc_window(&load);
	mlx_loop(load.mlx);
	mlx_destroy_display(load.mlx);
	free(load.mlx);
	return (0);
}



// ft_pixel_put(&load, 300, 200, 0x00FF0000);