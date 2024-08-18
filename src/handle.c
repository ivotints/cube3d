/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:24:11 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/18 15:13:01 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	handle_destroy(t_all_data *data)
{
	clean_data(data, 0);
	return (0);
}

int	is_movement_key(int key)
{
	if (key == XK_W || key == XK_w)
		return (TRUE);
	if (key == XK_A || key == XK_a)
		return (TRUE);
	if (key == XK_S || key == XK_s)
		return (TRUE);
	if (key == XK_D || key == XK_d)
		return (TRUE);
	return (FALSE);
}

int	handle_keypress(int key, t_all_data *data)
{
	if (key == XK_W || key == XK_w)
		data->keys.w = TRUE;
	else if (key == XK_A || key == XK_a)
		data->keys.a = TRUE;
	else if (key == XK_S || key == XK_s)
		data->keys.s = TRUE;
	else if (key == XK_D || key == XK_d)
		data->keys.d = TRUE;
	else if (key == XK_Left)
		data->keys.l_rot = TRUE;
	else if (key == XK_Right)
		data->keys.r_rot = TRUE;
	else if (key == XK_Escape)
		handle_destroy(data);
	return (0);
}

int	handle_keyrelease(int key, t_all_data *data)
{
	if (key == XK_W || key == XK_w)
		data->keys.w = FALSE;
	else if (key == XK_A || key == XK_a)
		data->keys.a = FALSE;
	else if (key == XK_S || key == XK_s)
		data->keys.s = FALSE;
	else if (key == XK_D || key == XK_d)
		data->keys.d = FALSE;
	else if (key == XK_Left)
		data->keys.l_rot = FALSE;
	else if (key == XK_Right)
		data->keys.r_rot = FALSE;
	return (0);
}
