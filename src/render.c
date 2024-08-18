/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:18:48 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/18 14:55:19 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	setup_render(t_all_data *data)
{
	data->fov = (double)S_HEIGHT / (double)S_WIDTH;
	data->depth = malloc(sizeof(double) * S_WIDTH);
	if (!data->depth)
		error_msg("Malloc error. setup_render.", NULL, data);
}

int	render_next_frame(t_all_data *data)
{
	update_move_direction(data);
	update_player_condition(data);
	img_paint_floor_ceiling(data);
	ray_cast(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}
