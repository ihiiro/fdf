/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:46:05 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/13 11:15:24 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct	s_pixels
{
	int			x;
	int			y;
	int			z;
	int			rgb;
}				t_pixels;

void	exitf(char *msg);

void	data(t_pixels **pixels, char *mapfile, int rows, int cols);

int		cols(char *mapfile);
int		rows(char *mapfile);

long	satoi(char *str);


#endif