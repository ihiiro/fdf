/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rows_cols.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:10:38 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/15 18:48:48 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "fdf.h"

int	cols(char *mapfile)
{
	char	*cols;
	int		n;
	int		i;
	int		fd;

	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		exitf("Error: could not open file\n");
	n = 0;
	i = 0;
	cols = get_next_line(fd);
	if (!cols)
		exit(EXIT_FAILURE);
	while (cols[i])
	{
		while (cols[i] == 32)
			i++;
		while (cols[i] && cols[i] != 32)
			i++;
		if (cols[i] == 32)
			n++;
	}
	free(cols);
	close(fd);
	return (n + 1);
}

int	rows(char *mapfile)
{
	char	*rows;
	int		n;
	int		i;
	int		fd;

	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		exitf("Error: could not open file\n");
	n = 0;
	i = 0;
	rows = get_next_line(fd);
	if (!rows)
		exit(EXIT_FAILURE);
	while (rows)
	{
		n++;
		free(rows);
		rows = get_next_line(fd);
	}
	close(fd);
	return (n);
}
