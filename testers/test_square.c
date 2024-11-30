#include "minilibx-linux/mlx.h"
#include <stdio.h>

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y *data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		y;
	int		x;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 400, "Hello world!");
	img.img = mlx_new_image(mlx, 600, 400);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

	y = 10;
	x = 10;
	while (y < 300)
	{
		x = 10;
		while (x < 100)
		{
			my_pixel_put(&img, x, y, 0x00FF0000);
			x++;
		}
		y++;
	}
	
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
