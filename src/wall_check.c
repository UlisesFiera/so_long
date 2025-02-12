/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:54:34 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/12 18:31:20 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

int	side_left(t_data_load *load)
{
	int		i;

	map_copy(load);
	i = 0;
	while (load->map_matrix[i])
	{
		if (load->map_matrix[i][0] != '1')
		{
			ft_printf("Left side not closed by walls\n");
			free_matrix(load);
			return (1);
		}
		i++;
	}
	free_matrix(load);
	return (0);
}

int	side_right(t_data_load *load)
{
	int		i;
	int		j;

	map_copy(load);
	i = 0;
	while (load->map_matrix[i])
	{
		j = 0;
		while (load->map_matrix[i][j] != '\0')
			j++;
		if (load->map_matrix[i][--j] != '1')
		{
			ft_printf("Right side not closed by walls\n");
			free_matrix(load);
			return (1);
		}
		i++;
	}
	free_matrix(load);
	return (0);
}

int	row_check(t_data_load *load)
{
	int		fd;
	int		size;
	int		size_rest;
	char	*line;

	fd = open(load->map, O_RDONLY);
	line = get_next_line(fd);
	size = line_size(line);
	while (line)
	{
		size_rest = line_size(line);
		if (size != size_rest)
		{
			ft_printf("Error: all map rows must be the same size\n");
			free(line);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	load->map_width = size;
	return (0);
}

int	wall_check(t_data_load *load)
{
	if (row_check(load))
		return (1);
	if (top_check(load))
		return (1);
	if (bot_check(load))
		return (1);
	if (side_left(load))
		return (1);
	if (side_right(load))
		return (1);
	return (0);
}
