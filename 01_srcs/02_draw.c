/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:30:05 by yuknakas          #+#    #+#             */
/*   Updated: 2025/04/12 16:00:46 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

int			fr_draw(t_fractal *fractal);
static void	_first_draw(t_fractal *fractal);
static void	_rest_draw(t_fractal *fractal);

int		fr_draw(t_fractal *fractal)
{
	if (fractal->calc_left == -1)
		_first_draw(fractal);
	else
		_rest_draw(fractal);
	if (fractal->max_iterations > fractal->iteration_limit)
		fractal->max_iterations = fractal->iteration_limit;
	return (0);
}

static void	_first_draw(t_fractal *fractal)
{
	if (fractal->type == MANDEL)
		fractal->calc_left = fr_first_mandel(fractal);
	else if (fractal->type == JULIA)
		fractal->calc_left = fr_first_julia(fractal);
	else
		fractal->calc_left = fr_first_ship(fractal);
	if (fractal->calc_left > 0)
		fractal->max_iterations = FLOP / 30 / fractal->calc_left / COST;
	if (fractal->iteration_limit > 1999)
	{
		if (fractal->max_iterations < fractal->iteration_limit / 60)
			fractal->max_iterations = fractal->iteration_limit / 60;
	}
	else
	{
		if (fractal->max_iterations < fractal->iteration_limit / 30)
			fractal->max_iterations = fractal->iteration_limit / 30;
	}
}

static void	_rest_draw(t_fractal *fractal)
{
	if (fractal->type == MANDEL)
		fractal->calc_left = fr_draw_mandel(fractal);
	else if (fractal->type == JULIA)
		fractal->calc_left = fr_draw_julia(fractal);
	else
		fractal->calc_left = fr_draw_ship(fractal);
	if (fractal->iteration_limit > 1999)
		fractal->max_iterations += fractal->iteration_limit / 60;
	else
		fractal->max_iterations += fractal->iteration_limit / 30;
}
