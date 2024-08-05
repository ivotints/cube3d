/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 01:47:44 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/05 01:52:31 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"


int	get_color_texture(t_img_data *texture, int *xyr, int i, int j)
{
	int	x;
	int	y;
	int	color;
	double x_ratio;
	double y_ratio;

	x_ratio = (double)(i - xyr[0] + xyr[2]) / (xyr[2] * 2);
	y_ratio = (double)(j - xyr[1] + xyr[2]) / (xyr[2] * 2);
	x = (texture->line_length / 4) * x_ratio;
	y = (texture->line_length / 4) * y_ratio;
	color = img_get_color(texture, x, y);
	return (color);
}
