/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:49:01 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/16 21:36:55 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"

static void	handle_actions(int keycode, t_vars *vars)
{
	if (keycode == 6)
		zoom(vars->pixels, vars, 1);
	else if (keycode == 7 && vars->zm > 1)
		zoom(vars->pixels, vars, -1);
	else if (keycode == 124)
		h_translate(vars->pixels, *vars, -20);
	else if (keycode == 123)
		h_translate(vars->pixels, *vars, 20);
	else if (keycode == 126)
		v_translate(vars->pixels, *vars, 20);
	else if (keycode == 125)
		v_translate(vars->pixels, *vars, -20);
	else if (keycode == 13)
		rotate_up(vars);
	else if (keycode == 1)
		rotate_down(vars);
	else if (keycode == 2)
		rotate_left(vars);
	else if (keycode == 0)
		rotate_right(vars);
	else if (keycode == 53)
		exits(1, vars);
}

int	key_hook(int keycode, t_vars *vars)
{
	vars->img->img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	vars->img->addr = mlx_get_data_addr(vars->img->img,
			&vars->img->bits_per_pixel, &vars->img->line_length,
			&vars->img->endian);
	handle_actions(keycode, vars);
	project(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img->img, 0, 0);
	return (0);
}
