/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:45:34 by yuknakas          #+#    #+#             */
/*   Updated: 2025/03/14 15:54:05 by yuknakas         ###   ########.fr       */
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
}

static int	_input_error_msg(void)
{
	ft_putendl_fd("How to use: ./fractol <fractal_type>", 2);
	ft_putendl_fd("Fractal_types available: AAA BBB CCC", 2);
	return (-1);
}
