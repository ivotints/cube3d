/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:58:15 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/05 19:26:35 by ivotints         ###   ########.fr       */
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

void	error_msg(char *error, t_data *data)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd(RESET, 2);
	// if (data && data->map.map)
	// 	ft_free(data->map.map);
	exit(1);
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

void	update_player_position(t_all_data *data)
{
	if (data->W)
	{
		if (worldMap[(int)(data->posX + data->dirX * data->moveSpeed)][(int)(data->posY)] == 0)
			data->posX += data->dirX * data->moveSpeed;
		if (worldMap[(int)(data->posX)][(int)(data->posY + data->dirY * data->moveSpeed)] == 0)
			data->posY += data->dirY * data->moveSpeed;
	}
	if (data->S)
	{
		if (worldMap[(int)(data->posX - data->dirX * data->moveSpeed)][(int)(data->posY)] == 0)
			data->posX -= data->dirX * data->moveSpeed;
		if (worldMap[(int)(data->posX)][(int)(data->posY - data->dirY * data->moveSpeed)] == 0)
			data->posY -= data->dirY * data->moveSpeed;
	}
	if (data->A)
	{
		if (worldMap[(int)(data->posX + data->dirX * data->moveSpeed)][(int)(data->posY)] == 0)
			data->posX += data->dirX * data->moveSpeed;
		if (worldMap[(int)(data->posX)][(int)(data->posY + data->dirY * data->moveSpeed)] == 0)
			data->posY += data->dirY * data->moveSpeed;
	}
	if (data->D)
	{
		if (worldMap[(int)(data->posX - data->dirX * data->moveSpeed)][(int)(data->posY)] == 0)
			data->posX -= data->dirX * data->moveSpeed;
		if (worldMap[(int)(data->posX)][(int)(data->posY - data->dirY * data->moveSpeed)] == 0)
			data->posY -= data->dirY * data->moveSpeed;
	}
	if (data->R_rot)
	{
		data->oldDirX = data->dirX;
		data->dirX = data->dirX * cos(-data->rotSpeed) - data->dirY * sin(-data->rotSpeed);
		data->dirY = data->oldDirX * sin(-data->rotSpeed) + data->dirY * cos(-data->rotSpeed);
		data->oldPlaneX = data->planeX;
		data->planeX = data->planeX * cos(-data->rotSpeed) - data->planeY * sin(-data->rotSpeed);
		data->planeY = data->oldPlaneX * sin(-data->rotSpeed) + data->planeY * cos(-data->rotSpeed);
	}
	if (data->L_rot)
	{
		data->oldDirX = data->dirX;
		data->dirX = data->dirX * cos(data->rotSpeed) - data->dirY * sin(data->rotSpeed);
		data->dirY = data->oldDirX * sin(data->rotSpeed) + data->dirY * cos(data->rotSpeed);
		data->oldPlaneX = data->planeX;
		data->planeX = data->planeX * cos(data->rotSpeed) - data->planeY * sin(data->rotSpeed);
		data->planeY = data->oldPlaneX * sin(data->rotSpeed) + data->planeY * cos(data->rotSpeed);
	}
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


int	render_next_frame(t_all_data *data)
{
	img_paint_floor_ceiling(data);
	calc_ray_position(data);
	update_player_position(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (0);
}

void	init_data(t_all_data *data, t_img_data *img, char *file)
{
	data->img = img;
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
	data->W = FALSE;
	data->A = FALSE;
	data->S = FALSE;
	data->D = FALSE;
	data->L_rot = FALSE;
	data->R_rot = FALSE;
}

int	handle_keypress(int	key, t_all_data *data)
{
	printf("The %d key has been pressed\n\n", key);
	if (key == XK_Escape)
		handle_destroy(data);
	if (key == XK_W || key == XK_w)
		data->W = TRUE;
	if (key == XK_A || key == XK_a)
		data->A = TRUE;
	if (key == XK_S || key == XK_s)
		data->S = TRUE;
	if (key == XK_D || key == XK_d)
		data->D = TRUE;
	if (key == XK_Left)
		data->L_rot = TRUE;
	if (key == XK_Right)
		data->R_rot = TRUE;
	return (0);
}

int	handle_keyrelease(int key, t_all_data *data)
{
	if (key == XK_W || key == XK_w)
		data->W = FALSE;
	else if (key == XK_A || key == XK_a)
		data->A = FALSE;
	else if (key == XK_S || key == XK_s)
		data->S = FALSE;
	else if (key == XK_D || key == XK_d)
		data->D = FALSE;
	else if (key == XK_Left)
		data->L_rot = FALSE;
	else if (key == XK_Right)
		data->R_rot = FALSE;
	return (0);
}

int	main(int ac, char **av)
{
	t_all_data	data;
	t_img_data	img;

	init_data(&data, &img, av[1]);
	mlx_hook(data.win, 17, 0, handle_destroy, &data);
	mlx_hook(data.win, ON_KEYDOWN, KeyPressMask, handle_keypress, &data);
	mlx_hook(data.win, ON_KEYUP, KeyReleaseMask, handle_keyrelease, &data);
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_loop(data.mlx);
	return (0);
}
