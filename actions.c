/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:29:15 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/16 14:02:51 by yel-yaqi         ###   ########.fr       */
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

void	zoom(t_pixels **pixels, t_vars *vars, int n)
{
	int	i;
	int	j;

	i = 0;
	vars->zm += n;
	while (i < vars->r)
	{
		j = 0;
		while (j < vars->c)
		{
			transform(&pixels[i][j]);
			pixels[i][j].x_transform = pixels[i][j].x_transform * vars->zm;
			pixels[i][j].y_transform = pixels[i][j].y_transform * vars->zm;
			pixels[i][j].z_transform = pixels[i][j].z_transform * vars->zm;
			j++;
		}
		i++;
	}
	center(pixels, vars->r, vars->c);
}

void	h_translate(t_pixels **pixels, t_vars vars, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars.r)
	{
		j = 0;
		while (j < vars.c)
		{
			pixels[i][j].x_transform += n;
			pixels[i][j].y_transform += n;
			// pixels[i][j].x_transform += n;
			j++;
		}
		i++;
	}
}
