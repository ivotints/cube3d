/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_paint_circle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:46:18 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/01 22:16:34 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	img_paint_circle(t_img_data *data, int *xyr, int color)
{
	int		i;
	int		j;
	int		distance;
	int		radius;

	radius = xyr[2];
	j = xyr[1] - radius;
	while (j < xyr[1] + radius)
	{
		i = xyr[0] - radius;
		while (i < xyr[0] + radius)
		{
			distance = pow(xyr[0] - i, 2);
			distance += pow(xyr[1] - j, 2);
			distance = sqrt(distance);
			if (distance < radius)
			{
				my_mlx_pixel_put(data, i, j, color);
			}
			i++;
		}
		j++;
	}
}
