/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_separate_trgb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:46:38 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/01 22:16:16 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

//Returns the requested value which can be t, r, g or b
unsigned char	get_separate_trgb(int trgb, char color)
{
	if (color == 't')
		return (((unsigned char *)&trgb)[3]);
	if (color == 'r')
		return (((unsigned char *)&trgb)[2]);
	if (color == 'g')
		return (((unsigned char *)&trgb)[1]);
	if (color == 'b')
		return (((unsigned char *)&trgb)[0]);
	write(2, "Wrong input in get_separate_trgb()\n", 36);
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
