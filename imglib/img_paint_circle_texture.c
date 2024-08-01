/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_paint_circle_texture.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:44:47 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/01 22:16:32 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	img_paint_circle_texture(t_img_data *img, int x, int y, int radius, t_img_data *texture)
{
	int		i;
	int		j;
	double	distance;
	int		color;

	j = y - radius;
	while (j < y + radius)
	{
		i = x - radius;
		while (i < x + radius)
		{
			distance = sqrt(pow(x - i, 2) + pow(y - j, 2));
			if (distance < radius)
			{
				color = img_get_color(texture, i, j);
				my_mlx_pixel_put(img, i, j, color);
			}
			i++;
		}
		j++;
	}
}
