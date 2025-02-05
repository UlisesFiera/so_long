/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:00:28 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/05 13:37:14 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

int	collection(t_data_load *load)
{
	int	i;
	int	j;
	int	count;

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
	return (count);
}
