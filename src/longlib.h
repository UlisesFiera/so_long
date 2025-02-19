/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longlib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:47:32 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/19 07:39:41 by ulfernan         ###   ########.fr       */
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

typedef struct s_data_texture
{
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			y;
	int			x;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data_texture;

typedef struct s_data_load
{
	void				*mlx;
	void				*win;
	char				*map;
	char				**map_matrix;
	void				*img;
	int					pixel_x;
	int					pixel_y;
	int					map_width;
	int					map_height;
	int					collected;
	int					collection;
	t_data_texture		floor_texture;
	t_data_texture		wall_texture;
	t_data_texture		collectible_texture;
	t_data_texture		player_texture;
	t_data_texture		exit_texture;
	t_data_texture		exit_player_texture;
}						t_data_load;

int		load_textures(t_data_load *load);
void	texture_put(t_data_load *load, char option);
int		wall_check(t_data_load *load);
int		char_check(t_data_load *load);
int		backtracking(t_data_load *load);
void	free_load(t_data_load *load);
void	triggers(t_data_load *load);
int		map_copy(t_data_load *load);
void	free_matrix(t_data_load *load);
int		collision(t_data_load *load, int x, int y);
int		background(t_data_load *load);
void	move(int keycode, t_data_load *load);
int		close_window(t_data_load *load);
int		collection(t_data_load *load);
int		line_size(char *line);
int		line_check(char *line);
int		top_check(t_data_load *load);
int		bot_check(t_data_load *load);

#endif