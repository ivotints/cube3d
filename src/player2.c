/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:17:34 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/18 14:58:16 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	collide_x(t_all_data *data)
{
	int	side;

	side = floor(data->player.pos_x + data->player.motion_x);
	if (get_map_value(&data->map, side, floor(data->player.pos_y)) != MAP_BLOCK)
		data->player.pos_x += data->player.motion_x;
	else
		data->player.motion_x = 0;
}

void	collide_y(t_all_data *data)
{
	int	side;

	side = floor(data->player.pos_y + data->player.motion_y);
	if (get_map_value(&data->map, floor(data->player.pos_x), side) != MAP_BLOCK)
		data->player.pos_y += data->player.motion_y;
	else
		data->player.motion_y = 0;
}

void	update_player_condition(t_all_data *data)
{
	double		cs;
	double		sn;
	t_player	*player;

	player = &(data->player);
	cs = cos(player->view_dir);
	sn = sin(player->view_dir);
	player->motion_x += player->move_x * cs - player->move_y * sn;
	player->motion_y += player->move_y * cs + player->move_x * sn;
	update_view_dir(player, &data->keys);
	collide_y(data);
	collide_x(data);
	data->player.render_x = data->player.pos_x;
	data->player.render_y = data->player.pos_y;
	data->player.view_dir += data->player.motion_view_dir;
}
