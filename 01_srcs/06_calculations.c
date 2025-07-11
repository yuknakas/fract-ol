/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_calculations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:01:22 by yuknakas          #+#    #+#             */
/*   Updated: 2025/04/16 09:56:08 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

int	fr_calculate_julia(t_fractal *frac)
{
	int			iterations;
	long double	tmp;

	frac->zx = frac->x / frac->zoom + frac->offset_x;
	frac->zy = frac->y / frac->zoom + frac->offset_y;
	iterations = 1;
	while (iterations < frac->max_iterations)
	{
		tmp = frac->zx;
		frac->zx = frac->zx * frac->zx - frac->zy * frac->zy + frac->cx;
		frac->zy = 2 * tmp * frac->zy + frac->cy;
		if (frac->zx * frac ->zx + frac->zy * frac->zy > 4)
			break ;
		iterations++;
	}
	if (iterations == frac->max_iterations)
	{
		fr_put_color_pixel(frac, frac->x, frac->y, BLACK);
		return (1);
	}
	else
		fr_put_color_pixel(frac, frac->x, frac->y, frac->color * iterations);
	return (0);
}

int	fr_calculate_mandelbrot(t_fractal *frac)
{
	int			iterations;
	long double	tmp;

	frac->zx = 0.0;
	frac->zy = 0.0;
	frac->cx = frac->x / frac->zoom + frac->offset_x;
	frac->cy = frac->y / frac->zoom + frac->offset_y;
	iterations = 1;
	while (iterations < frac->max_iterations)
	{
		tmp = frac->zx;
		frac->zx = frac->zx * frac->zx - frac->zy * frac->zy + frac->cx;
		frac->zy = 2 * tmp * frac->zy + frac->cy;
		if (frac->zx * frac ->zx + frac->zy * frac->zy > 4)
			break ;
		iterations++;
	}
	if (iterations == frac->max_iterations)
	{
		fr_put_color_pixel(frac, frac->x, frac->y, BLACK);
		return (1);
	}
	else
		fr_put_color_pixel(frac, frac->x, frac->y, frac->color * iterations);
	return (0);
}

int	fr_calculate_burningship(t_fractal *frac)
{
	int			iterations;
	long double	tmp;

	frac->zx = 0.0;
	frac->zy = 0.0;
	frac->cx = frac->x / frac->zoom + frac->offset_x;
	frac->cy = frac->y / frac->zoom + frac->offset_y;
	iterations = 1;
	while (iterations < frac->max_iterations)
	{
		tmp = frac->zx;
		frac->zx = fabsl(frac->zx * frac->zx - frac->zy * frac->zy + frac->cx);
		frac->zy = fabsl(2.0 * tmp * frac->zy) + frac->cy;
		if (frac->zx * frac ->zx + frac->zy * frac->zy > 4)
			break ;
		iterations++;
	}
	if (iterations == frac->max_iterations)
	{
		fr_put_color_pixel(frac, frac->x, frac->y, BLACK);
		return (1);
	}
	else
		fr_put_color_pixel(frac, frac->x, frac->y, frac->color * iterations);
	return (0);
}
