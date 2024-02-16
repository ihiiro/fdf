/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:13:53 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/16 16:14:19 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

void	transform(t_pixels *pixel, t_vars vars)
{
	pixel->x_transform = pixel->x * cos(vars.y_angle * M_PI / 180)
		- pixel->y * sin(vars.y_angle * M_PI / 180);
	pixel->y_transform = pixel->x * sin(vars.y_angle * M_PI / 180)
		+ pixel->y * cos(vars.y_angle * M_PI / 180);
	pixel->y_transform = pixel->y_transform * cos(vars.x_angle * M_PI / 180)
		- pixel->z * sin(vars.x_angle * M_PI / 180);
	pixel->z_transform = pixel->y_transform * sin(vars.x_angle * M_PI / 180)
		+ pixel->z * cos(vars.x_angle * M_PI / 180);
}
