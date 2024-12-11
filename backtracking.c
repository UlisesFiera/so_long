/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:40:39 by ulfernan          #+#    #+#             */
/*   Updated: 2024/12/07 16:40:19 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

int is_valid(char **matrix, int y, int x, int rows, int cols)
{
    return (y >= 0 && y < rows && x >= 0 && x < cols && 
            (matrix[y][x] == '0' || matrix[y][x] == 'C' || matrix[y][x] == 'P'));
}

int path_find(char **matrix, int y, int x, int rows, int cols) 
{
    if (matrix[y][x] == 'E') // Exit found
        return 0;

    if (!is_valid(matrix, y, x, rows, cols))
        return 1; // Not traversable

    matrix[y][x] = 'V'; // Mark as visited

    // Explore all possible directions
    if (path_find(matrix, y - 1, x, rows, cols) == 0 || // Up
        path_find(matrix, y, x - 1, rows, cols) == 0 || // Left
        path_find(matrix, y, x + 1, rows, cols) == 0 || // Right
        path_find(matrix, y + 1, x, rows, cols) == 0)   // Down
        return 0;

    matrix[y][x] = '0'; // Reset for backtracking
    return 1; // No valid path
}

int	player_pos(char **matrix, int *y, int *x)
{
	int	i;
	int j;

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
	ft_printf("Missing player 'P' item\n");
	return (1);
}

int	backtracking(char **matrix)
{
	int y;
	int x;

	y = 0;
	x = 0;
	if (player_pos(matrix, &y, &x))
		return (1);
	if (path_find(matrix, y, x))
		return (1);
	return (0);
}