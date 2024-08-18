/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:20:25 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/18 15:13:16 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	set_null(t_all_data *data)
{
	data->textures.no.img = NULL;
	data->textures.so.img = NULL;
	data->textures.ea.img = NULL;
	data->textures.we.img = NULL;
	data->img.img = NULL;
	data->win = NULL;
	data->mlx = NULL;
	data->map.map = NULL;
	data->list = NULL;
	data->depth = NULL;
	data->mlx = NULL;
	data->keys.w = FALSE;
	data->keys.a = FALSE;
	data->keys.s = FALSE;
	data->keys.d = FALSE;
	data->keys.l_rot = FALSE;
	data->keys.r_rot = FALSE;
}

void	init_data(t_all_data *data, int ac, char **av)
{
	if (ac < 2)
		error_msg(ERRTOOLOW, NULL, NULL);
	if (ac > 2)
		error_msg(ERRTOOHIGH, NULL, NULL);
	check_file(av[1]);
	data->mlx = mlx_init();
	load_data(data, av[1]);
	check_data(data);
	data->win = mlx_new_window(data->mlx, S_WIDTH, S_HEIGHT, PROGRAM_NAME);
	data->img.img = mlx_new_image(data->mlx, S_WIDTH, S_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	data->img.h = S_HEIGHT;
	data->img.w = S_WIDTH;
}
