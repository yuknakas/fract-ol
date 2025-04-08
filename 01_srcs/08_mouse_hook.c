/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_mouse_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:47:52 by yuknakas          #+#    #+#             */
/*   Updated: 2025/04/08 16:48:59 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

int			fr_mouse_hook(int mouse_code, int x, int y, t_fractal *fractal);
static void	_zoom(t_fractal *fractal, int x, int y, int in_out);

int	fr_mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
{
	if (mouse_code == SCROLL_UP)
		_zoom(fractal, x, y, 1);
	else if (mouse_code == SCROLL_DOWN)
		_zoom(fractal, x, y, -1);
	fractal->calc_left = -1;
	return (0);
}

static void	_zoom(t_fractal *fractal, int x, int y, int in_out)
{
	double	zoom_level;

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
	else
		return ;
}
