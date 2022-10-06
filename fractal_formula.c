/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_formula.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dida-sil <dida-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 07:00:30 by dida-sil          #+#    #+#             */
/*   Updated: 2022/10/06 10:27:40 by dida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	draw_mandelbrot(t_vars *vars)
{
	vars->x = 0;
	vars->y = 0;
	vars->iter = 0;
	while ((pow(vars->x, 2.0) + pow(vars->y, 2.0) <= 4) \
	&& vars->iter < vars->max)
	{
		vars->x_new = pow(vars->x, 2.0) - pow(vars->y, 2.0) + vars->c_re;
		vars->y = 2 * vars->x * vars->y + vars->c_im;
		vars->x = vars->x_new;
		vars->iter++;
	}
	paint_fractal(vars);
}
