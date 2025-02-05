/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:40:39 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/05 13:36:04 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

int	path_find(char **matrix, int y, int x)
{
	if (matrix[y][x] == 'E')
		return (0);
	if (matrix[y][x] == '1' || matrix[y][x] == 'V')
		return (1);
	matrix[y][x] = 'V';
	if (path_find(matrix, y - 1, x) == 0
		|| path_find(matrix, y, x - 1) == 0
		|| path_find(matrix, y + 1, x) == 0
		|| path_find(matrix, y, x + 1) == 0)
		return (0);
	return (1);
}

int	player_pos(char **matrix, int *y, int *x)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == 'P')
			{
				*y = i;
				*x = j;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	backtracking(t_data_load *load)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (map_copy(load))
	{
		ft_printf("Map copy failure\n");
		return (1);
	}
	if (player_pos(load->map_matrix, &y, &x))
	{
		ft_printf("Missing player 'P' item\n");
		free_matrix(load);
		return (1);
	}
	if (path_find(load->map_matrix, y, x))
	{
		ft_printf("Error: no possible route\n");
		free_matrix(load);
		return (1);
	}
	free_matrix(load);
	return (0);
}
