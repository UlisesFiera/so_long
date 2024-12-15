/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triggers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:35:32 by ulfernan          #+#    #+#             */
/*   Updated: 2024/12/15 20:51:47 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

int	close_window(t_data_load *load)
{
	ft_printf("Exiting game\n");
	free_load(load);
	exit (0);
}

void	esc(int keycode, t_data_load *load)
{
	if (keycode == 65307)
	{
		ft_printf("Exiting game\n");
		free_load(load);
		exit(0);
	}
}

int	press(int keycode, t_data_load *load)
{
	move(keycode, load);
	esc(keycode, load);
	return (0);
}

void	triggers(t_data_load *load)
{
	mlx_hook(load->win, 2, 1L << 0, press, load);
	mlx_hook(load->win, 17, 0, close_window, load);
}
