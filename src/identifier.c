/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:26:07 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/18 15:10:23 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	is_identifier(char *s1, char *s2, char **result)
{
	if (*s2 == ' ')
		s2++;
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (FALSE);
		s2++;
		s1++;
	}
	if (*s1 == 0 && *s2 == ' ')
	{
		while (*s2 == ' ')
			s2++;
		trim_from_end(s2, ' ');
		*result = s2;
		return (TRUE);
	}
	return (FALSE);
}

int	read_identifier(t_all_data *data, char *line)
{
	char	*str;

	if (is_identifier("NO", line, &str))
		set_texture(&data->textures.no, data, str);
	else if (is_identifier("SO", line, &str))
		set_texture(&data->textures.so, data, str);
	else if (is_identifier("WE", line, &str))
		set_texture(&data->textures.we, data, str);
	else if (is_identifier("EA", line, &str))
		set_texture(&data->textures.ea, data, str);
	else if (is_identifier("F", line, &str))
		set_color(&data->textures.f, data, str);
	else if (is_identifier("C", line, &str))
		set_color(&data->textures.c, data, str);
	else
		return (FAILURE);
	return (SUCCESS);
}
