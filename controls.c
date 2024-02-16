/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:49:01 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/16 13:47:21 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include "fdf.h"

#include <stdio.h>


#include <stdio.h>
int	key_hook(int keycode, t_vars *vars)
{
	vars->img->img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	vars->img->addr = mlx_get_data_addr(vars->img->img, &vars->img->bits_per_pixel,
			&vars->img->line_length, &vars->img->endian);
	
	if (keycode == 6)
	{
		vars->zm += 1;
		zoom(vars->pixels, vars->r, vars->c, vars->zm);
	}
	else if (keycode == 7 && vars->zm > 1)
	{
		vars->zm -= 1;
		printf("%d\n", vars->zm);
		zoom(vars->pixels, vars->r, vars->c, vars->zm);
	}
	// printf("%d\n", keycode);
	project(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img->img, 0, 0);
	return (0);
}
