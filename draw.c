/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:24:46 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/16 12:30:59 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include "fdf.h"

void	put_pixels(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < WINDOW_WIDTH && x >= 0 && y < WINDOW_HEIGHT && y >= 0)
	{
		dst = data->addr + (y * data->line_length
				+ x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	center(t_pixels **pixels, int r, int c)
{
	int	i;
	int	j;

	i = 0;
	while (i < r)
	{
		j = 0;
		while (j < c)
		{
			pixels[i][j].x_transform = (WINDOW_WIDTH / 2) - pixels[i][j].x_transform;
			pixels[i][j].y_transform = (WINDOW_HEIGHT / 2) - pixels[i][j].y_transform;
			j++;
		}
		i++;
	}
}
#include <stdio.h>
void	project_iso(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	iso_y(vars->pixels, vars->r, vars->c, -55);
	iso_x(vars->pixels, vars->r, vars->c, 55);
	center(vars->pixels, vars->r, vars->c);
	while (i < vars->r)
	{
		j = 0;
		while (j < vars->c)
		{
			put_pixels(vars->img, vars->pixels[i][j].x_transform, vars->pixels[i][j].y_transform,
				vars->pixels[i][j].rgb);
			j++;
		}
		i++;
	}
	bresenhams(vars->pixels, vars->r, vars->c, vars->img);
}

void	project(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->r)
	{
		j = 0;
		while (j < vars->c)
		{
			put_pixels(vars->img, vars->pixels[i][j].x_transform, vars->pixels[i][j].y_transform,
				vars->pixels[i][j].rgb);
			j++;
		}
		i++;
	}
	bresenhams(vars->pixels, vars->r, vars->c, vars->img);
}

void	draw(t_pixels **pixels, t_vars vars)
{
	t_data	img;

	img.img = mlx_new_image(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	vars.img = &img;
	vars.zm = 2;
	project_iso(&vars);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
	mlx_key_hook(vars.mlx_win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
