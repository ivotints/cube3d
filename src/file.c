/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:11:00 by ivotints          #+#    #+#             */
/*   Updated: 2024/09/12 16:13:52 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	read_file(char *file, t_line **start)
{
	int		fd;
	int		size[2];
	char	*line;

	size[1] = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		size[0] = ft_strlen(line);
		if (line[size[0] - 1] == '\n')
			line[size[0]-- - 1] = 0;
		if (size[1] == 0 && is_empty(line))
			free(line);
		else
		{
			add_line(start, line, size[0]);
			size[0] = 0;
			while (size[1] == 0 && line[size[0]] == ' ')
				size[0]++;
			if (size[1] == 0 && line[size[0]] == '1')
				size[1] = 1;
		}
		line = get_next_line(fd);
	}
}

void	add_line(t_line **list, char *str, int size)
{
	t_line	*new;
	t_line	*temp;

	new = malloc(sizeof(t_line));
	new->next = NULL;
	new->size = size;
	new->line = str;
	temp = *list;
	if (!temp)
		*list = new;
	while (temp)
	{
		if (!temp->next)
		{
			temp->next = new;
			break ;
		}
		temp = temp->next;
	}
}
