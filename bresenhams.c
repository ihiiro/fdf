/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenhams.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:36:35 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/13 19:58:52 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	apply_x(t_pixels pixel0, t_pixels pixel1, t_data *img)
{
	t_bresenhams	vars;

	vars.x0 = pixel0.x;
	vars.x1 = pixel1.x;
	vars.y0 = pixel0.y;
	vars.y1 = pixel1.y;
	vars.dx = abs(vars.x1 - vars.x0);
	vars.dy = -abs(vars.y1 - vars.y0);
	vars.err = vars.dx + vars.dy;
	if (vars.x0 < vars.x1)
		vars.sx = 1;
	else
		vars.sx = -1;
	if (vars.y0 < vars.y1)
		vars.sy = 1;
	else
		vars.sy = -1;
	while (1)
	{
		put_pixels(img, vars.x0, vars.y0, pixel0.rgb);
		if (vars.x0 == vars.x1 && vars.y0 == vars.y1)
			break;
		vars.e2 = 2 * vars.err;
		if (vars.e2 >= vars.dy)
		{
			vars.err += vars.dy;
			vars.x0 += vars.sx;
		}
		if (vars.e2 <= vars.dx)
		{
			vars.err += vars.dx;
			vars.y0 += vars.sy;
		}
	}
}

static void	apply_y(t_pixels pixel0, t_pixels pixel1, t_data *img)
{
	t_bresenhams	vars;

	vars.x0 = pixel0.x;
	vars.x1 = pixel1.x;
	vars.y0 = pixel0.y;
	vars.y1 = pixel1.y;
	vars.dx = abs(vars.x1 - vars.x0);
	vars.dy = -abs(vars.y1 - vars.y0);
	vars.err = vars.dx + vars.dy;
	if (vars.x0 < vars.x1)
		vars.sx = 1;
	else
		vars.sx = -1;
	if (vars.y0 < vars.y1)
		vars.sy = 1;
	else
		vars.sy = -1;
	while (1)
	{
		put_pixels(img, vars.x0, vars.y0, pixel0.rgb);
		if (vars.x0 == vars.x1 && vars.y0 == vars.y1)
			break;
		vars.e2 = 2 * vars.err;
		if (vars.e2 >= vars.dy)
		{
			vars.err += vars.dy;
			vars.x0 += vars.sx;
		}
		if (vars.e2 <= vars.dx)
		{
			vars.err += vars.dx;
			vars.y0 += vars.sy;
		}
	}
}

void	bresenhams(t_pixels **pixels, int r, int c, t_data *img)
{
	int				i;
	int				j;

	i = 0;
	while (i < r - 1)
	{
		j = 0;
		while (j < c - 1)
		{
			apply_x(pixels[i][j], pixels[i][j + 1], img);
			apply_y(pixels[i][j], pixels[i + 1][j], img);
			j++;
		}
		i++;
	}
}
