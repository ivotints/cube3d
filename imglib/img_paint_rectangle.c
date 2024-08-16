/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_paint_rectangle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:48:05 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/15 10:08:07 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	img_paint_rectangle(t_img_data *img, int *coordinates4, int color)
{
	int	i;
	int	j;
	int	x;
	int	y;

	j = coordinates4[1];
	x = coordinates4[2];
	y = coordinates4[3];
	while (j < y)
	{
		i = coordinates4[0];
		while (i < x)
		{
			my_mlx_pixel_put(img, i, j, color);
			i++;
		}
		j++;
	}
}
