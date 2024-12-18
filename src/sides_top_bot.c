/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sides_top_bot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:52:08 by ulfernan          #+#    #+#             */
/*   Updated: 2024/12/18 17:19:13 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

int	line_size(char *line)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (ft_isalnum(line[i]))
	{
		size++;
		i++;
	}
	return (size);
}

int	line_check(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != '1')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	top_bot_check(t_data_load *load)
{
	map_copy(load);
	if (line_check(load->map_matrix[0]))
	{
		ft_printf("Top line not closed by walls\n");
		free_matrix(load);
		return (1);
	}
	if (line_check(load->map_matrix[load->map_height - 1]))
	{
		ft_printf("Bot line not closed by walls\n");
		free_matrix(load);
		return (1);
	}
	free_matrix(load);
	return (0);
}

int	sides(t_data_load *load)
{
	int		i;
	int		j;

	i = 0;
	map_copy(load);
	while (load->map_matrix[i])
	{
		j = 0;
		if (load->map_matrix[i][0] != '1')
		{
			free_matrix(load);
			return (1);
		}
		while (load->map_matrix[i][j + 1] != '\0'
			&& load->map_matrix[i][j + 1] != '\n')
			j++;
		if (load->map_matrix[i][j] != '1')
		{
			free_matrix(load);
			return (2);
		}
		i++;
	}
	free_matrix(load);
	return (0);
}

int	sides_top_bot(t_data_load *load)
{
	if (top_bot_check(load))
		return (1);
	if (sides(load) == 1)
	{
		ft_printf("Left side not closed by walls\n");
		return (1);
	}
	if (sides(load) == 2)
	{
		ft_printf("Right side not closed by walls\n");
		return (1);
	}
	return (0);
}
