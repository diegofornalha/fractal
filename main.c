/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dida-sil <dida-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 07:03:36 by dida-sil          #+#    #+#             */
/*   Updated: 2022/10/11 18:30:57 by dida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	paint_fractal(t_vars *vars)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)vars->iter / (double)vars->max;
	r = 9 * (1 - t) * pow(t, 3) * 255;
	g = 15 * pow((1 - t), 2) * pow(t, 2) * 255;
	b = 8.5 * pow((1 - t), 3) * t * 255;
	pixel_put(vars, vars->line, vars->column, create_rgb(b, g, r));
}

void	draw_fractal(t_vars *vars)
{
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	vars->column = 0;
	while (vars->column < HEIGHT)
	{
		vars->line = 0;
		while (vars->line < WIDTH)
		{
			vars->c_re = (vars->line - WIDTH / 2.0) \
			* 4.0 / WIDTH * vars->zoom + vars->move_x;
			vars->c_im = (vars->column - HEIGHT / 2.0) \
			* 4.0 / WIDTH * vars->zoom + vars->move_y;
			choose_fractol(vars);
			vars->line++;
		}
		vars->column++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}

void	choose_fractol(t_vars *vars)
{
	if (ft_strncmp(vars->arg, "mandelbrot", 10) == 0)
		draw_mandelbrot(vars);
	else if (ft_strncmp(vars->arg, "julia", 5) == 0)
		draw_julia(vars);
	else
	{
		printf("Invalid argument\n");
		exit(0);
	}
}

void	init_data(t_vars *vars)
{
	vars->zoom = 1;
	vars->move_x = -0.1;
	vars->move_y = 0;
	vars->max = 50;
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	check_args(argc, argv, &vars);
	init_data(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Fractol");
	draw_fractal(&vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, zoom_mouse, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
