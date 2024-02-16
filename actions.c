/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:29:15 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/16 13:38:03 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

static void	transform(t_pixels *pixel)
{
	pixel->x_transform = pixel->x * cos(-55 * M_PI / 180)
		- pixel->y * sin(-55 * M_PI / 180);
	pixel->y_transform = pixel->x * sin(-55 * M_PI / 180)
		+ pixel->y * cos(-55 * M_PI / 180);
	pixel->y_transform = pixel->y_transform * cos(55 * M_PI / 180)
		- pixel->z * sin(55 * M_PI / 180);
	pixel->z_transform = pixel->y_transform * sin(55 * M_PI / 180)
		+ pixel->z * cos(55 * M_PI / 180);
}

void	zoom(t_pixels **pixels, int r, int c, int zm)
{
	int	i;
	int	j;

	i = 0;
	while (i < r)
	{
		j = 0;
		while (j < c)
		{
			transform(&pixels[i][j]);
			pixels[i][j].x_transform = pixels[i][j].x_transform * zm;
			pixels[i][j].y_transform = pixels[i][j].y_transform * zm;
			pixels[i][j].z_transform = pixels[i][j].z_transform * zm;
			j++;
		}
		i++;
	}
	center(pixels, r, c);
}
