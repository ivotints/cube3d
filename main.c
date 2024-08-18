/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:58:15 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/18 12:01:04 by ivotints         ###   ########.fr       */
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

void	destroy_img(t_all_data *data, t_img_data *img)
{
	if (img->img)
	{
		mlx_destroy_image(data->mlx, img->img);
		img->img = NULL;
	}
}

void	clean_images(t_all_data *data)
{
	destroy_img(data, &(data->textures.NO));
	destroy_img(data, &(data->textures.SO));
	destroy_img(data, &(data->textures.EA));
	destroy_img(data, &(data->textures.WE));
	destroy_img(data, &(data->img));
}

void	free_file(t_line *file)
{
	t_line *next;

	while (file)
	{
		next = file->next;
		if (file->line)
			free(file->line);
		free(file);
		file = next;
	}
}

void	free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	clean_data(t_all_data *data, int exit_code)
{
	if (data)
	{
		clean_images(data);
		if (data->win)
			mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->map.map);
		free_file(data->list);
		free(data->depth);
		free(data->mlx);
		exit(exit_code);
	}
}

int	handle_destroy(t_all_data *data)
{
	clean_data(data, 0);
	return (0);
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
	player->move_x = 0;
	if (keys->W)
		player->move_x += 1;
	if (keys->S)
		player->move_x -= 1;
	player->move_y = 0;
	if (keys->D)
		player->move_y += 1;
	if (keys->A)
		player->move_y -= 1;
	if (player->move_x > 0)
		normalize(&player->move_y, &player->move_x, 0.01);
	else
		normalize(&player->move_y, &player->move_x, 0.009);
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

char	get_map_value(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x > map->x || y > map->y)
		return (MAP_EMPTY);
	return (map->map[y * map->x + x]);
}

void	collide_x(t_all_data *data)
{
	int	side;
	side = floor(data->player.pos_x + data->player.motion_x);
	if (get_map_value(&data->map, side, floor(data->player.pos_y)) != MAP_BLOCK)
		data->player.pos_x += data->player.motion_x;
	else
		data->player.motion_x = 0;
}

void	collide_y(t_all_data *data)
{
	int	side;
	side = floor(data->player.pos_y + data->player.motion_y);
	if (get_map_value(&data->map, floor(data->player.pos_x), side) != MAP_BLOCK)
		data->player.pos_y += data->player.motion_y;
	else
		data->player.motion_y = 0;
}

void	update_render()
{

}

void	update_player_condition(t_all_data *data)
{
	double	cs;
	double	sn;
	t_player	*player;

	player = &(data->player);
	cs = cos(player->view_dir);
	sn = sin(player->view_dir);
	player->motion_x += player->move_x * cs - player->move_y * sn;
	player->motion_y += player->move_y * cs + player->move_x * sn;
	update_view_dir(player, &data->keys);
	collide_y(data);
	collide_x(data);
	data->player.render_x = data->player.pos_x;
	data->player.render_y = data->player.pos_y;
	data->player.view_dir += data->player.motion_view_dir;
}

t_rot	make_rot(double angle)
{
	t_rot	rot;

	rot.angle = angle;
	rot.cos = cos(rot.angle);
	rot.sin = sin(rot.angle);
	return (rot);
}

t_ray	get_init_ray(t_rot *rot, double x, double y)
{
	t_ray	ray;

	if (rot->cos > 0)
		ray.st_cos_x = floor(x + 1) - x;
	else
		ray.st_cos_x = ceil(x - 1) - x;
	ray.st_cos_y = ray.st_cos_x * (rot->sin / rot->cos);
	ray.ln_cos = sqrt(pow(ray.st_cos_x, 2) + pow(ray.st_cos_y, 2));
	if (rot->sin > 0)
		ray.st_sin_y = floor(y + 1) - y;
	else
		ray.st_sin_y = ceil(y - 1) - y;
	ray.st_sin_x = ray.st_sin_y * (rot->cos / rot->sin);
	ray.ln_sin =  sqrt(pow(ray.st_sin_x, 2) + pow(ray.st_sin_y, 2));
	return (ray);
}

