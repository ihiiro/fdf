/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:46:03 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/13 14:30:57 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

parsing
	open file for counting/malloc
	malloc 2d array of structs {x, y, z, rgb}
	open file for reading data
	convert from hex to dec
draw pixels isometrically
	transform all points to iso
	draw lines between points

*/

#include <fcntl.h>
#include "fdf.h"

#include <stdio.h>
#include <stdlib.h>
int	main(int argc, char **argv)
{
	t_pixels	**pixels;
	int			i;
	int			r;
	int			c;

	r = rows(argv[1]);
	c = cols(argv[1]);
	// printf("r=%d, c=%d", r, c); exit(0);
	pixels = (t_pixels **)malloc(sizeof(t_pixels *) * r);
	i = 0;
	while (i < r)
		pixels[i++] = (t_pixels *)malloc(sizeof(t_pixels) * c);
	data(pixels, argv[1], r, c);
	// 
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("(%d, %d, %d, %d)\n", pixels[i][j].x, pixels[i][j].y, pixels[i][j].z, pixels[i][j].rgb);
		}
		// printf("\n");
	}
	// 
}
