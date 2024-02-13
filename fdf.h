/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:46:05 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/13 19:56:11 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WINDOW_HEIGHT 1080
# define WINDOW_WIDTH 1920

typedef struct	s_bresenhams
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
	int			x0;
	int			x1;
	int			y0;
	int			y1;
}				t_bresenhams;

typedef struct	s_pixels
{
	int			x;
	int			y;
	int			z;
	int			rgb;
}				t_pixels;

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

void	exitf(char *msg);

void	data(t_pixels **pixels, char *mapfile, int rows, int cols);

void	draw(t_pixels **pixels, int r, int c);

void	put_pixels(t_data *data, int x, int y, int color);

void	bresenhams(t_pixels **pixels, int r, int c, t_data *img);

int		cols(char *mapfile);
int		rows(char *mapfile);

long	satoi(char *str);

#endif