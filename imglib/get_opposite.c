/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opposite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:16:05 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/01 22:16:10 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	get_opposite(int color)
{
	unsigned char	RGB[3];

	RGB[0] = get_separate_trgb(color, 'r');
	RGB[1] = get_separate_trgb(color, 'g');
	RGB[2] = get_separate_trgb(color, 'b');
	RGB[0] = 0xFF - RGB[0];
	RGB[1] = 0xFF - RGB[1];
	RGB[2] = 0xFF - RGB[2];
	return (create_trgb(0, RGB[0], RGB[1], RGB[2]));
}
