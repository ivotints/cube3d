/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:58:15 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/11 03:59:38 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/* //free array of strings
void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	tab = NULL;
	return ;
}

//__O_DIRECTORY can open only directory. If it is a file, it will return -1
void	check_extension(char *path)
{
	size_t	len;
	size_t	len_ext;
	int		fd;

	len = ft_strlen(path);
	len_ext = ft_strlen(MAP_EXTENSION);
	if (len < len_ext)
		error_msg(ERR_TOO_SHORT_NAME, NULL);
	if (ft_strcmp(path + len - len_ext, MAP_EXTENSION))
		error_msg(ERR_EXTENSION, NULL);
	fd = open(path, __O_DIRECTORY);
	if (fd != -1)
	{
		close (fd);
		error_msg(ERR_IS_DIR, NULL);
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_msg(ERR_FAIL_TO_OPEN_FILE, NULL);
	close (fd);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		check_extension(av[1]);


		// create_map(av[1], &data);
		// init_map(&data);
		// check_map(&data);
		// init_player(&data);
		// init_window(&data);
		// init_images(&data);
		// render(&data);
		// loop_images(data);
		// destroy_images(data);
		// free(data.mlx);
		// if (data.map.map)
		// 	ft_free(data.map.map);
	}
	else if (ac == 1)
		error_msg(ERRTOOLOW, NULL);
	else
		error_msg(ERRTOOHIGH, NULL);
	return (0);
}
 */

char	worldMap[24][24] =
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};



