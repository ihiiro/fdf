/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:46:05 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/18 15:12:39 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WINDOW_HEIGHT 1080
# define WINDOW_WIDTH 1920

typedef struct s_bresenhams
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

typedef struct s_pixels
{
	int			x;
	int			y;
	int			z;
	int			x_transform;
	int			y_transform;
	int			z_transform;
	int			rgb;
}				t_pixels;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_vars
{
	t_pixels	**pixels;
	t_data		*img;
	void		*mlx;
	void		*mlx_win;
	int			zm;
	int			x_angle;
	int			y_angle;
	int			z_angle;
	int			x_tr;
	int			y_tr;
	int			r;
	int			c;
}				t_vars;

void	exitf(char *msg);

void	project(t_vars *vars);

void	data(t_pixels **pixels, char *mapfile, int rows, int cols);

void	draw(t_pixels **pixels, t_vars *vars);

void	put_pixels(t_data *data, int x, int y, int color);

void	bresenhams(t_pixels **pixels, int r, int c, t_data *img);

void	iso_x(t_pixels **pixels, int r, int c, int a);
void	iso_y(t_pixels **pixels, int r, int c, int a);
void	iso_z(t_pixels **pixels, int r, int c, int a);

void	project_iso(t_vars *vars, int angle_x, int angle_y, int angle_z);

void	center(t_pixels **pixels, int r, int c);

void	zoom(t_pixels **pixels, t_vars *vars, int n);
void	h_translate(t_pixels **pixels, t_vars *vars, int n, int er);
void	v_translate(t_pixels **pixels, t_vars *vars, int n, int er);
void	rotate_up(t_vars *vars);
void	rotate_down(t_vars *vars);
void	rotate_left(t_vars *vars);
void	rotate_right(t_vars *vars);
void	blackhole_event_horizon(t_vars *vars);

void	transform(t_pixels *pixel, t_vars vars);

int		exits(int keycode, t_vars *vars);

int		exits_x(int keycode, t_vars *vars);

int		cols(char *mapfile);
int		rows(char *mapfile);

int		key_hook(int keycode, t_vars *vars);

long	satoi(char *str);

#endif