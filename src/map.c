/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:12:39 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/18 14:56:55 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	get_map_size(t_line *start, int *x, int *y)
{
	*x = 0;
	*y = 0;
	while (start)
	{
		(*y)++;
		*x = fmax(*x, start->size);
		start = start->next;
	}
}

t_map	make_empty(int x, int y)
{
	t_map	map;
	int		i;

	map.map = malloc(x * y * sizeof(char));
	if (!map.map)
		return (map);
	i = 0;
	while (i < x * y)
		map.map[i++] = MAP_EMPTY;
	map.x = x;
	map.y = y;
	return (map);
}

int	set_map(t_all_data *data, char c, int x, int y)
{
	char	val;

	if (c == '1')
		val = MAP_BLOCK;
	else if (c == ' ')
		val = MAP_EMPTY;
	else if (c == '0' || set_player(data, c, x, y))
		val = MAP_AIR;
	else
		return (FAILURE);
	data->map.map[y * data->map.x + x] = val;
	return (SUCCESS);
}

int	map_flood_fill(t_map *map)
{
	int		x;
	int		y;
	char	val;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			val = get_map_value(map, x, y);
			if (val == MAP_AIR)
			{
				if (get_map_value(map, x + 1, y) == MAP_EMPTY
					|| get_map_value(map, x - 1, y) == MAP_EMPTY
					|| get_map_value(map, x, y + 1) == MAP_EMPTY
					|| get_map_value(map, x, y - 1) == MAP_EMPTY)
					return (FAILURE);
			}
			x++;
		}
		y++;
	}
	return (SUCCESS);
}

void	load_map(t_all_data *data, t_line *list)
{
	int	x;
	int	y;

	y = 0;
	while (list)
	{
		x = 0;
		while (x < list->size)
		{
			if (!set_map(data, list->line[x], x, y))
				error_msg("Unknown symbol in the *.cub file.",
					&list->line[x], data);
			x++;
		}
		y++;
		list = list->next;
	}
	if (!map_flood_fill(&data->map))
		error_msg("Map is not closed.", NULL, data);
}