int	handle_destroy(t_all_data *data)
{
	mlx_destroy_image(data->mlx, data->img->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
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

void	normalize(double *x, double *y, double scale)
{
	double	hypotenuse;

	hypotenuse = sqrt(pow(*x, 2) + pow(*y, 2));
	if (!hypotenuse)
		return ;
	*x /= hypotenuse;
	*y /= hypotenuse;
	*x *= scale;
	*y *= scale;
}

void	update_move_direction(t_all_data *data)
{
	t_keys		*keys;
	t_player	*player;

	keys = &(data->keys);
	player = &(data->player);
	player->move_y = 0;
	if (keys->W)
		player->move_y += 1;
	if (keys->S)
		player->move_y -= 1;
	player->move_x = 0;
	if (keys->D)
		player->move_x += 1;
	if (keys->A)
		player->move_x -= 1;
	if (player->move_y > 0)
		normalize(&player->move_x, &player->move_y, 0.0085);
	else
		normalize(&player->move_x, &player->move_y, 0.0045);
}



double	current_time()
{
	struct timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);
	return (ts.tv_sec + (double)ts.tv_nsec / 1000000000.0);
}

void	vertLine(int x, t_all_data *data)
{
	while (data->drawStart <= data->drawEnd)
	{
		my_mlx_pixel_put(data->img, x, data->drawStart, data->color);
		data->drawStart++;
	}
}

void	calc_ray_position(t_all_data *data)
{
	int	x;

	x = 0;
	while (x < S_WIDTH)
	{
		data->cameraX = 2 * x / (double)S_WIDTH - 1;
		data->rayDirX = data->dirX + data->planeX * data->cameraX;
		data->rayDirY = data->dirY + data->planeY * data->cameraX;
		data->mapX = (int)data->posX;
		data->mapY = (int)data->posY;
		data->deltaDistX = 1e30;
		if (data->rayDirX != 0)
			data->deltaDistX = fabs(1 / data->rayDirX);
		data->deltaDistY = 1e30;
		if (data->rayDirY != 0)
			data->deltaDistY = fabs(1 / data->rayDirY);
		data->hit = 0;
		if (data->rayDirX < 0)
		{
			data->stepX = -1;
			data->sideDistX = (data->posX - data->mapX) * data->deltaDistX;
		}
		else
		{
			data->stepX = 1;
			data->sideDistX = (data->mapX + 1.0 - data->posX) * data->deltaDistX;
		}
		if (data->rayDirY < 0)
		{
			data->stepY = -1;
			data->sideDistY = (data->posY - data->mapY) * data->deltaDistY;
		}
		else
		{
			data->stepY = 1;
			data->sideDistY = (data->mapY + 1.0 - data->posY) * data->deltaDistY;
		}
		data->hit = 0;
		while (data->hit == 0)
		{
			if (data->sideDistX < data->sideDistY)
			{
				data->sideDistX += data->deltaDistX;
				data->mapX += data->stepX;
				data->side = 0;
			}
			else
			{
				data->sideDistY += data->deltaDistY;
				data->mapY += data->stepY;
				data->side = 1;
			}
			if (worldMap[data->mapX][data->mapY] > 0)
				data->hit = 1;
		}
		if (data->side == 0)
			data->perpWallDist = (data->sideDistX - data->deltaDistX);
		else
			data->perpWallDist = (data->sideDistY - data->deltaDistY);
		data->lineHeight = (int)(S_HEIGHT / data->perpWallDist);
		data->drawStart = S_HEIGHT / 2 - data->lineHeight / 2;
		if (data->drawStart < 0)
			data->drawStart = 0;
		data->drawEnd = S_HEIGHT / 2 + data->lineHeight / 2;
		if (data->drawEnd >= S_HEIGHT)
			data->drawEnd = S_HEIGHT - 1;
		data->color = create_trgb(0, 100, 0, 0);
		if (data->side == 1)
			data->color /= 2;
		vertLine(x, data);
		data->oldTime = data->time;
		//data->time = current_time();
		//data->frameTime = (data->time - data->oldTime);
		data->frameTime = 0.000003f;
		data->moveSpeed = data->frameTime * 5000.0;
		data->rotSpeed = data->frameTime * 3000.0;
		x++;
	}
}

void	update_view_dir(t_player *player, t_keys *keys)
{
	if (keys->L_rot && !keys->R_rot)
		player->motion_view_dir -= 0.013;
	else if (!keys->L_rot && keys->R_rot)
		player->motion_view_dir += 0.013;
	else
		player->motion_view_dir *= 0.9;
	player->motion_x *= 0.9;
	player->motion_y *= 0.9;
	player->motion_view_dir *= 0.9;

}

void	collide_y(t_all_data *data)
{
	int	side;
	side = floor()
}

void	update_player_condition(t_all_data *data)
{
	double	cs;
	double	sn;
	t_player	*player;

	player = &(data->player);
	cs = cos(player->view_dir);
	sn = sin(player->view_dir);
	player->motion_y += player->move_y * cs - player->move_x * sn;
	player->motion_x += player->move_x * cs + player->move_y * sn;
	update_view_dir(player, &data->keys);
	collide_y(data);



}

int	render_next_frame(t_all_data *data)
{
	update_move_direction(data);
	update_player_condition(data);
	img_paint_floor_ceiling(data);
	calc_ray_position(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (0);
}

void	error_msg(char *error1, char *error2, t_all_data *data)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(error1, 2);
	ft_putstr_fd(" ", 2);
	ft_putstr_fd(error2, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd(RESET, 2);
	//data
	exit(1);
}

//__O_DIRECTORY can open only directory. If it is a file, it will return -1
void	check_file(char *path)
{
	size_t	len;
	size_t	len_ext;
	int		fd;

	len = ft_strlen(path);
	len_ext = ft_strlen(MAP_EXTENSION);
	if (len < len_ext)
		error_msg(ERR_TOO_SHORT_NAME, path, NULL);
	if (ft_strcmp(path + len - len_ext, MAP_EXTENSION))
		error_msg(ERR_EXTENSION, path, NULL);
	fd = open(path, __O_DIRECTORY);
	if (fd != -1)
	{
		close (fd);
		error_msg(ERR_IS_DIR, path, NULL);
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_msg(ERR_FAIL_TO_OPEN_FILE, path, NULL);
	close (fd);
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
			break;
		}
		temp = temp->next;
	}
}

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

int	is_empty(char *str)
{
	if (!str)
		return (1);
	while (*str)
	{
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}

void	trim_from_end(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (i >= 0 && str[i] == c)
		str[i--] = '\0';
}

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

t_img_data load_image(void *mlx, char *path)
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

void	set_color(int *col, t_all_data *data, char *RGB)
{
	char	**srgb;
	int		checkint;
	char	*check;
	int		i;

	if (*col != 0x12345678)
		error_msg("Duplicate color.", RGB, data);
	srgb = ft_split(RGB, ',');
	i = 0;
	while (srgb[i])
	{
		checkint = ft_atoi(srgb[i]);
		if (checkint > 255 || checkint < 0)
			error_msg("Range is from 0 to 255.", RGB, data);
		check = ft_itoa(checkint);
		if (ft_strcmp(check, srgb[i]) != 0)
			error_msg("Other chars in color set.", RGB, data);
		i++;
	}
	if (i != 3)
		error_msg("3 numbers required.", RGB, data);
	*col = create_trgb(0, ft_atoi(srgb[0]), ft_atoi(srgb[1]), ft_atoi(srgb[2]));
}

int	read_identifier(t_all_data *data, char *line)
{
	char	*str;

	if (is_identifier("NO", line, &str))
		set_texture(&data->textures.NO, data, str);
	else if (is_identifier("SO", line, &str))
		set_texture(&data->textures.SO, data, str);
	else if (is_identifier("WE", line, &str))
		set_texture(&data->textures.WE, data, str);
	else if (is_identifier("EA", line, &str))
		set_texture(&data->textures.EA, data, str);
	else if (is_identifier("F", line, &str))
		set_color(&data->textures.F, data, str);
	else if (is_identifier("C", line, &str))
		set_color(&data->textures.C, data, str);
	else
		return (FAILURE);
	return (SUCCESS);
}

void	get_map_size(t_line *start, int *x, int *y)
{
	*x = 0;
	*y = 0;
	while (start)
	{
		*y++;
		*x = fmax(*x, start->size); // do we need size int the structure? or better do ft_strlen nd remove it from the structure
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

void	load_data(t_all_data *data, char *file)
{
	t_line		*list;
	int			x;
	int			y;

	read_file(file, &list);
	data->textures.NO.img = NULL;
	data->textures.SO.img = NULL;
	data->textures.WE.img = NULL;
	data->textures.EA.img = NULL;
	data->textures.C = 0x12345678;
	data->textures.F = 0x12345678;
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
	return (load_map(data, list));
}

void	init_data(t_all_data *data, int ac, char **av)
{
	if (ac < 2)
		error_msg(ERRTOOLOW, NULL, NULL);
	if (ac > 2)
		error_msg(ERRTOOHIGH, NULL, NULL);
	check_file(av[1]);
	load_data(data, av[1]);


	data->ceiling_color = create_trgb(0, 51, 153, 255);
	data->floor_color = create_trgb(0, 64, 64, 64);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, S_WIDTH, S_HEIGHT, PROGRAM_NAME);
	img->img = mlx_new_image(data->mlx, S_WIDTH, S_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	data->posX = 22;
	data->posY = 12;
	data->dirX = -1;
	data->dirY = 0;
	data->planeX = 0;
	data->planeY = 0.66;
	data->time = 0;
	data->keys.W = FALSE;
	data->keys.A = FALSE;
	data->keys.S = FALSE;
	data->keys.D = FALSE;
	data->keys.L_rot = FALSE;
	data->keys.R_rot = FALSE;
}

int	handle_keypress(int	key, t_all_data *data)
{
	if (key == XK_Escape)
		handle_destroy(data);
	if (key == XK_W || key == XK_w)
		data->keys.W = TRUE;
	if (key == XK_A || key == XK_a)
		data->keys.A = TRUE;
	if (key == XK_S || key == XK_s)
		data->keys.S = TRUE;
	if (key == XK_D || key == XK_d)
		data->keys.D = TRUE;
	if (key == XK_Left)
		data->keys.L_rot = TRUE;
	if (key == XK_Right)
		data->keys.R_rot = TRUE;
	return (0);
}

int	handle_keyrelease(int key, t_all_data *data)
{
	if (key == XK_W || key == XK_w)
		data->keys.W = FALSE;
	else if (key == XK_A || key == XK_a)
		data->keys.A = FALSE;
	else if (key == XK_S || key == XK_s)
		data->keys.S = FALSE;
	else if (key == XK_D || key == XK_d)
		data->keys.D = FALSE;
	else if (key == XK_Left)
		data->keys.L_rot = FALSE;
	else if (key == XK_Right)
		data->keys.R_rot = FALSE;
	return (0);
}

int	main(int ac, char **av)
{
	t_all_data	data;

	init_data(&data, ac, av);
	mlx_hook(data.win, 17, 0, handle_destroy, &data);
	mlx_hook(data.win, ON_KEYDOWN, KeyPressMask, handle_keypress, &data);
	mlx_hook(data.win, ON_KEYUP, KeyReleaseMask, handle_keyrelease, &data);
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_loop(data.mlx);
	return (0);
}
