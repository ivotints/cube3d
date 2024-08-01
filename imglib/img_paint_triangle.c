/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_paint_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:40:03 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/01 22:17:04 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	img_paint_triangle(t_img_data *data, int color, double x, double y, double side)
{
	double	i;
	double	j;
	double	median;

	j = y;
	median = sqrt(pow(side, 2) - pow(side / 2, 2));
	while (j < y + median)
	{
		i = x - side / 2;
		while (i < x + side / 2)
		{
			if (i >= x - ((j - y) / median) * (side / 2)
				&& i <= x + ((j - y) / median) * (side / 2))
			{
				my_mlx_pixel_put(data, i, j, color);
			}
			i++;
		}
		j++;
	}
}
