/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:35:32 by ulfernan          #+#    #+#             */
/*   Updated: 2024/12/12 20:01:28 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

int		up(int keycode, t_data_load *load)
{
	int	steps;

	steps = 0;
	if (keycode == 65362)
	{
		load->player_texture.y += 10;
		mlx_clear_window(load->mlx, load->win);
		texture_put(load, 'P');
		ft_printf("Steps: %i\n", steps);
	}
	mlx_string_put(load->mlx, load->win, load->player_texture.x, load->player_texture.y, 0xFFFFFF, "Moving!");
	return (0);
}

void	movement(t_data_load *load)
{
	mlx_hook(load->win, up, load);
//	mlx_hook(load->win, 65364, 0, down, load);
//	mlx_hook(load->win, 65361, 0, left, load);
//	mlx_hook(load->win, 65363, 0, right, load);
}

/*
int key_press(int keycode, t_data_load *load)
{
    if (keycode == 65362) // Up arrow key
    {
        load->player_texture.y -= 10;
        ft_printf("Moving up! Player Y: %d\n", load->player_texture.y);
    }
    else if (keycode == 65364) // Down arrow key
    {
        load->player_texture.y += 10;
        ft_printf("Moving down! Player Y: %d\n", load->player_texture.y);
    }
    else if (keycode == 65361) // Left arrow key
    {
        load->player_texture.x -= 10;
        ft_printf("Moving left! Player X: %d\n", load->player_texture.x);
    }
    else if (keycode == 65363) // Right arrow key
    {
        load->player_texture.x += 10;
        ft_printf("Moving right! Player X: %d\n", load->player_texture.x);
    }
    else if (keycode == 65307) // Escape key
    {
        ft_printf("Exiting game\n");
        free_load(load);
        exit(0);
    }

    // Redraw the screen
    mlx_clear_window(load->mlx, load->win);
    mlx_put_image_to_window(load->mlx, load->win, load->player_texture.img, 
                            load->player_texture.x, load->player_texture.y);
    return (0);
}

void movement(t_data_load *load)
{
    mlx_hook(load->win, 2, 1L << 0, key_press, load); // 2: KeyPress event
}
*/