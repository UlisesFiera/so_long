/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:54:05 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/05 13:36:46 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

int	char_check(t_data_load *load)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(load->map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[++i])
		{
			if ((line[i] != '1') && (line[i] != '0') && (line[i] != 'P')
				&& (line[i] != 'C') && (line[i] != 'E') && (line[i] != '\n'))
			{
				ft_printf("Invalid item in map: '%c'\n", line[i]);
				free(line);
				close(fd);
				return (1);
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
