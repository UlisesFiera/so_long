/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:22:29 by ulfernan          #+#    #+#             */
/*   Updated: 2024/12/18 17:22:43 by ulfernan         ###   ########.fr       */
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
