#include "header/fractol.h"

int main()
{
	void *mlx = mlx_init();
	void *window = mlx_new_window(mlx, SIZE, SIZE, "test window");
	void *window1 = mlx_new_window(mlx, SIZE, SIZE, "test window");
	sleep(15);
	mlx_destroy_window(mlx, window);
	sleep(15);
	mlx_destroy_window(mlx, window1);
}