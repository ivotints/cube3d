/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_paint_floor_ceiling.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:14:39 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/15 10:23:13 by ivotints         ###   ########.fr       */
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
	img_paint_rectangle(&(data->img), coordinates, data->textures.C);
	coordinates[0] = 0;
	coordinates[1] = S_HEIGHT / 2;
	coordinates[2] = S_WIDTH;
	coordinates[3] = S_HEIGHT;
	img_paint_rectangle(&(data->img), coordinates, data->textures.F);
}
