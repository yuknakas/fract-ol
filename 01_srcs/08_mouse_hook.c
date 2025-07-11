/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_mouse_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:47:52 by yuknakas          #+#    #+#             */
/*   Updated: 2025/04/12 15:56:34 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

int			fr_mouse_hook(int mouse_code, int x, int y, t_fractal *fractal);
static void	_zoom(t_fractal *fractal, int x, int y, int in_out);
static void	_center(t_fractal *fractal, int x, int y);

int	fr_mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
{
	if (mouse_code == SCROLL_UP || mouse_code == MOUSE_LEFT)
		_zoom(fractal, x, y, 1);
	else if (mouse_code == SCROLL_DOWN || mouse_code == MOUSE_RIGHT)
		_zoom(fractal, x, y, -1);
	else if (mouse_code == MOUSE_MIDDLE)
		_zoom(fractal, x, y, 0);
	fractal->calc_left = -1;
	return (0);
}

static void	_zoom(t_fractal *fractal, int x, int y, int in_out)
{
	long double	zoom_level;

	zoom_level = 1.42;
	if (in_out == 1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom * zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom * zoom_level));
		fractal->zoom *= zoom_level;
	}
	else if (in_out == -1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom / zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom / zoom_level));
		fractal->zoom /= zoom_level;
	}
	else if (in_out == 0)
		_center(fractal, x, y);
}

static void	_center(t_fractal *fractal, int x, int y)
{
	fractal->offset_x = (x / fractal->zoom + 
			fractal->offset_x) - (SIZE / 2.0 / fractal->zoom);
	fractal->offset_y = (y / fractal->zoom + 
			fractal->offset_y) - (SIZE / 2.0 / fractal->zoom);
}