/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:05:44 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/05 14:14:39 by ulfernan         ###   ########.fr       */
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
	int	i;

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
