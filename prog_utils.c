/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dida-sil <dida-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 07:11:48 by dida-sil          #+#    #+#             */
/*   Updated: 2022/10/06 10:28:52 by dida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_args(int argc, char **argv, t_vars *vars)
{
	if (argc != 2)
	{
		puts("Usage: ./fractol [fractal name]\n");
		puts("Available fractals: Mandelbrot\n");
		exit(0);
	}
	else
	{
		vars->arg = argv[1];
	}
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n && (*str1 == *str2) && (*str1 != '\0' || *str2 != '\0'))
	{
		str1++;
		str2++;
		n--;
	}
	if (n > 0)
		return (*str1 - *str2);
	else
		return (*(str1 - 1) - *(str2 - 1));
}
