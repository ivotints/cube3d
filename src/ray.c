/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:21:28 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/18 15:01:40 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	get_pixel(t_img_data *img, int x, int y)
{
	return (*(int *)(img->addr + (y * img->line_length + x
			* (img->bits_per_pixel / 8))));
}

void	set_img_strip(t_img_data *img, t_shape shape, double offset)
{
	t_vec		v;
	int			t;
	double		o;
	double		cur;
	char		*dst;

	v.y = fmax(0, shape.y);
	v.x = (shape.img->w - 1) * offset;
	o = shape.img->h / (double)shape.height;
	cur = o * (v.y - shape.y);
	dst = img->addr + (v.y * img->line_length
			+ shape.x * (img->bits_per_pixel / 8));
	while (v.y < shape.y + shape.height && v.y < S_HEIGHT)
	{
		t = get_pixel(shape.img, v.x, (int)cur);
		*(unsigned int *)dst = t;
		dst += img->line_length;
		cur += o;
		v.y++;
	}
}

void	cast_forward(t_ray *ray, t_ray step)
{
	if (ray->ln_cos < ray->ln_sin)
	{
		ray->st_cos_x += step.st_cos_x;
		ray->st_cos_y += step.st_cos_y;
		ray->ln_cos += step.ln_cos;
	}
	else
	{
		ray->st_sin_x += step.st_sin_x;
		ray->st_sin_y += step.st_sin_y;
		ray->ln_sin += step.ln_sin;
	}
}

void	do_ray(t_all_data *data, t_trace *tr)
{
	tr->pos = get_collide_pos(*tr);
	if (get_map_value(&data->map, tr->pos.x, tr->pos.y) == MAP_BLOCK)
	{
		setup_line(data, tr);
		set_img_strip(&data->img, tr->line, tr->offset);
		tr->i = RENDER_DISTANCE;
		return ;
	}
	cast_forward(&tr->ray, tr->step);
	tr->i++;
}

void	ray_cast(t_all_data *data)
{
	t_trace	trace;

	trace.line.width = 1;
	trace.line.x = -1;
	while (++trace.line.x < S_WIDTH)
	{
		data->depth[trace.line.x] = 999;
		trace.newa = atan2((trace.line.x / (double)S_WIDTH) - 0.5, data->fov);
		trace.rot = make_rot(data->player.view_dir + trace.newa);
		trace.ref_x = data->player.render_x;
		trace.ref_y = data->player.render_y;
		trace.ray = get_init_ray(&trace.rot, trace.ref_x, trace.ref_y);
		trace.step = get_init_ray(&trace.rot, 0, 0);
		trace.i = 0;
		while (trace.i < RENDER_DISTANCE)
			do_ray(data, &trace);
	}
}
