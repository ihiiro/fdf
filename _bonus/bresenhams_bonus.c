/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenhams_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:36:35 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/18 15:40:08 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	b_fill(t_bresenhams *vars, t_pixels pixel0, t_pixels pixel1)
{
	vars->x0 = pixel0.x_transform;
	vars->x1 = pixel1.x_transform;
	vars->y0 = pixel0.y_transform;
	vars->y1 = pixel1.y_transform;
	vars->dx = abs(vars->x1 - vars->x0);
	vars->dy = -abs(vars->y1 - vars->y0);
	vars->err = vars->dx + vars->dy;
	if (vars->x0 < vars->x1)
		vars->sx = 1;
	else
		vars->sx = -1;
	if (vars->y0 < vars->y1)
		vars->sy = 1;
	else
		vars->sy = -1;
}

static void	apply_x(t_pixels pixel0, t_pixels pixel1, t_data *img)
{
	t_bresenhams	vars;

	b_fill(&vars, pixel0, pixel1);
	while (1)
	{
		put_pixels(img, vars.x0, vars.y0, pixel0.rgb);
		if (vars.x0 == vars.x1 && vars.y0 == vars.y1)
			break ;
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

	b_fill(&vars, pixel0, pixel1);
	while (1)
	{
		put_pixels(img, vars.x0, vars.y0, pixel0.rgb);
		if (vars.x0 == vars.x1 && vars.y0 == vars.y1)
			break ;
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

	i = -1;
	while (++i < r - 1)
	{
		j = 0;
		while (j < c - 1)
		{
			if (pixels[i][j].rgb != 16777215 && i > 0 && j > 0)
			{
				apply_x(pixels[i][j], pixels[i][j + 1], img);
				apply_x(pixels[i][j], pixels[i][j - 1], img);
				apply_y(pixels[i][j], pixels[i + 1][j], img);
				apply_y(pixels[i][j], pixels[i - 1][j], img);
			}
			else
			{
				pixels[i][j].rgb = pixels[i][j + 1].rgb;
				apply_x(pixels[i][j], pixels[i][j + 1], img);
				apply_y(pixels[i][j], pixels[i + 1][j], img);
			}
			j++;
		}
	}
}
