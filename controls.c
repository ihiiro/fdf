/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:49:01 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/16 12:31:45 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include "fdf.h"

void	transform(t_pixels *pixel)
{
	pixel->x_transform = pixel->x * cos(-55 * M_PI / 180)
		- pixel->y * sin(-55 * M_PI / 180);
	pixel->y_transform = pixel->x * sin(-55 * M_PI / 180)
		+ pixel->y * cos(-55 * M_PI / 180);
	pixel->y_transform = pixel->y_transform * cos(55 * M_PI / 180)
		- pixel->z * sin(55 * M_PI / 180);
	pixel->z_transform = pixel->y_transform * sin(55 * M_PI / 180)
		+ pixel->z * cos(55 * M_PI / 180);
}

#include <stdio.h>
static void	zoom(t_pixels **pixels, int r, int c, int zm)
{
	int	i;
	int	j;

	i = 0;
	while (i < r)
	{
		j = 0;
		while (j < c)
		{
			transform(&pixels[i][j]);

			pixels[i][j].x_transform = pixels[i][j].x_transform * zm;
			pixels[i][j].y_transform = pixels[i][j].y_transform * zm;
			pixels[i][j].z_transform = pixels[i][j].z_transform * zm;

			printf("x=%d, y=%d, z=%d\n", pixels[i][j].x, pixels[i][j].y, pixels[i][j].z);
			j++;
		}
		i++;
	}
	center(pixels, r, c);
}

#include <stdio.h>
int	key_hook(int keycode, t_vars *vars)
{
	vars->img->img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	vars->img->addr = mlx_get_data_addr(vars->img->img, &vars->img->bits_per_pixel,
			&vars->img->line_length, &vars->img->endian);
	zoom(vars->pixels, vars->r, vars->c, vars->zm);
	project(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img->img, 0, 0);
	vars->zm += 1;
	return (0);
}
