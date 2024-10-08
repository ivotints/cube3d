/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:58:15 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/18 15:32:03 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	main(int ac, char **av)
{
	t_all_data	data;

	set_null(&data);
	init_data(&data, ac, av);
	setup_render(&data);
	mlx_hook(data.win, ON_DESTROY, 0, handle_destroy, &data);
	mlx_hook(data.win, ON_KEYDOWN, (1L << 0), handle_keypress, &data);
	mlx_hook(data.win, ON_KEYUP, (1L << 1), handle_keyrelease, &data);
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_loop(data.mlx);
	return (0);
}
