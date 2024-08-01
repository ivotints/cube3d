/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_paint_hexagon.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:23:13 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/01 22:16:47 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	img_paint_hexagon(t_img_data *data, int color, double x, double y, double side)
{
	double	triangle_median;

	triangle_median = sqrt(pow(side, 2) - pow(side / 2, 2));
	img_paint_triangle(data, color, x, y, side);
	img_paint_triangle(data, color, x - side / 2, y - triangle_median, side);
	img_paint_triangle(data, color, x + side / 2, y - triangle_median, side);
	img_paint_rtriangle(data, color, x, y - triangle_median, side);
	img_paint_rtriangle(data, color, x + side / 2, y, side);
	img_paint_rtriangle(data, color, x - side / 2, y, side);
}
