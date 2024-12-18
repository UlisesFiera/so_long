/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:30:47 by ulfernan          #+#    #+#             */
/*   Updated: 2024/12/18 16:47:23 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

void	free_up(t_data_load *load, char *line, int fd)
{
	free_matrix(load);
	free(line);
	close(fd);
}

int	copying(t_data_load *load)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(load->map, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		load->map_matrix[i] = ft_strdup(line);
		if (!load->map_matrix[i])
		{
			free_up(load, line, fd);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	load->map_matrix[i] = NULL;
	close(fd);
	return (0);
}

int	map_copy(t_data_load *load)
{
	load->map_matrix = malloc((load->map_height + 1) * sizeof(char *));
	if (!load->map_matrix)
	{
		free(load);
		ft_printf("Copy map (malloc) failure\n");
		return (1);
	}
	if (copying(load))
	{
		ft_printf("Copy map failure\n");
		return (1);
	}
	return (0);
}

// Caller function MUST FREE on success	free_matrix(load);