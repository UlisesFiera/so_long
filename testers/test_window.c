#include "minilibx-linux/mlx.h"

int	main(void)
{
	void	*mlx;
	void 	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 300, 300, "Hello world!");
	mlx_loop(mlx);
}
