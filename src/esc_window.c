/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esc_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:39:33 by ulfernan          #+#    #+#             */
/*   Updated: 2024/12/12 19:22:04 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

int		close_window(t_data_load *load)
{
	free_load(load);
	exit (0);
}
 
int		esc_key(int keycode, t_data_load *load)
{
	if (keycode == 65307)
	{
		free_load(load);
		exit (0);
	}
	return (0);
}

void	esc_window(t_data_load *load)
{
	mlx_hook(load->win, 17, 0, close_window, load);
	mlx_key_hook(load->win, esc_key, load);
}
