/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:39:33 by ulfernan          #+#    #+#             */
/*   Updated: 2024/11/28 16:39:33 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

int	close_window(int keycode, t_data *load)
{
	mlx_destroy_window(load->mlx, load->win);
	free(load->mlx);
	return (0);
}

int	esc_key(int keycode, t_data *load)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(load->mlx, load->win);
		free(load->mlx);
		return (0);
	}
	return (0);
}

void	esc_window(t_data *load)
{
	mlx_key_hook(load->win, esc_key, load);
	mlx_hook(load->win, 17, 0, close_window, load);
}
