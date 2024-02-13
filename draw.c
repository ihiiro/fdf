/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:24:46 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/13 19:52:37 by yel-yaqi         ###   ########.fr       */
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
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

static void	iso(t_pixels **pixels, int r, int c)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	while (i < r)
	{
		j = 0;
		while (j < c)
		{
			x = pixels[i][j].x;
			pixels[i][j].x = (x - pixels[i][j].y) * cos(.523599);
			pixels[i][j].y = (x + pixels[i][j].y) * sin(.523599) - pixels[i][j].z;
			j++;
		}
		i++;
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

static void	project(t_pixels **pixels, int r, int c, t_data *img)
{
	int	i;
	int	j;

	i = 0;
	iso(pixels, r, c);
	center(pixels, r, c);
	while (i < r)
	{
		j = 0;
		while (j < c)
		{
			put_pixels(img, pixels[i][j].x, pixels[i][j].y, pixels[i][j].rgb);
			j++;
		}
		i++;
	}
	bresenhams(pixels, r, c, img);
}

void	draw(t_pixels **pixels, int r, int c)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF");
	img.img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	project(pixels, r, c, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
