/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:28:48 by yuknakas          #+#    #+#             */
/*   Updated: 2025/04/12 16:18:45 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"
#include <stdio.h>

void	fr_put_color_pixel(t_fractal *fractal, int x, int y, int color);
int		fr_destroy_window(t_fractal *fractal);

void	fr_put_color_pixel(t_fractal *fractal, int x, int y, int color)
{
	int	*buffer;

	buffer = fractal->pointer_to_image;
	buffer[(y * fractal->size_line / sizeof(int)) + x] = color;
}

int	fr_destroy_window(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image);
	mlx_destroy_window(fractal->mlx, fractal->window);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	free(fractal);
	exit(0);
}

void	fr_initial_iteration(t_fractal *fractal)
{
	int	addition;

	addition = 0;
	addition = (int)(fractal->zoom / 5000.0) * 5;
	if (addition > 50)
		addition = 50;
	addition = (int)(fractal->zoom / 100000.0) * 5;
	if (addition > 100)
		addition = 100;
	fractal->max_iterations = FLOP / SIZE / SIZE / COST + addition;
	if (fractal->max_iterations < 1)
		fractal->max_iterations = 1;
	printf("max interation: %d\n", fractal->max_iterations);
	if (fractal->max_iterations > fractal->iteration_limit)
		fractal->max_iterations = fractal->iteration_limit;
}
