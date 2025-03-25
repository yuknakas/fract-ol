/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:08:10 by yuknakas          #+#    #+#             */
/*   Updated: 2025/03/25 16:00:24 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

static int	_first_draw(t_fractal *fractal);
static int	_draw_rest(t_fractal *fractal);
static int	_calculate(t_fractal *fractal);

void	fr_draw(t_fractal *fractal)
{
	int	remain;

	remain = _first_draw(fractal);
	while (fractal->max_iterations < fractal->iteration_limit)
	{
		fractal->max_iterations = FLOP / remain / COST;
		if (fractal->max_iterations > fractal->iteration_limit)
			fractal->max_iterations = fractal->iteration_limit;
		remain = _draw_rest(fractal);
	}
}

static int	_first_draw(t_fractal *fractal)
{
	int	remain;

	fractal->x = 0;
	fractal->x = 0;
	fractal->max_iterations = FLOP / SIZE / SIZE / COST;
	remain = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			remain += _calculate(fractal);
			fractal->y++;
		}
		fractal->x++;
	}
	return (remain);
}

static int	_draw_rest(t_fractal *fractal)
{
	int	*buffer;
	int	remain;

	buffer = fractal->pointer_to_image;
	fractal->x = 0;
	fractal->x = 0;
	remain = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			if (buffer[(fractal->y * fractal->size_line
						/ sizeof(int)) + fractal->x] == BLACK)
				remain += _calculate(fractal);
			fractal->y++;
		}
		fractal->x++;
	}
	return (remain);
}

static int	_calculate(t_fractal *fractal)
{
	if (fractal->type == MANDEL)
		return (fr_calculate_mandelbrot(fractal));
	else if (fractal->type == JULIA)
		return (fr_calculate_julia(fractal));
	else if (fractal->type == SHIP)
		return (fr_calculate_burningship(fractal));
}
