/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:16:09 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/18 15:40:03 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

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
			transform(&pixels[i][j], *vars);
			pixels[i][j].x_transform = pixels[i][j].x_transform * vars->zm;
			pixels[i][j].y_transform = pixels[i][j].y_transform * vars->zm;
			pixels[i][j].z_transform = pixels[i][j].z_transform * vars->zm;
			j++;
		}
		i++;
	}
	center(pixels, vars->r, vars->c);
	h_translate(pixels, vars, vars->x_tr * vars->zm, 1);
	v_translate(pixels, vars, vars->y_tr * vars->zm, 1);
}
