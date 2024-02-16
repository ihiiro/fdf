/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:49:01 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/16 10:53:15 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

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
			pixels[i][j].x += zm;
			pixels[i][j].y += zm;
			pixels[i][j].z += zm;

			printf("x=%d, y=%d, z=%d\n", pixels[i][j].x, pixels[i][j].y, pixels[i][j].z);
			j++;
		}
		i++;
	}
}

#include <stdio.h>
int	key_hook(int keycode, t_vars *vars)
{
	vars->img->img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	vars->img->addr = mlx_get_data_addr(vars->img->img, &vars->img->bits_per_pixel,
			&vars->img->line_length, &vars->img->endian);
	zoom(vars->pixels, vars->r, vars->c, vars->zm);
	project_iso(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img->img, 0, 0);
	return (0);
}
