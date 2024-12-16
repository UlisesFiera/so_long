/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:54:05 by ulfernan          #+#    #+#             */
/*   Updated: 2024/12/17 00:03:05 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

void	collection(t_data_load *load)
{
	int	i;
	int	j;
	int	count;

	map_copy(load);
	count = 0;
	i = 0;
	while (load->map_matrix[i])
	{
		j = 0;
		while (load->map_matrix[i][j])
		{
			if ((char)load->map_matrix[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	load->collectible_count = 0;
	load->collectible_count = count;
	free_matrix(load);
}

int	char_check(t_data_load *load)
{
	int		fd;
	char	*line;
	int		i;

	collection(load);
	fd = open(load->map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[++i])
		{
			if ((line[i] != '1') && (line[i] != '0') && (line[i] != 'P')
				&& (line[i] != 'C') && (line[i] != 'E') && (line[i] != '\n'))
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

int	char_check(t_data_load *load)
{
	int		i;
	int		j;

	collection(load);
	map_copy(load);
	i = 0;
	while (load->map_matrix[i])
	{
		j = 0;
		while (load->map_matrix[i][j])
		{
			if ((load->map_matrix[i][j] != '1') && (load->map_matrix[i][j] != '0') && (load->map_matrix[i][j] != 'P')
				&& (load->map_matrix[i][j] != 'C') && (load->map_matrix[i][j] != 'E') && (load->map_matrix[i][j] != '\n'))
			{
				ft_printf("Invalid item in map: '%c'\n", load->map_matrix[i][j]);
				return (1);
			}
			j++;
		}
		i++;
	}
	free_matrix(load);
	return (0);
}