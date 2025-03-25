/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_calculations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:01:22 by yuknakas          #+#    #+#             */
/*   Updated: 2025/03/25 15:56:26 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

int	fr_calculate_julia(t_fractal *frac)
{
	int		iterations;
	double	tmp;

	frac->zx = frac->x / frac->zoom + frac->offset_x;
	frac->zy = frac->y / frac->zoom + frac->offset_y;
	iterations = 1;
	while (iterations < frac->max_iterations)
	{
		tmp = frac->zx;
		frac->zx = frac->zx * frac->zx - frac->zy * frac->zy + frac->cx;
		frac->zy = 2 * tmp * frac->zy + frac->cy;
		if (frac->zx * frac ->zx + frac->zy * frac->zy > __DBL_MAX__)
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
	int		iterations;
	double	tmp;

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
		if (frac->zx * frac ->zx + frac->zy * frac->zy > __DBL_MAX__)
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
	int		iterations;
	double	tmp;

	frac->zx = 0.0;
	frac->zy = 0.0;
	frac->cx = frac->x / frac->zoom + frac->offset_x;
	frac->cy = frac->y / frac->zoom + frac->offset_y;
	iterations = 1;
	while (iterations < frac->max_iterations)
	{
		tmp = frac->zx;
		frac->zx = fabs(frac->zx * frac->zx - frac->zy * frac->zy + frac->cx);
		frac->zy = fabs(2 * tmp * frac->zy + frac->cy);
		if (frac->zx * frac ->zx + frac->zy * frac->zy > __DBL_MAX__)
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
