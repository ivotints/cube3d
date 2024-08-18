/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:22:08 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/18 15:11:06 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_vec	get_collide_pos(t_trace tr)
{
	t_vec	pos;

	if (tr.ray.ln_cos > tr.ray.ln_sin)
	{
		pos.x = floor(tr.ref_x + tr.ray.st_sin_x);
		pos.y = floor(tr.ref_y + tr.ray.st_sin_y + tr.rot.sin / 2);
	}
	else
	{
		pos.x = floor(tr.ref_x + tr.ray.st_cos_x + tr.rot.cos / 2);
		pos.y = floor(tr.ref_y + tr.ray.st_cos_y);
	}
	return (pos);
}

char	get_side(t_trace trace)
{
	if (trace.ray.ln_cos > trace.ray.ln_sin)
	{
		if (trace.rot.sin > 0)
			return ('W');
		return ('E');
	}
	if (trace.rot.cos > 0)
		return ('N');
	return ('S');
}

t_img_data	*get_texture(t_all_data *data, char side)
{
	if (side == 'E')
		return (&(data->textures.no));
	if (side == 'W')
		return (&(data->textures.so));
	if (side == 'N')
		return (&(data->textures.we));
	return (&(data->textures.ea));
}

//Return position of the ray in the texture from 0 to 0.99
double	tex_offset(t_trace trace)
{
	double	offset;

	if (trace.ray.ln_cos < trace.ray.ln_sin)
	{
		offset = trace.ref_x + trace.ref_y + trace.ray.st_cos_x
			+ trace.ray.st_cos_y;
		offset -= (int)offset;
		if (trace.rot.cos < 0)
			offset = 1 - offset;
	}
	else
	{
		offset = trace.ref_x + trace.ref_y + trace.ray.st_sin_x
			+ trace.ray.st_sin_y;
		offset -= (int)offset;
		if (trace.rot.sin > 0)
			offset = 1 - offset;
	}
	return (offset);
}

void	setup_line(t_all_data *data, t_trace *tr)
{
	tr->side = get_side(*tr);
	tr->len = fmin(tr->ray.ln_cos, tr->ray.ln_sin);
	data->depth[tr->line.x] = fmin(tr->len, data->depth[tr->line.x]);
	tr->line.height = S_HEIGHT / (tr->len * cos(tr->newa));
	tr->line.y = (S_HEIGHT - tr->line.height) / 2;
	tr->line.img = get_texture(data, tr->side);
	tr->offset = tex_offset(*tr);
}
