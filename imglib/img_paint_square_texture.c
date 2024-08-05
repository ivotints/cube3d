/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_paint_square_texture.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 01:47:09 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/05 01:52:33 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"


void	img_paint_square_texture(t_all_data *data, int *xyr, void *img)
{
	t_img_data	tmp;
	int			i;
	int			j;
	int			color;

	tmp.img = img;
	tmp.addr = mlx_get_data_addr(img, &tmp.bits_per_pixel, &tmp.line_length, &tmp.endian);
	i = xyr[0] - xyr[2];
	while (i < xyr[0] + xyr[2])
	{
		j = xyr[1] - xyr[2];
		while (j < xyr[1] + xyr[2])
		{
			color = get_color_texture(&tmp, xyr, i, j);
			my_mlx_pixel_put(data->img, i, j, color);
			j++;
		}
		i++;
	}
	mlx_destroy_image(data->mlx, img);
}
