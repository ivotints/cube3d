/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_shade.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:47:21 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/01 22:15:55 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	add_shade(double dim, int color)
{
	unsigned char	RGB[3];

	RGB[0] = get_separate_trgb(color, 'r');
	RGB[1] = get_separate_trgb(color, 'g');
	RGB[2] = get_separate_trgb(color, 'b');
	RGB[0] = RGB[0] - (RGB[0]) * dim;
	RGB[1] = RGB[1] - (RGB[1]) * dim;
	RGB[2] = RGB[2] - (RGB[2]) * dim;
	return (create_trgb(0, RGB[0], RGB[1], RGB[2]));
}
