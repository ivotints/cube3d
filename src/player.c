/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:15:47 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/18 15:13:31 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_player	make_player(void)
{
	t_player	p;

	p.is_set = TRUE;
	p.pos_x = 0;
	p.pos_y = 0;
	p.view_dir = 0;
	p.motion_view_dir = 0;
	p.motion_x = 0;
	p.motion_y = 0;
	return (p);
}

int	set_player(t_all_data *data, char c, int x, int y)
{
	int	val;

	if (c == 'W')
		val = 0;
	else if (c == 'S')
		val = 1;
	else if (c == 'E')
		val = 2;
	else if (c == 'N')
		val = 3;
	else
		return (FAILURE);
	if (data->player.is_set == TRUE)
		error_msg("Detected multiple player in map.", NULL, data);
	data->player = make_player();
	data->player.pos_x = x + 0.5;
	data->player.pos_y = y + 0.5;
	data->player.view_dir = PI / 2 * val;
	return (SUCCESS);
}

void	normalize(double *x, double *y, double scale)
{
	double	hypotenuse;

	hypotenuse = sqrt(pow(*x, 2) + pow(*y, 2));
	if (!hypotenuse)
		return ;
	*x /= hypotenuse;
	*y /= hypotenuse;
	*x *= scale;
	*y *= scale;
}

void	update_move_direction(t_all_data *data)
{
	t_keys		*keys;
	t_player	*player;

	keys = &(data->keys);
	player = &(data->player);
	player->move_x = 0;
	if (keys->w)
		player->move_x += 1;
	if (keys->s)
		player->move_x -= 1;
	player->move_y = 0;
	if (keys->d)
		player->move_y += 1;
	if (keys->a)
		player->move_y -= 1;
	if (player->move_x > 0)
		normalize(&player->move_y, &player->move_x, 0.01);
	else
		normalize(&player->move_y, &player->move_x, 0.009);
}