t_vec	get_collide_pos(t_trace tr)
{
	t_vec	pos;

	if (tr.ray.ln_cos > tr.ray.ln_sin)
	{
		pos.x = floor(tr.ref_x + tr.ray.st_sin_x);
		pos.y = floor(tr.ref_y + tr.ray.st_sin_y + tr.rot.sin / 2);
	}
	else
	{
		pos.x = floor(tr.ref_x + tr.ray.st_cos_x + tr.rot.cos / 2);
		pos.y = floor(tr.ref_y + tr.ray.st_cos_y);
	}
	return (pos);
}

char	get_side(t_trace trace)
{
	if (trace.ray.ln_cos > trace.ray.ln_sin)
	{
		if (trace.rot.sin > 0)
			return ('W');
		return ('E');
	}
	if (trace.rot.cos > 0)
		return ('N');
	return ('S');
}

t_img_data	*get_texture(t_all_data *data, char side)
{
	if (side == 'E')
		return (&(data->textures.NO));
	if (side == 'W')
		return (&(data->textures.SO));
	if (side == 'N')
		return (&(data->textures.WE));
	return (&(data->textures.EA));
}


//Return position of the ray in the texture from 0 to 0.99
double	tex_offset(t_trace trace)
{
	double	offset;


	if (trace.ray.ln_cos < trace.ray.ln_sin)
	{
		offset = trace.ref_x + trace.ref_y + trace.ray.st_cos_x
			+ trace.ray.st_cos_y;
		offset -= (int)offset;
		if (trace.rot.cos < 0)
			offset = 1 - offset;
	}
	else
	{
		offset = trace.ref_x + trace.ref_y + trace.ray.st_sin_x
			+ trace.ray.st_sin_y;
		offset -= (int)offset;
		if (trace.rot.sin > 0)
			offset = 1 - offset;
	}
	return (offset);
}

void	setup_line(t_all_data *data, t_trace *tr)
{
	tr->side = get_side(*tr);
	tr->len = fmin(tr->ray.ln_cos, tr->ray.ln_sin);
	data->depth[tr->line.x] = fmin(tr->len, data->depth[tr->line.x]);
	tr->line.height = S_HEIGHT / (tr->len * cos(tr->newa));
	tr->line.y = (S_HEIGHT - tr->line.height) / 2;
	tr->line.img = get_texture(data, tr->side);
	tr->offset = tex_offset(*tr);
}

int	get_pixel(t_img_data *img, int x, int y)
{
	return (*(int *)(img->addr + (y * img->line_length + x
		* (img->bits_per_pixel / 8))));
}

void	set_img_strip(t_img_data *img, t_shape shape, double offset)
{
	t_vec		v;
	int			t;
	double		o;
	double		cur;
	char		*dst;

	v.y = fmax(0, shape.y);
	v.x = (shape.img->w - 1) * offset;
	o = shape.img->h / (double)shape.height;
	cur = o * (v.y - shape.y);
	dst = img->addr + (v.y * img->line_length +
		shape.x * (img->bits_per_pixel / 8));
	while (v.y < shape.y + shape.height && v.y < S_HEIGHT)
	{
		t = get_pixel(shape.img, v.x, (int)cur);
		*(unsigned int*)dst = t;
		dst += img->line_length;
		cur += o;
		v.y++;
	}
}

void	cast_forward(t_ray *ray, t_ray step)
{
	if (ray->ln_cos < ray->ln_sin)
	{
		ray->st_cos_x += step.st_cos_x;
		ray->st_cos_y += step.st_cos_y;
		ray->ln_cos += step.ln_cos;
	}
	else
	{
		ray->st_sin_x += step.st_sin_x;
		ray->st_sin_y += step.st_sin_y;
		ray->ln_sin += step.ln_sin;
	}
}

