/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:43:41 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/16 12:28:23 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line/get_next_line.h"
#include "fdf.h"

static int	pow(int base, int exp)
{
	int	result;

	result = 1;
	if (exp == 0)
		return (1);
	else if (exp == 1)
		return (base);
	while (exp >= 1)
	{
		result *= base;
		exp--;
	}
	return (result);
}

static int	hex_to_dec(char hex)
{
	if (hex >= '0' && hex <= '9')
		return (satoi(&hex));
	else if (hex == 'A' || hex == 'a')
		return (10);
	else if (hex == 'B' || hex == 'b')
		return (11);
	else if (hex == 'C' || hex == 'c')
		return (12);
	else if (hex == 'D' || hex == 'd')
		return (13);
	else if (hex == 'E' || hex == 'e')
		return (14);
	return (15);
}

static int	rgb(char *hex)
{
	int	dec;
	int	i;
	int	j;

	i = 0;
	dec = 0;
	while (hex[i] && hex[i] != ' ')
		i++;
	i--;
	j = 0;
	while (i >= 0)
	{
		dec += hex_to_dec(hex[j]) * pow(16, i);
		i--;
		j++;
	}
	return (dec);
}

static void	cols_fill(t_pixels *row, char *line, int cols, int y)
{
	int	i;
	int	x;
	int	z;

	i = 0;
	x = 0;
	while (i < cols)
	{
		row[i].z = satoi(line) * -10;
		row[i].x = x * -10;
		row[i].y = y * -10;
		while (*line >= '0' && *line <= '9')
			line++;
		if (*line == ',')
			row[i].rgb = rgb(line + 3);
		else
			row[i].rgb = 0xFFFFFF;
		while (*line && *line != 32)
			line++;
		while (*line == 32)
			line++;
		x++;
		i++;
	}
}

void	data(t_pixels **pixels, char *mapfile, int rows, int cols)
{
	char	*row;
	int		fd;
	int		y;

	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		exitf("Error: could not open file\n");
	row = get_next_line(fd);
	y = 0;
	while (y < rows)
	{
		cols_fill(pixels[y], row, cols, y);
		free(row);
		row = get_next_line(fd);
		y++;
	}
	close(fd);
}
