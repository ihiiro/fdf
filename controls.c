/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:49:01 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/16 21:48:04 by yel-yaqi         ###   ########.fr       */
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
	handle_actions(keycode, vars);
	project(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img->img, 0, 0);
	return (0);
}
