/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:51:25 by yuknakas          #+#    #+#             */
/*   Updated: 2025/03/25 15:41:03 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

int			fr_initialize_setup(t_fractal *fractal, char *arg_name);
static int	_setup_window(t_fractal *fractal);

int	fr_initialize_setup(t_fractal *fractal, char *arg_name)
{
	if (!_setup_window)
		return (0);
	fractal->x = 0;
	fractal->y = 0;
	fractal->color = MID_YEL;
	fractal->zoom = 300;
	fractal->offset_x = -1.21;
	fractal->offset_y = -1.21;
	fractal->iteration_limit = 42;
	if (ft_strncmp(arg_name, "mandelbrot", 10))
		fractal->type = MANDEL;
	else if (ft_strncmp(arg_name, "julia", 10))
		fractal->type = JULIA;
	else if (ft_strncmp(arg_name, "burningship", 10))
		fractal->type = SHIP;
	else
		return (0);
	return (1);
}

static int	_setup_window(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	fractal->window = mlx_new_window(fractal->mlx, SIZE, SIZE, "fract-ol");
	fractal->image = mlx_new_image(fractal->mlx, SIZE, SIZE);
	fractal->pointer_to_image = mlx_get_data_addr(fractal->image,
			&fractal->bits_per_pixel,
			&fractal->size_line,
			&fractal->endian);
	if (fractal->mlx == NULL || fractal->window == NULL
		|| fractal->image == NULL || fractal->pointer_to_image == NULL)
	{
		ft_putendl_fd("Error with seeting up window", 2);
		return (0);
	}
	return (1);
}
