/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_paint_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:19:29 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/01 20:19:51 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	img_paint_square(t_img_data *data, int color, int x, int y, int side)
{
	int	i;
	int	j;

	j = y;
	while (j < y + side)
	{
		i = x;
		while (i < x + side)
		{
			my_mlx_pixel_put(data, i, j, color);
			i++;
		}
		j++;
	}
}
