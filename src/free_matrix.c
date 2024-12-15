/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:37:48 by ulfernan          #+#    #+#             */
/*   Updated: 2024/12/15 16:40:59 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

void	free_matrix(t_data_load *load)
{
	int	i;

	i = 0;
	while (i < load->map_height)
	{
		free(load->map_matrix[i]);
		i++;
	}
	free(load->map_matrix);
}
