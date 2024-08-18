/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:18:07 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/18 14:18:31 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	get_map_value(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x > map->x || y > map->y)
		return (MAP_EMPTY);
	return (map->map[y * map->x + x]);
}
