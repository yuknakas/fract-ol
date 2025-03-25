/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:45:34 by yuknakas          #+#    #+#             */
/*   Updated: 2025/03/25 15:40:54 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

int			main(int argc, char **argv);
static int	_input_error_msg(void);

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (argc != 2)
		return (_input_error_msg());
	fractal = malloc(sizeof(fractal));
	if (fractal == NULL)
		return (-1);
	if (!fr_initialize_setup(fractal, argv[1]))
		return (_input_error_msg());
	fr_identify_type(fractal);
	//free all memory
	return (0);
}

int	fr_identify_type(t_fractal *fractal)
{
	
	return (0);
}

static int	_input_error_msg(void)
{
	ft_putendl_fd("How to use: ./fractol <fractal_type>", 2);
	ft_putendl_fd(
		"Fractal_types available: mandelbrot, juilia, burningship", 2);
	return (-1);
}
