/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:24:46 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/16 10:01:32 by yel-yaqi         ###   ########.fr       */
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

static void	center(t_pixels **pixels, int r, int c)
{
	int	i;
	int	j;

	i = 0;
	while (i < r)
	{
		j = 0;
		while (j < c)
		{
			pixels[i][j].x = (WINDOW_WIDTH / 2) - pixels[i][j].x;
			pixels[i][j].y = (WINDOW_HEIGHT / 2) - pixels[i][j].y;
			j++;
		}
		i++;
	}
}

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
			put_pixels(vars->img, vars->pixels[i][j].x, vars->pixels[i][j].y, vars->pixels[i][j].rgb);
			j++;
		}
		i++;
	}
	bresenhams(vars->pixels, vars->r, vars->c, vars->img);
}

void	init_vars(t_vars *vars)
{
	vars->img = &img;
	vars->mlx = mlx;
	vars->mlx_win = mlx_win;
	vars->pixels = pixels;
	vars->zm = 30;
	vars->r = r;
	vars->c = c;
}

void	draw(t_pixels **pixels, int r, int c)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_vars	vars;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF");
	img.img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	project_iso(&vars);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
