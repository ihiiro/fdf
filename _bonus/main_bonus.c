/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:46:03 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/18 15:59:24 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <fcntl.h>
#include "fdf_bonus.h"

int	main(int argc, char **argv)
{
	t_vars		vars;
	int			i;
	int			projection;

	if (argc > 2)
		exitf("Error: more than 1 argument");
	vars.r = rows(argv[1]);
	vars.c = cols(argv[1]);
	vars.pixels = (t_pixels **)malloc(sizeof(t_pixels *) * vars.r);
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF");
	i = 0;
	while (i < vars.r)
		vars.pixels[i++] = (t_pixels *)malloc(sizeof(t_pixels) * vars.c);
	data(vars.pixels, argv[1], vars.r, vars.c);
	draw(vars.pixels, &vars);
}
