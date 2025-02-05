/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:54:34 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/05 14:11:44 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

int	sides(t_data_load *load)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(load->map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] != '1')
		{
			ft_printf("Left side not closed by walls\n");
			free(line);
			close(fd);
			return (1);
		}
		while (line[i + 1] != '\0' && line[i + 1] != '\n')
			i++;
		if (line[i] != '1')
		{
			ft_printf("Right side not closed by walls\n");
			free(line);
			close(fd);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
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
	map_copy(load);
	if (row_check(load))
		return (1);
	if (top_check(load))
		return (1);
	if (bot_check(load))
		return (1);
	if (sides(load))
		return (1);
	free_matrix(load);
	return (0);
}
