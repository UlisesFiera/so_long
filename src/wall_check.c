
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:54:34 by ulfernan          #+#    #+#             */
/*   Updated: 2024/12/12 17:05:34 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

int	line_size(char *line)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (ft_isalnum(line[i]))
	{
		size++;
		i++;
	}
	return (size);
}

int	line_check(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != '1')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	top_check(t_data_load *load)
{
	int		fd;
	char	*line;

	fd = open(load->map, O_RDONLY);
	line = get_next_line(fd);
	if (line_check(line))
	{
		ft_printf("Top line not closed by walls\n");
		free(line);
		close(fd);
		return (1);
	}
	free(line);
	close(fd);
	return (0);
}

int	bot_check(t_data_load *load)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(load->map, O_RDONLY);
	line = get_next_line(fd);
	i = 1;
	while (i < load->map_height)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (line_check(line))
	{
		ft_printf("Bot line not closed by walls\n");
		free(line);
		close(fd);
		return (1);
	}
	free(line);
	close(fd);
	return (0);
}

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
	if (row_check(load))
		return (1);
	if (top_check(load))
		return (1);
	if (bot_check(load))
		return (1);
	if (sides(load))
		return (1);
	return (0);
}
