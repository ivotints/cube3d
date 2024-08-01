/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_paint_floor_ceiling.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:14:39 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/01 22:16:44 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	img_paint_floor_ceiling(t_all_data *data)
{
	int	coordinates[4];

	coordinates[0] = 0;
	coordinates[1] = 0;
	coordinates[2] = S_WIDTH;
	coordinates[3] = S_HEIGHT / 2;
	img_paint_rectangle(data, coordinates, data->ceiling_color);
	coordinates[0] = 0;
	coordinates[1] = S_HEIGHT / 2;
	coordinates[2] = S_WIDTH;
	coordinates[3] = S_HEIGHT;
	img_paint_rectangle(data, coordinates, data->floor_color);
}
