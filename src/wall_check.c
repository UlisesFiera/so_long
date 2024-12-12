/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:54:34 by ulfernan          #+#    #+#             */
/*   Updated: 2024/12/12 11:49:40 by ulfernan         ###   ########.fr       */
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

int	top_bot(char *top_bot_line)
{
	int		i;

	i = 0;
	while (top_bot_line[i] != '\0' && top_bot_line[i] != '\n')
	{
		if (top_bot_line[i] != '1')
		{
			ft_printf("Top or bottom line not closed by walls\n");
			free(top_bot_line);
			return (1);
		}
		i++;
	}
	return (0);
}

int	sides(char *line, char *top_bot_line, int fd)
{
	int		i;

	i = 0;
	while (line != NULL)
	{
		if (line[0] != '1')
		{
			ft_printf("Left side not closed by walls\n");
			return (1);
		}
		while (line[i + 1] != '\0' && line[i + 1] != '\n')
			i++;
		if (line[i] != '1')
		{
			ft_printf("Right side not closed by walls\n");
			return (1);
		}
		top_bot_line = line;
		line = get_next_line(fd);
	}
	if (top_bot(top_bot_line))
		return (1);
	free(line);
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
	int		fd;
	char	*line;
	char	*top_bot_line;

	if (row_check(load))
		return (1);
	fd = open(load->map, O_RDONLY);
	top_bot_line = get_next_line(fd);
	if (top_bot(top_bot_line))
	{
		close(fd);
		return (1);
	}
	line = get_next_line(fd);
	if (sides(line, top_bot_line, fd))
	{
		close(fd);
		free(line);
		free(top_bot_line);
		return (1);
	}
	free(top_bot_line);
	close(fd);
	return (0);
}