void	do_ray(t_all_data *data, t_trace *tr)
{
	tr->pos = get_collide_pos(*tr);
	if (get_map_value(&data->map, tr->pos.x, tr->pos.y) == MAP_BLOCK)
	{
		setup_line(data, tr);
		set_img_strip(&data->img, tr->line, tr->offset);
		tr->i = RENDER_DISTANCE;
		return ;
	}
	cast_forward(&tr->ray, tr->step);
	tr->i++;
}

void	ray_cast(t_all_data *data)
{
	t_trace	trace;

	trace.line.width = 1;
	trace.line.x = -1;
	while (++trace.line.x < S_WIDTH)
	{
		data->depth[trace.line.x] = 999;
		trace.newa = atan2((trace.line.x / (double)S_WIDTH) - 0.5, data->fov);
		trace.rot = make_rot(data->player.view_dir + trace.newa);
		trace.ref_x = data->player.render_x;
		trace.ref_y = data->player.render_y;
		trace.ray = get_init_ray(&trace.rot, trace.ref_x, trace.ref_y);
		trace.step = get_init_ray(&trace.rot, 0, 0);
		trace.i = 0;
		while (trace.i < RENDER_DISTANCE)
			do_ray(data, &trace);
	}
}

int	render_next_frame(t_all_data *data)
{
	update_move_direction(data);
	update_player_condition(data);
	img_paint_floor_ceiling(data);
	ray_cast(data);

	//calc_ray_position(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
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
	clean_data(data, 1);
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

	//printf("%s\n", path);
	img.img = mlx_xpm_file_to_image(mlx, path, &img.w, &img.h);
	//write(1, "123456789\n", 9);

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
	int		checkint;
	int		i;
	char	**srgb;
	char	*check;

	if (*col != 0x12345678)
		error_msg("Duplicate color.", RGB, data);
	srgb = ft_split(RGB, ',');
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
	if (i != 3)
	{
		free_arr(srgb);
		error_msg("3 RGB numbers required.", RGB, data);
	}
	*col = create_trgb(0, ft_atoi(srgb[0]), ft_atoi(srgb[1]), ft_atoi(srgb[2]));
	free_arr(srgb);
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
		(*y)++;
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

t_player	make_player(void)
{
	t_player	p;

	p.is_set = TRUE;
	p.pos_x = 0;
	p.pos_y = 0;
	p.view_dir = 0;
	p.motion_view_dir = 0;
	p.motion_x = 0;
	p.motion_y = 0;
	return (p);
}

int	set_player(t_all_data *data, char c, int x, int y)
{
	int	val;

	if (c == 'W')
		val = 0;
	else if (c == 'S')
		val = 1;
	else if (c == 'E')
		val = 2;
	else if (c == 'N')
		val = 3;
	else
		return (FAILURE);
	if (data->player.is_set == TRUE)
		error_msg("Detected multiple player in map.", NULL, data);
	data->player = make_player();
	data->player.pos_x = x + 0.5;
	data->player.pos_y = y + 0.5;
	data->player.view_dir = PI / 2 * val;
	return (SUCCESS);
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
	int	x;
	int	y;
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
				error_msg("Unknown symbol in the *.cub file.", &list->line[x], data);
			x++;
		}
		y++;
		list = list->next;
	}
	if (!map_flood_fill(&data->map))
		error_msg("Map is not closed.", NULL, data);
}

void	load_data(t_all_data *data, char *file)
{
	t_line		*list;
	int			x;
	int			y;

	list = NULL;
	read_file(file, &list);
	data->list = list;
	data->textures.NO.img = NULL;
	data->textures.SO.img = NULL;
	data->textures.WE.img = NULL;
	data->textures.EA.img = NULL;
	data->textures.C = 0x12345678;
	data->textures.F = 0x12345678;
	data->player.is_set = FALSE;
	while (list)
	{
		if (read_identifier(data, list->line) == FAILURE)
			break ;
		list = list->next;
	}
	get_map_size(list, &x, &y);
	//printf("%d, %d\n", x, y);
	if (x == 0)
		error_msg("Map is empty. ", NULL, data);
	data->map = make_empty(x, y);

	if (!data->map.map)
		error_msg("Failed to create map.", NULL, data);
	load_map(data, list);
}

