#include "header/fractol.h"
#include <stdio.h>
#include <limits.h>

int main()
{
	long double db;

	db = __SIZEOF_LONG_DOUBLE__
	void *mlx = mlx_init();
	void *window = mlx_new_window(mlx, SIZE, SIZE, "test window");
	sleep(10);
	void *image = mlx_new_image(mlx, SIZE, SIZE);
	int rando;
	rando = 0;
	void *pt_image = mlx_get_data_addr(image, &rando, &rando, &rando);
	int *ptr_image = pt_image;
	printf("original: %i\n", 0x000000);
	int i = 0;
	while (i < 15)
	{
		printf("%dth color is: %i\n", i, ptr_image[i]);
		i++;
	}
	mlx_destroy_image(mlx, image);
	mlx_destroy_window(mlx, window);
	return (0);
}