/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:52:34 by ulfernan          #+#    #+#             */
/*   Updated: 2024/12/06 17:43:22 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

int		sides(char *line, char *top_bot_line, int fd)
{
	while (line != NULL)
	{
		if (line[0] != '1' || line[ft_strlen(line) - 1] != '1' )
		{
			free(line);
			free(top_bot_line);
			close (fd);
			return (1);
		}
		last_line = line;
		line = get_next_line(fd);
	}
}

int		top_bot(char *line, int fd)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
		{
			free(top_bot_line);
			close(fd);
			return (1);
		}
		i++;
	}
	return (0);
}

int		wall_check(t_data_load *load)
{
	int		fd;
	char	*line;
	char	*top_bot_line;

	fd = open(load->map, O_RDONLY);
	if (top_bot(top_bot_line = get_next_line(fd), fd))
		return (1):
	line = get_next_line(fd);
	if (sides(line, top_bot_line, fd))
		return (1):
	free(line);
	free(last_line);
	close (fd);
	if (load->map_height > load->map_width)
		return (1);
	return (0);
}

int		map_check(t_data_load *load)
{
	if (wall_check(load))
		return (1);
	return (0);
}