/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:26:57 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/18 15:09:46 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	check_data(t_all_data *data)
{
	if (S_HEIGHT < 1 || S_HEIGHT < 1)
		error_msg("Wrong resolution.", NULL, data);
	if (S_HEIGHT > 5000 || S_HEIGHT > 5000)
		error_msg("Wrong resolution. Too big.", NULL, data);
	if (data->textures.c == 0x12345678)
		error_msg("Ceiling color is not set.", NULL, data);
	if (data->textures.f == 0x12345678)
		error_msg("Floor color is not set.", NULL, data);
	if (data->player.is_set == FALSE)
		error_msg("No player in the map.", NULL, data);
	if (data->textures.ea.img == NULL)
		error_msg("EA texture is not set.", NULL, data);
	if (data->textures.we.img == NULL)
		error_msg("WE texture is not set.", NULL, data);
	if (data->textures.no.img == NULL)
		error_msg("NO texture is not set.", NULL, data);
	if (data->textures.so.img == NULL)
		error_msg("SO texture is not set.", NULL, data);
}
