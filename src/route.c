/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:43:52 by ulfernan          #+#    #+#             */
/*   Updated: 2024/12/12 18:53:29 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

void	free_matrix(char **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	copy_map(char **matrix, t_data_load *load)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(load->map, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		matrix[i] = ft_strdup(line);
		if (!matrix[i])
		{	
			free_matrix(matrix, i);
			free(line);
			close(fd);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	matrix[i] = NULL;
	close(fd);
	return (0);
}

int		route(t_data_load *load)
{
	int		fd;
	char	*line;
	int		row;
	char	**matrix;
	
	fd = open(load->map, O_RDONLY);
	line = get_next_line(fd);
	row = 1;
	while (line)
	{
		row++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	matrix = malloc((row + 1) * sizeof(char *));
	if (!matrix)
	{
		free(matrix);
		ft_printf("Malloc failure\n");
		return (1);
	}
	if (copy_map(matrix, load))
	{
		free(matrix);
		ft_printf("Copy map failure\n");
		return (1);
	}
	if (backtracking(matrix))
	{
		free_matrix(matrix, row);
		ft_printf("Backtracking failure\n");
		return (1);
	}
	free_matrix(matrix, row);
	return (0);
}

