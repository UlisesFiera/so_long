/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:54:05 by ulfernan          #+#    #+#             */
/*   Updated: 2024/12/17 00:17:26 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

int	characters(char matrix)
{
	if ((matrix != '1')
		&& (matrix != '0')
		&& (matrix != 'P')
		&& (matrix != 'C')
		&& (matrix != 'E')
		&& (matrix != '\n'))
		return (1);
	return (0);
}

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
			if (characters(load->map_matrix[i][j]))
			{
				ft_printf("Invalid item in map: '%c'\n",
					load->map_matrix[i][j]);
				return (1);
			}
			j++;
		}
		i++;
	}
	free_matrix(load);
	return (0);
}
