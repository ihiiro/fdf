/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:56:47 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/16 11:53:44 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

void	iso_y(t_pixels **pixels, int r, int c, int a)
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
			pixels[i][j].x_transform = x * cos(a * M_PI / 180)
				- pixels[i][j].y * sin(a * M_PI / 180);
			pixels[i][j].y_transform = x * sin(a * M_PI / 180)
				+ pixels[i][j].y * cos(a * M_PI / 180);
			j++;
		}
		i++;
	}
}

void	iso_x(t_pixels **pixels, int r, int c, int a)
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
			pixels[i][j].y_transform = pixels[i][j].y_transform * cos(a * M_PI / 180)
				- pixels[i][j].z * sin(a * M_PI / 180);
			pixels[i][j].z_transform = pixels[i][j].y_transform * sin(a * M_PI / 180)
				+ pixels[i][j].z * cos(a * M_PI / 180);
			j++;
		}
		i++;
	}
}

void	iso_z(t_pixels **pixels, int r, int c, int a)
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
			pixels[i][j].z = pixels[i][j].z * cos(a * M_PI / 180)
				- pixels[i][j].x * sin(a * M_PI / 180);
			pixels[i][j].x = pixels[i][j].z * sin(a * M_PI / 180)
				+ pixels[i][j].x * cos(a * M_PI / 180);
			j++;
		}
		i++;
	}
}
