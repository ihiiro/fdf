/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:49:01 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/18 15:40:10 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include <stdlib.h>
#include "fdf_bonus.h"

static int	handle_actions(int keycode, t_vars *vars)
{
	if (keycode == 6 && vars->zm)
		zoom(vars->pixels, vars, 1);
	else if (keycode == 7 && vars->zm > 1)
		zoom(vars->pixels, vars, -1);
	else if (keycode == 124 && vars->zm == 1)
		h_translate(vars->pixels, vars, -20, 0);
	else if (keycode == 123 && vars->zm == 1)
		h_translate(vars->pixels, vars, 20, 0);
	else if (keycode == 126 && vars->zm == 1)
		v_translate(vars->pixels, vars, 20, 0);
	else if (keycode == 125 && vars->zm == 1)
		v_translate(vars->pixels, vars, -20, 0);
	else if (keycode == 13 && vars->zm == 1)
		return (rotate_up(vars), 1);
	else if (keycode == 1 && vars->zm == 1)
		return (rotate_down(vars), 1);
	else if (keycode == 2 && vars->zm == 1)
		return (rotate_left(vars), 1);
	else if (keycode == 0 && vars->zm == 1)
		return (rotate_right(vars), 1);
	else if (keycode == 53)
		exits(1, vars);
	else if (keycode == 49)
		return (blackhole_event_horizon(vars), 1);
	return (0);
}

static void	paint_black(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		j = 0;
		while (j < WINDOW_HEIGHT)
		{
			put_pixels(vars->img, i, j, 0x0);
			j++;
		}
		i++;
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	paint_black(vars);
	if (!handle_actions(keycode, vars))
		project(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img->img, 0, 0);
	return (0);
}
