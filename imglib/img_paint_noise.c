/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_paint_noise.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:45:24 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/01 22:16:50 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	img_paint_noise(t_img_data *data, int delta)
{
	int	x;
	int	y;
	int	color;
	int	RGB[6];

	if (delta < 1)
		return ;
	y = 0;
	while (y < S_HEIGHT)
	{
		x = 0;
		while (x < S_WIDTH)
		{
			color = img_get_color(data, x, y);
			RGB[0] = ((color >> 16) & 0xFF) - delta + (rand() % (delta * 2));
			if (RGB[0] > 0xFF)
				RGB[0] = 0xFF;
			if (RGB[0] < 0)
				RGB[0] = 0;
			RGB[1] = ((color >> 8) & 0xFF) - delta + (rand() % (delta * 2));
			if (RGB[1] > 0xFF)
				RGB[1] = 0xFF;
			if (RGB[1] < 0)
				RGB[1] = 0;
			RGB[2] = (color & 0xFF) - delta + (rand() % (delta * 2));
			if (RGB[2] > 0xFF)
				RGB[2] = 0xFF;
			if (RGB[2] < 0)
				RGB[2] = 0;
			color = (RGB[0] << 16) | (RGB[1] << 8) | (RGB[2]);
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
}
