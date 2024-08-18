/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_paint_floor_ceiling.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:14:39 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/18 15:31:23 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	img_paint_rectangle(t_img_data *img, int *coord4, int color)
{
	int	i;
	int	j;
	int	x;
	int	y;

	j = coord4[1];
	x = coord4[2];
	y = coord4[3];
	while (j < y)
	{
		i = coord4[0];
		while (i < x)
		{
			my_mlx_pixel_put(img, i, j, color);
			i++;
		}
		j++;
	}
}

void	img_paint_floor_ceiling(t_all_data *data)
{
	int	coordinates[4];

	coordinates[0] = 0;
	coordinates[1] = 0;
	coordinates[2] = S_WIDTH;
	coordinates[3] = S_HEIGHT / 2;
	img_paint_rectangle(&(data->img), coordinates, data->textures.c);
	coordinates[0] = 0;
	coordinates[1] = S_HEIGHT / 2;
	coordinates[2] = S_WIDTH;
	coordinates[3] = S_HEIGHT;
	img_paint_rectangle(&(data->img), coordinates, data->textures.f);
}
