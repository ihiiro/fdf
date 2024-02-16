/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:16:41 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/16 16:19:52 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	h_translate(t_pixels **pixels, t_vars vars, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars.r)
	{
		j = 0;
		while (j < vars.c)
		{
			pixels[i][j].x_transform += n;
			j++;
		}
		i++;
	}
}

void	v_translate(t_pixels **pixels, t_vars vars, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars.r)
	{
		j = 0;
		while (j < vars.c)
		{
			pixels[i][j].y_transform += n;
			j++;
		}
		i++;
	}
}
