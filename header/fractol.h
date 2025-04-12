/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:24:02 by yuknakas          #+#    #+#             */
/*   Updated: 2025/04/12 15:42:24 by yuknakas         ###   ########.fr       */
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
# define COST 40
# define BLACK 0x000000
# define MID_YEL 0xfcbe11
# define MANDEL 1
# define JULIA 2
# define SHIP 3

// KEYCODES
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define R 114
# define C 99
# define H 104
# define J 106
# define P 112
# define M 109

// MOUSECODES
# define MOUSE_LEFT 1
# define MOUSE_MIDDLE 2
# define MOUSE_RIGHT 3
# define SCROLL_UP 4
# define SCROLL_DOWN 5

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
int		fr_initialize_setup(t_fractal *fractal);
int		fr_setup_window(t_fractal *fractal, char *arg_name);

//02_draw
void	fr_draw(t_fractal *fractal);
int		fr_first_mandel(t_fractal *fractal);
int		fr_first_julia(t_fractal *fractal);
int		fr_first_ship(t_fractal *fractal);
int		fr_draw_mandel(t_fractal *fractal);
int		fr_draw_julia(t_fractal *fractal);
int		fr_draw_ship(t_fractal *fractal);

//03_calculations
int		fr_calculate_julia(t_fractal *frac);
int		fr_calculate_mandelbrot(t_fractal *frac);
int		fr_calculate_burningship(t_fractal *frac);

//04_05_hooks
int		fr_key_hook(int key_code, t_fractal *fractal);
int		fr_mouse_hook(int mouse_code, int x, int y, t_fractal *fractal);

//10_utils
void	fr_put_color_pixel(t_fractal *fractal, int x, int y, int color);
int		fr_destroy_window(t_fractal *fractal);
void	fr_initial_iteration(t_fractal *fractal);

#endif