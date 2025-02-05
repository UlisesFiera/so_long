/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:20:56 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/05 13:53:32 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

int	exit_game(t_data_load *load, int open_exit)
{
	if (open_exit == 1)
	{
		free_matrix(load);
		free_load(load);
		exit(0);
	}
	else
	{
		free_matrix(load);
		return (1);
	}
}

int	collision(t_data_load *load, int x, int y)
{
	int			map_x;
	int			map_y;
	static int	open_exit = 0;

	map_copy(load);
	map_x = x / load->pixel_x;
	map_y = y / load->pixel_y;
	if (load->map_matrix[map_y][map_x] == '1')
	{
		free_matrix(load);
		return (1);
	}
	else if (load->map_matrix[map_y][map_x] == 'C')
	{
		load->collected++;
		if (load->collected == load->collection)
			open_exit = 1;
	}
	else if (load->map_matrix[map_y][map_x] == 'E')
		exit_game(load, open_exit);
	free_matrix(load);
	return (0);
}

// 1 means true, means the screen won't be redrawn and so we achieve collision