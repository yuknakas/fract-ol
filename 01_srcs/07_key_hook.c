/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:17:28 by yuknakas          #+#    #+#             */
/*   Updated: 2025/04/12 16:06:58 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

int			fr_key_hook(int key_code, t_fractal *fractal);
static void	_set_random_julia(t_fractal *fractal);
static void	_change_iterations(t_fractal *fractal, int key_code);

int	fr_key_hook(int key_code, t_fractal *fractal)
{
	if (key_code == ESC)
		fr_destroy_window(fractal);
	else if (key_code == LEFT)
		fractal->offset_x -= 42 / fractal->zoom;
	else if (key_code == RIGHT)
		fractal->offset_x += 42 / fractal->zoom;
	else if (key_code == UP)
		fractal->offset_y -= 42 / fractal->zoom;
	else if (key_code == DOWN)
		fractal->offset_y += 42 / fractal->zoom;
	else if (key_code == R)
		fr_initialize_setup(fractal);
	else if (key_code == C)
		fractal->color += (255 * 255 * 255) / 100;
	else if (key_code == J)
		_set_random_julia(fractal);
	else if (key_code == M || key_code == P)
		_change_iterations(fractal, key_code);
	fractal->calc_left = -1;
	return (0);
}

static void	_set_random_julia(t_fractal *fractal)
{
	fractal->cx = ((double)rand() / RAND_MAX) * 3.0 - 1.5;
	fractal->cy = ((double)rand() / RAND_MAX) * 3.0 - 1.5;
}

static void	_change_iterations(t_fractal *fractal, int key_code)
{
	if (key_code == M)
	{
		fractal->iteration_limit -= 100;
		if (fractal->iteration_limit < 1)
			fractal->iteration_limit = 1;
	}
	else if (key_code == P)
	{
		if (fractal->max_iterations < 4200)
			fractal->max_iterations += 100;
	}
}
