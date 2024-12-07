/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:34:24 by ulfernan          #+#    #+#             */
/*   Updated: 2024/12/07 11:25:54 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

void	*initialize(t_data_load *load)
{
	load->mlx = mlx_init();
	load->pixel_x = 96;
	load->pixel_y = 99;
	if (!load->mlx)
	{
		ft_printf("Error: mlx failure\n");
		return (NULL);
	}
	load->win = mlx_new_window(load->mlx, (load->map_width * load->pixel_x), 
								(load->map_height * load->pixel_y), "./so long");
	if (!load->win)
	{
		ft_printf("Error: couldn't create window\n");
		return (NULL);
	}
	return (load->win);
}

int		mapping(char *map, t_data_load *load)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: couldn't read map file\n");
		return (1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		load->map_height++;
		load->map_width = ft_strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	if (map_check(load))
	{
		ft_printf("Error: invalid map\n");
		return (1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_data_load	load;

	ft_memset(&load, 0, sizeof(t_data_load));
	if (argc > 2)
	{
		ft_printf("Error: one '.ber' file only\n");
		return (1);
	}
	load.map = argv[1];
	if (mapping(load.map, &load))
		return (1);
	if (initialize(&load) == NULL)
	{
		ft_printf("Error: couldn't initialize game\n");
		return (1);
	}
	load_textures(&load);
	esc_window(&load);
	mlx_loop(load.mlx);
	mlx_destroy_display(load.mlx);
	free(load.mlx);
	return (0);
}



// ft_pixel_put(&load, 300, 200, 0x00FF0000);
// ft_printf("Hi!\n");