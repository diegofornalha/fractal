/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_formula.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dida-sil <dida-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 07:00:30 by dida-sil          #+#    #+#             */
/*   Updated: 2022/10/11 18:18:01 by dida-sil         ###   ########.fr       */
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

# define JU_RE -0.789 
# define JU_IM -0.345

void	draw_julia(t_vars *vars)
{
	vars->x = vars->c_re;
	vars->y = vars->c_im;
	vars->iter = 0;
	while ((pow(vars->x, 2.0) + pow(vars->y, 2.0) <= 4) \
	&& vars->iter < vars->max)
	{
		vars->x_new = pow(vars->x, 2.0) - pow(vars->y, 2.0) + JU_RE;
		vars->y = 2.0 * vars->x * vars->y + JU_IM;
		vars->x = vars->x_new;
		vars->iter++;
	}
	paint_fractal(vars);
}