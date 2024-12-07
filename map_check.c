/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:52:34 by ulfernan          #+#    #+#             */
/*   Updated: 2024/12/07 15:00:22 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

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
		free(top_bot_line);
		top_bot_line = line;
		line = get_next_line(fd);
	}
	if (top_bot(top_bot_line))
		return (1);
	free(line);
	return (0);
}

int	wall_check(t_data_load *load)
{
	int		fd;
	char	*line;
	char	*top_bot_line;

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

int	char_check(t_data_load *load)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(load->map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[++i])
		{
			if ((line[i] != '1') && (line[i] != '0') && (line[i] != 'P') && 
				(line[i] != 'C') && (line[i] != 'E') && (line[i] != '\n'))
			{
				ft_printf("Invalid item in map: '%c'\n", line[i]);
				free(line);
				close(fd);
				return (1);
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	map_check(t_data_load *load)
{
	if (load->map_height < 3)
	{
		ft_printf("Min height: 3 rows\n");
		return (1);
	}
	if (load->map_height > load->map_width)
	{
		ft_printf("Not a rectangular map\n");
		return (1);
	}
	if (char_check(load))
		return (1);
	if (wall_check(load))
		return (1);

	if (route(load))
	{
		printf("Error: no possible route\n");
		return (1);
	}
	return (0);
}
