/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:54:05 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/19 09:05:27 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

int	collectible_check(t_data_load *load)
{
	load->collection = collection(load);
	if (load->collection == 0)
		ft_printf("Error: no collectibles\n");
	return (load->collection);
}

int	player_check(t_data_load *load)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (load->map_matrix[i])
	{
		j = 0;
		while ((load->map_matrix[i][j]))
		{
			if (load->map_matrix[i][j] == 'P')
				count++;
			j++;
		}
		i++;
	}
	if (count > 1)
		return (1);
	return (0);
}

int	exit_check(t_data_load *load)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (load->map_matrix[i])
	{
		j = 0;
		while ((load->map_matrix[i][j]))
		{
			if (load->map_matrix[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count > 1)
		return (1);
	return (0);
}

int	valid_char(t_data_load *load)
{
	int		i;
	int		j;

	i = 0;
	while (load->map_matrix[i])
	{
		j = 0;
		while ((load->map_matrix[i][j]))
		{
			if ((load->map_matrix[i][j] != '1')
				&& (load->map_matrix[i][j] != '0')
				&& (load->map_matrix[i][j] != 'P')
				&& (load->map_matrix[i][j] != 'C')
				&& (load->map_matrix[i][j] != 'E')
				&& (load->map_matrix[i][j] != '\n'))
			{
				ft_printf("Invalid item: '%c'\n", load->map_matrix[i][j]);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	char_check(t_data_load *load)
{
	map_copy(load);
	if (valid_char(load))
	{
		free_matrix(load);
		return (1);
	}
	if (exit_check(load))
	{
		free_matrix(load);
		ft_printf("Error: more than 1 exit\n");
		return (1);
	}
	if (player_check(load))
	{
		free_matrix(load);
		ft_printf("Error: more than 1 player\n");
		return (1);
	}
	if (collectible_check(load) == 0)
	{
		free_matrix(load);
		return (1);
	}
	free_matrix(load);
	return (0);
}
