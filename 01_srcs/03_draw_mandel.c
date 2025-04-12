/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_draw_mandel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:08:10 by yuknakas          #+#    #+#             */
/*   Updated: 2025/04/12 14:04:41 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"
#include <stdio.h>

int	fr_first_mandel(t_fractal *fractal);
int	fr_draw_mandel(t_fractal *fractal);

int	fr_first_mandel(t_fractal *fractal)
{
	int	remain;

	printf("zoom is:%f\n", fractal->zoom);
	fractal->x = 0;
	fr_initial_iteration(fractal);
	remain = 0;
	while (fractal->x < SIZE)
	{
		fractal->y = 0;
		while (fractal->y < SIZE)
		{
			remain += fr_calculate_mandelbrot(fractal);
			fractal->y++;
		}
		fractal->x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window,
		fractal->image, 0, 0);
	return (remain);
}

int	fr_draw_mandel(t_fractal *fractal)
{
	int	*buffer;
	int	remain;

	printf("drawing rest\n");
	buffer = fractal->pointer_to_image;
	fractal->x = 0;
	remain = 0;
	while (fractal->x < SIZE)
	{
		fractal->y = 0;
		while (fractal->y < SIZE)
		{
			if (buffer[(fractal->y * fractal->size_line
						/ sizeof(int)) + fractal->x] == BLACK)
				remain += fr_calculate_mandelbrot(fractal);
			fractal->y++;
		}
		fractal->x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window,
		fractal->image, 0, 0);
	return (remain);
}
