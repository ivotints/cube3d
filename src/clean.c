/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:24:59 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/18 15:10:03 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	destroy_img(t_all_data *data, t_img_data *img)
{
	if (img->img)
	{
		mlx_destroy_image(data->mlx, img->img);
		img->img = NULL;
	}
}

void	clean_images(t_all_data *data)
{
	destroy_img(data, &(data->textures.no));
	destroy_img(data, &(data->textures.so));
	destroy_img(data, &(data->textures.ea));
	destroy_img(data, &(data->textures.we));
	destroy_img(data, &(data->img));
}

void	clean_data(t_all_data *data, int exit_code)
{
	if (data)
	{
		clean_images(data);
		if (data->win)
			mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->map.map);
		free_file(data->list);
		free(data->depth);
		free(data->mlx);
		exit(exit_code);
	}
}