void	check_data(t_all_data *data)
{
	if (S_HEIGHT < 1 || S_HEIGHT < 1)
		error_msg("Wrong resolution.", NULL, data);
	if (S_HEIGHT > 5000 || S_HEIGHT > 5000)
		error_msg("Wrong resolution. Too big.", NULL, data);
	if (data->textures.C == 0x12345678)
		error_msg("Ceiling color is not set.", NULL, data);
	if (data->textures.F == 0x12345678)
		error_msg("Floor color is not set.", NULL, data);
	if (data->player.is_set == FALSE)
		error_msg("No player in the map.", NULL, data);
	if (data->textures.EA.img == NULL)
		error_msg("EA texture is not set.", NULL, data);
	if (data->textures.WE.img == NULL)
		error_msg("WE texture is not set.", NULL, data);
	if (data->textures.NO.img == NULL)
		error_msg("NO texture is not set.", NULL, data);
	if (data->textures.SO.img == NULL)
		error_msg("SO texture is not set.", NULL, data);
}

void	init_data(t_all_data *data, int ac, char **av)
{
	if (ac < 2)
		error_msg(ERRTOOLOW, NULL, NULL);
	if (ac > 2)
		error_msg(ERRTOOHIGH, NULL, NULL);
	check_file(av[1]);
	data->mlx = mlx_init();
	load_data(data, av[1]);
	check_data(data);
	data->win = mlx_new_window(data->mlx, S_WIDTH, S_HEIGHT, PROGRAM_NAME);
	data->img.img = mlx_new_image(data->mlx, S_WIDTH, S_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	data->img.h = S_HEIGHT;
	data->img.w = S_WIDTH;
}

int	handle_keypress(int	key, t_all_data *data)
{
	if (key == XK_W || key == XK_w)
		data->keys.W = TRUE;
	else if (key == XK_A || key == XK_a)
		data->keys.A = TRUE;
	else if (key == XK_S || key == XK_s)
		data->keys.S = TRUE;
	else if (key == XK_D || key == XK_d)
		data->keys.D = TRUE;
	else if (key == XK_Left)
		data->keys.L_rot = TRUE;
	else if (key == XK_Right)
		data->keys.R_rot = TRUE;
	else if (key == XK_Escape)
		handle_destroy(data);
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

void	setup_render(t_all_data *data)
{
	data->fov = (double)S_HEIGHT / (double)S_WIDTH;
	data->depth = malloc(sizeof(double) * S_WIDTH);
	if (!data->depth)
		error_msg("Malloc error. setup_render.", NULL, data);
}

void	set_null(t_all_data *data)
{
	data->textures.NO.img = NULL;
	data->textures.SO.img = NULL;
	data->textures.EA.img = NULL;
	data->textures.WE.img = NULL;
	data->img.img = NULL;
	data->win = NULL;
	data->mlx = NULL;
	data->map.map = NULL;
	data->free.srgb = NULL;
	data->list = NULL;
	data->depth = NULL;
	data->mlx = NULL;
	data->keys.W = FALSE;
	data->keys.A = FALSE;
	data->keys.S = FALSE;
	data->keys.D = FALSE;
	data->keys.L_rot = FALSE;
	data->keys.R_rot = FALSE;
}

int	main(int ac, char **av)
{
	t_all_data	data;

	set_null(&data);
	init_data(&data, ac, av);
	setup_render(&data);
	mlx_hook(data.win, 17, 0, handle_destroy, &data);
	mlx_hook(data.win, ON_KEYDOWN, KeyPressMask, handle_keypress, &data);
	mlx_hook(data.win, ON_KEYUP, KeyReleaseMask, handle_keyrelease, &data);
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_loop(data.mlx);
	return (0);
}
