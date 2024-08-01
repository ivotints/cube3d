/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_paint_checkered_pattern.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:42:59 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/01 22:16:29 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	img_paint_checkered_pattern(t_img_data *data, int color1, int color2, int side)
{
	int	i;
	int	j;

	j = 0;
	while (j < S_HEIGHT)
	{
		i = 0;
		while (i < S_WIDTH)
		{
			if (i % (2 * side) < side && j % (2 * side) < side)
				img_paint_square(data, color1, i, j, side);
			else if (i % (2 * side) >= side && j % (2 * side) >= side)
				img_paint_square(data, color1, i, j, side);
			else
				img_paint_square(data, color2, i, j, side);
			i += side;
		}
		j += side;
	}
}
