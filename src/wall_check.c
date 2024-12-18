/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:54:34 by ulfernan          #+#    #+#             */
/*   Updated: 2024/12/18 17:29:57 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

int	row_check(t_data_load *load)
{
	int		i;
	int		size;
	int		size_rest;

	map_copy(load);
	i = 0;
	size = line_size(load->map_matrix[i]);
	while (load->map_matrix[i])
	{
		size_rest = line_size(load->map_matrix[i]);
		if (size != size_rest)
		{
			ft_printf("Error: all map rows must be the same size\n");
			free_matrix(load);
			return (1);
		}
		i++;
	}
	free_matrix(load);
	load->map_width = size;
	return (0);
}

int	wall_check(t_data_load *load)
{
	if (row_check(load))
		return (1);
	if (sides_top_bot(load))
		return (1);
	return (0);
}
