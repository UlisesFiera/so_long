/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:54:34 by ulfernan          #+#    #+#             */
/*   Updated: 2024/12/18 17:08:21 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

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
	if (sides_top_bot(load))
		return (1);
	return (0);
}
