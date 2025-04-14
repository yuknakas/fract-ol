/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:45:34 by yuknakas          #+#    #+#             */
/*   Updated: 2025/04/12 16:22:47 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

int			main(int argc, char **argv);
static int	_input_error_msg(void);
static int	_find_type(t_fractal *fractal, char *arg_name);

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (argc != 2)
		return (_input_error_msg());
	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
		return (-1);
	if (_find_type(fractal, argv[1]))
	{
		free(fractal);
		return (_input_error_msg());
	}
	if (!fr_setup_window(fractal))
	{
		fr_destroy_window(fractal);
		return (_input_error_msg());
	}
	mlx_key_hook(fractal->window, fr_key_hook, fractal);
	mlx_mouse_hook(fractal->window, fr_mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, fr_destroy_window, fractal);
	mlx_loop_hook(fractal->mlx, fr_draw, fractal);
	mlx_loop(fractal->mlx);
	return (0);
}

static int	_input_error_msg(void)
{
	ft_putendl_fd("How to use: ./fractol <fractal_type>", 2);
	ft_putendl_fd(
		"Fractal_types available: mandelbrot, juilia, burningship", 2);
	return (-1);
}

static int	_find_type(t_fractal *fractal, char *arg_name)
{
	if (!ft_strncmp(arg_name, "mandelbrot", 10))
		fractal->type = MANDEL;
	else if (!ft_strncmp(arg_name, "julia", 10))
	{
		fractal->cx = -0.745429;
		fractal->cy = 0.05;
		fractal->type = JULIA;
	}
	else if (!ft_strncmp(arg_name, "burningship", 10))
		fractal->type = SHIP;
	else
		return (1);
	return (0);
}
