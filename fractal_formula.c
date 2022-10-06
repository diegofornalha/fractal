/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_formula.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dida-sil <dida-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 07:00:30 by dida-sil          #+#    #+#             */
/*   Updated: 2022/10/06 18:31:57 by dida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mandelbrot(t_vars *vars)
{
	vars->z_re = vars->c_re;
	vars->z_im = vars->c_im;
	vars->iter = 0;
	while (vars->z_re * vars->z_re + vars->z_im * vars->z_im < 4 && \
			vars->iter < vars->max)
	{
		vars->tmp = vars->z_re;
		vars->z_re = vars->z_re * vars->z_re - vars->z_im * vars->z_im + \
		vars->c_re;
		vars->z_im = 2 * vars->z_im * vars->tmp + vars->c_im;
		vars->iter++;
	}
	paint_fractal(vars);
}
