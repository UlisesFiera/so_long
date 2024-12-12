/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longlib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:47:32 by ulfernan          #+#    #+#             */
/*   Updated: 2024/12/12 10:58:06 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LONGLIB_H
# define LONGLIB_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

typedef struct	s_data_load
{
	void		*mlx;
	void		*win;
	char		*map;
	void		*img;
	char		*addr;
	int			pixel_x;
	int			pixel_y;
	int			map_width;
	int			map_height;
}				t_data_load;

typedef struct	s_data_texture
{
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data_texture;

void	esc_window(t_data_load *load);
int		load_textures(t_data_load *load);
void	texture_put(t_data_load *load, t_data_texture *texture, char option);
int		wall_check(t_data_load *load);
int		char_check(t_data_load *load);
int		route(t_data_load *load);
int		backtracking(char **matrix);

#endif