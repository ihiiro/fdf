/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blackhole_event_horizon.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:08:09 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/18 15:15:18 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	blackhole_event_horizon(t_vars *vars)
{
	vars->z_angle += 5;
	project_iso(vars, vars->x_angle, vars->y_angle, vars->z_angle);
}
