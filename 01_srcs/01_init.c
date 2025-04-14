/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:51:25 by yuknakas          #+#    #+#             */
/*   Updated: 2025/04/12 16:21:15 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

int			fr_initialize_setup(t_fractal *fractal);
int			fr_setup_window(t_fractal *fractal);

int	fr_initialize_setup(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->calc_left = -1;
	fractal->color = MID_YEL;
	fractal->zoom = (long double)300;
	fractal->offset_x = -1.21;
	fractal->offset_y = -1.21;
	fractal->iteration_limit = 420;
	return (1);
}

int	fr_setup_window(t_fractal *fractal)
{
	fr_initialize_setup(fractal);
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
