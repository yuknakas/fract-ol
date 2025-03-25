/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:24:02 by yuknakas          #+#    #+#             */
/*   Updated: 2025/03/25 15:44:41 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../00_libft/header/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <pthread.h>

# define SIZE 700
# define FLOP 2000000000
# define COST 15
# define BLACK 0x000000
# define MID_YEL 0xfcbe11
# define MANDEL 1
# define JULIA 2
# define SHIP 3

//structure used to convey data
typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*pointer_to_image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	int		type;
	int		max_iterations;
	int		iteration_limit;
	int		calc_left;
}			t_fractal;

// int		main(int argc, char **argv);
int		fr_initialize_setup(t_fractal *fractal, char *arg_name);

//03_calculations
int		fr_calculate_julia(t_fractal *frac);
int		fr_calculate_mandelbrot(t_fractal *frac);
int		fr_calculate_burningship(t_fractal *frac);

//10_utils
void	fr_put_color_pixel(t_fractal *fractal, int x, int y, int color);

#endif