/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 20:28:13 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/16 21:48:49 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"

int	exits_x(int keycode, t_vars *vars)
{
	(void)keycode;
	exit(EXIT_SUCCESS);
	return (0);
}

int	exits(int keycode, t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	(void)keycode;
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	while (i < vars->r)
	{
		free((void *)vars->pixels[i]);
		i++;
	}
	free(vars->pixels);
	exit(EXIT_SUCCESS);
	return (0);
}
