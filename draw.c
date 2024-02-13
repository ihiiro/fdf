/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:24:46 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/13 15:51:40 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

static void	put_pixels(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	project(t_pixels **pixels, int r, int c, t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < r)
	{
		j = 0;
		while (j < c)
		{
			put_pixels(img, pixels[i][j].x, pixels[i][j].y - pixels[i][j].z, pixels[i][j].rgb);
			// put_pixels(img, pixels[i][j].x, pixels[i][j].y, pixels[i][j].rgb);
			j++;
		}
		i++;
	}
}

void	draw(t_pixels **pixels, int r, int c)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 3000, 2400, "FdF");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	project(pixels, r, c, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
