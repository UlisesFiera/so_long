/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:20:56 by ulfernan          #+#    #+#             */
/*   Updated: 2024/12/15 20:22:09 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

int		collision(t_data_load *load, int x, int y)
{
	int	map_x;
    int	map_y;
    
	map_x = x / load->pixel_x;
	map_y = y / load->pixel_y;
	map_copy(load);
	if (load->map_matrix[map_y][map_x] == '1')
	{
		free_matrix(load);
		return (1);
	}
	free_matrix(load);
	return (0);
}