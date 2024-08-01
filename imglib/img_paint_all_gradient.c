/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_paint_all_gradient.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:39:12 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/01 22:16:25 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	img_paint_all_gradient(t_img_data *data, int color1, int color2)
{
	int x, y;
	double RGB1[3], RGB2[3], deltaRGB[3], currentRGB[3];
	int color;

	RGB1[0] = (color1 >> 16) & 0xFF;
	RGB1[1] = (color1 >> 8) & 0xFF;
	RGB1[2] = color1 & 0xFF;
	RGB2[0] = (color2 >> 16) & 0xFF;
	RGB2[1] = (color2 >> 8) & 0xFF;
	RGB2[2] = color2 & 0xFF;

	deltaRGB[0] = (RGB2[0] - RGB1[0]) / (double)S_HEIGHT;
	deltaRGB[1] = (RGB2[1] - RGB1[1]) / (double)S_HEIGHT;
	deltaRGB[2] = (RGB2[2] - RGB1[2]) / (double)S_HEIGHT;

	y = 0;
	color = color1;
	while (y < S_HEIGHT)
	{
		x = 0;
		currentRGB[0] = RGB1[0] + deltaRGB[0] * y;
		currentRGB[1] = RGB1[1] + deltaRGB[1] * y;
		currentRGB[2] = RGB1[2] + deltaRGB[2] * y;
		color = ((int)currentRGB[0] << 16) | ((int)currentRGB[1] << 8) | (int)currentRGB[2];
		while (x < S_WIDTH)
		{
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
}
