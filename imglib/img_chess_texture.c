/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_chess_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:43:58 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/01 22:16:19 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_img_data	*img_chess_texture(void *mlx_ptr, int col_1, int col_2, int side)
{
	t_img_data	*img;

	img = malloc(sizeof(t_img_data));
	img->img = mlx_new_image(mlx_ptr, S_WIDTH, S_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
								&img->endian);
	img_paint_checkered_pattern(img, col_1, col_2, side);
	return (img);
}
