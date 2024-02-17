/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:17:10 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/17 16:49:21 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	rotate_up(t_vars *vars)
{
	vars->x_angle += 5;
	project_iso(vars, vars->x_angle, vars->y_angle);
}

void	rotate_down(t_vars *vars)
{
	vars->x_angle -= 5;
	project_iso(vars, vars->x_angle, vars->y_angle);
}

void	rotate_left(t_vars *vars)
{
	vars->y_angle -= 5;
	project_iso(vars, vars->x_angle, vars->y_angle);
}

void	rotate_right(t_vars *vars)
{
	vars->y_angle += 5;
	project_iso(vars, vars->x_angle, vars->y_angle);
}
