/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:20:56 by ulfernan          #+#    #+#             */
/*   Updated: 2024/12/15 21:59:40 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

int		collection(t_data_load *load)
{
	int	i;
	int	j;
	int	count;
	
	while (load->map_matrix[i])
	{
		while (load->map_matrix[i][j])
		{
			if ((char)load->map_matrix[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int		collision(t_data_load *load, int x, int y)
{
	int	map_x;
    int	map_y;
	int	count;
	int	collected;
	int	open_exit;
    
	map_x = x / load->pixel_x;
	map_y = y / load->pixel_y;
	open_exit = 0;
	map_copy(load);
	collected = 0;
	count = collection(load);
	if (load->map_matrix[map_y][map_x] == '1')
	{
		free_matrix(load);
		return (1);
	}
	if (load->map_matrix[map_y][map_x] == 'C')
	{
		collected++;
		if (collected == count)
		open_exit = 1;
	}
	if (load->map_matrix[map_y][map_x] == 'E')
	{
		if (open_exit == 1)
		{
			free_matrix(load);
			mlx_hook(load->win, 17, 0, close_window, load);
			return (0);
		}
		free_matrix(load);
		return (1);
	}
	free_matrix(load);
	return (0);
}