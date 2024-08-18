/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:11:00 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/18 15:00:04 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	read_file(char *file, t_line **start)
{
	int		fd;
	int		size;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		size = ft_strlen(line);
		if (line[size - 1] == '\n')
			line[size-- - 1] = 0;
		if (is_empty(line))
			free(line);
		else
			add_line(start, line, size);
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
