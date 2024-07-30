/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:58:15 by ivotints          #+#    #+#             */
/*   Updated: 2024/07/30 23:32:42 by ivotints         ###   ########.fr       */
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

/* int	handle_input(int keysym, t_mlx_data *data)
{
	if(keysym == XK_Escape)
	{
		printf("The %d key (ESC) has been pressed\n\n", keysym);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
	}
	printf("The %d key has been pressed\n\n", keysym);
	return (0);
} */


void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	img_paint_all(t_img_data *data, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < S_HEIGHT)
	{
		x = 0;
		while (x < S_WIDTH)
		{
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
}

void	img_paint_square(t_img_data *data, int color, int x, int y, int side)
{
	int	i;
	int	j;

	j = y;
	while (j < y + side)
	{
		i = x;
		while (i < x + side)
		{
			my_mlx_pixel_put(data, i, j, color);
			i++;
		}
		j++;
	}
}

void	img_paint_circle(t_img_data *data, int color, int x, int y, double radius)
{
	int	i;
	int	j;
	double	distance;

	j = y - radius;
	while (j < y + radius)
	{
		i = x - radius;
		while (i < x + radius)
		{
			distance = sqrt((x - i) * (x - i) + (y - j) * (y - j));
			if (distance < radius)
			{
				my_mlx_pixel_put(data, i, j, color);
			}
			i++;
		}
		j++;
	}
}

int	main(void)
{
	t_mlx_data	mlx;
	t_img_data	img;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, S_WIDTH, S_HEIGHT, "cube3d");
	img.img = mlx_new_image(mlx.mlx, S_WIDTH, S_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

	img_paint_all(&img, 0x00FFFFFF);
	img_paint_square(&img, 0x00000000, S_WIDTH / 10, S_HEIGHT / 10, S_WIDTH / 10);
	img_paint_circle(&img, 0x000000FF, S_WIDTH / 5, S_HEIGHT / 10, 50);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_loop(mlx.mlx);




	//mlx_key_hook(data.win, handle_input, &data);




	//mlx_destroy_window(data.mlx, data.win);
	//mlx_destroy_display(data.mlx);
	//free(data.mlx);
	return (0);
}