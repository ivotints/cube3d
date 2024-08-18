/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:23:14 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/18 15:25:15 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	update_view_dir(t_player *player, t_keys *keys)
{
	if (keys->l_rot && !keys->r_rot)
		player->motion_view_dir -= 0.013;
	else if (!keys->l_rot && keys->r_rot)
		player->motion_view_dir += 0.013;
	else
		player->motion_view_dir *= 0.9;
	player->motion_x *= 0.9;
	player->motion_y *= 0.9;
	player->motion_view_dir *= 0.9;
}

t_rot	make_rot(double angle)
{
	t_rot	rot;

	rot.angle = angle;
	rot.cos = cos(rot.angle);
	rot.sin = sin(rot.angle);
	return (rot);
}

t_ray	get_init_ray(t_rot *rot, double x, double y)
{
	t_ray	ray;

	if (rot->cos > 0)
		ray.st_cos_x = floor(x + 1) - x;
	else
		ray.st_cos_x = ceil(x - 1) - x;
	ray.st_cos_y = ray.st_cos_x * (rot->sin / rot->cos);
	ray.ln_cos = sqrt(pow(ray.st_cos_x, 2) + pow(ray.st_cos_y, 2));
	if (rot->sin > 0)
		ray.st_sin_y = floor(y + 1) - y;
	else
		ray.st_sin_y = ceil(y - 1) - y;
	ray.st_sin_x = ray.st_sin_y * (rot->cos / rot->sin);
	ray.ln_sin = sqrt(pow(ray.st_sin_x, 2) + pow(ray.st_sin_y, 2));
	return (ray);
}
