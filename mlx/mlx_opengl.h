/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_opengl.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dida-sil <dida-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:12:01 by dida-sil          #+#    #+#             */
/*   Updated: 2022/10/06 09:12:13 by dida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    *mlx_new_opengl_window(void *mlx_ptr, int size_x, int size_y, char *title);

int	mlx_opengl_swap_buffers(void *win_ptr);

int	mlx_opengl_window_set_context(void *win_ptr);
