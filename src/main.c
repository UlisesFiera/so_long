/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:34:24 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/19 08:00:37 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

int	map_check(t_data_load *load)
{
	if (char_check(load))
		return (1);
	if (wall_check(load))
		return (1);
	if (load->map_height < 3)
	{
		ft_printf("Error: Min height: 3 rows\n");
		return (1);
	}
	if (load->map_height > load->map_width)
	{
		ft_printf("Error: not a rectangular map\n");
		return (1);
	}
	if (backtracking(load))
	{
		ft_printf("Error: invalid map\n");
		return (1);
	}
	return (0);
}

void	*initialize(t_data_load *load)
{
	load->mlx = mlx_init();
	load->pixel_x = 96;
	load->pixel_y = 99;
	if (!load->mlx)
	{
		free_load(load);
		ft_printf("Error: mlx failure\n");
		return (NULL);
	}
	load->win = mlx_new_window(load->mlx, (load->map_width * load->pixel_x),
			(load->map_height * load->pixel_y), "./so long");
	if (!load->win)
	{
		free_load(load);
		ft_printf("Error: couldn't create window\n");
		return (NULL);
	}
	map_copy(load);
	load->collected = 0;
	free_matrix(load);
	return (load->win);
}

int	mapping(char *map, t_data_load *load)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: couldn't read map // map not provided\n");
		return (1);
	}
	line = get_next_line(fd);
	while (line != NULL && line[0] != '\n')
	{
		load->map_height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close (fd);
	if (map_check(load))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
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
	if (load_textures(&load))
	{
		ft_printf("Error: texture load failure\n");
		return (1);
	}
	triggers(&load);
	mlx_loop(load.mlx);
	free_load(&load);
	return (0);
}
