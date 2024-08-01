/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:58:15 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/01 22:30:21 by ivotints         ###   ########.fr       */
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

void	change_player_xy(t_all_data *data, int key)
{
	if (key == XK_W || key == XK_w)
		data->player_xy[1] -= 1;
	if (key == XK_A || key == XK_a)
		data->player_xy[0] -= 1;
	if (key == XK_S || key == XK_s)
		data->player_xy[1] += 1;
	if (key == XK_D || key == XK_d)
		data->player_xy[0] += 1;
}

int	handle_input(int key, t_all_data *data)
{
	if (key == XK_Escape)
	{
		printf("The %d key (ESC) has been pressed\n\n", key);
		handle_destroy(data);
	}
	if (is_movement_key(key))
		change_player_xy(data, key);
	printf("The %d key has been pressed\n\n", key);
	return (0);
}

int	render_next_frame(t_all_data *data)
{
	int	ijr[3];
	int	color;

	ijr[0] = data->player_xy[0];
	ijr[1] = data->player_xy[1];
	ijr[2] = 20;
	color = create_trgb(0, 255, 255, 51);
	img_paint_floor_ceiling(data);
	img_paint_circle(data->img, ijr, color);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (0);
}

void	init_data(t_all_data *data, t_img_data *img)
{
	data->img = img;
	data->ceiling_color = create_trgb(0, 51, 153, 255);
	data->floor_color = create_trgb(0, 64, 64, 64);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, S_WIDTH, S_HEIGHT, PROGRAM_NAME);
	img->img = mlx_new_image(data->mlx, S_WIDTH, S_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	data->player_xy[0] = 100;
	data->player_xy[1] = 100;
}

int	main(void)
{
	t_all_data	data;
	t_img_data	img;

	init_data(&data, &img);
	mlx_key_hook(data.win, handle_input, &data);
	mlx_hook(data.win, 17, 0, handle_destroy, &data);
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_loop(data.mlx);
	return (0);
}
