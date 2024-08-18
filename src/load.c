/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:27:25 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/18 15:08:09 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_img_data	load_image(void *mlx, char *path)
{
	t_img_data	img;

	img.img = mlx_xpm_file_to_image(mlx, path, &img.w, &img.h);
	if (img.img)
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
				&img.line_length, &img.endian);
	return (img);
}

void	set_texture(t_img_data *img, t_all_data *data, char *path)
{
	if (img->img)
		error_msg("Duplicate texture.", path, data);
	*img = load_image(data->mlx, path);
	if (!img->img)
		error_msg("Failed to load texture", path, data);
}

int	set_color2(char **srgb, char *RGB, t_all_data *data)
{
	int		checkint;
	int		i;
	char	*check;

	i = 0;
	while (srgb[i])
	{
		checkint = ft_atoi(srgb[i]);
		if (checkint > 255 || checkint < 0)
		{
			free_arr(srgb);
			error_msg("Range is from 0 to 255.", RGB, data);
		}
		check = ft_itoa(checkint);
		if (ft_strcmp(check, srgb[i]) != 0)
		{
			free(check);
			free_arr(srgb);
			error_msg("Other chars in color set.", RGB, data);
		}
		free(check);
		i++;
	}
	return (i);
}

void	set_color(int *col, t_all_data *data, char *RGB)
{
	char	**srgb;

	if (*col != 0x12345678)
		error_msg("Duplicate color.", RGB, data);
	srgb = ft_split(RGB, ',');
	if (set_color2(srgb, RGB, data) != 3)
	{
		free_arr(srgb);
		error_msg("3 RGB numbers required.", RGB, data);
	}
	*col = create_trgb(0, ft_atoi(srgb[0]), ft_atoi(srgb[1]), ft_atoi(srgb[2]));
	free_arr(srgb);
}

void	load_data(t_all_data *data, char *file)
{
	t_line		*list;
	int			x;
	int			y;

	list = NULL;
	read_file(file, &list);
	data->list = list;
	data->textures.c = 0x12345678;
	data->textures.f = 0x12345678;
	data->player.is_set = FALSE;
	while (list)
	{
		if (read_identifier(data, list->line) == FAILURE)
			break ;
		list = list->next;
	}
	get_map_size(list, &x, &y);
	if (x == 0)
		error_msg("Map is empty. ", NULL, data);
	data->map = make_empty(x, y);
	if (!data->map.map)
		error_msg("Failed to create map.", NULL, data);
	load_map(data, list);
}
