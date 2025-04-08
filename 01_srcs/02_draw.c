/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:30:05 by yuknakas          #+#    #+#             */
/*   Updated: 2025/04/08 17:05:55 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	fr_draw(t_fractal *fractal)
{
	int	remain;

	remain = 0;
	if (fractal->calc_left == -1)
	{
		if (fractal->type == MANDEL)
			fractal->calc_left = fr_first_mandel(fractal);
		else if (fractal->type == JULIA)
			fractal->calc_left = fr_first_julia(fractal);
		else
			fractal->calc_left = fr_first_ship(fractal);
		fractal->max_iterations = FLOP / 30 / fractal->calc_left / COST;
		return ;
	}
	if (fractal->type == MANDEL)
		remain = fr_draw_mandel(fractal);
	else if (fractal->type == JULIA)
		remain = fr_draw_julia(fractal);
	else
		remain = fr_draw_ship(fractal);
	if (fractal->calc_left > remain)
		fractal->max_iterations = FLOP / 30 / fractal->calc_left / COST;
	else
		fractal->max_iterations += fractal->iteration_limit / 10;
	fractal->calc_left = remain;
}
