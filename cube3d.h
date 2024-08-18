/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:59:58 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/18 11:06:32 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h> // __O_DIRECTORY
# include <math.h>
# include <X11/keysym.h> // XK_Escape
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
#include <time.h>

# define PROGRAM_NAME "cube3d"
# define S_WIDTH 800
# define S_HEIGHT 600
# define TEXTURE_SIZE 384
# define TRUE 1
# define FALSE 0
# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_EXPOSE 12
# define ON_DESTROY 17
# define ResizeRequest 25
# define KeyPressMask (1L<<0)
# define KeyReleaseMask (1L<<1)
# define MAP_EMPTY 'Y'
# define MAP_AIR '0'
# define MAP_BLOCK '1'
# define PI 3.14159265358979323846
# define RENDER_DISTANCE 100

# define FAILURE 0
# define SUCCESS 1


//colors
# define RED "\033[0;31m"
# define RESET "\033[0m"
# define WHITE "\033[1;37m"

# define MAP_EXTENSION ".cub"

//errors
# define ERR_TOO_SHORT_NAME "Too short map path"
# define ERR_EXTENSION "Wrong argument. Extension \".cub\" was not found"
# define ERR_IS_DIR "It is a directory"
# define ERR_FAIL_TO_OPEN_FILE "The file cannot be opened"
# define ERRTOOLOW "Please enter map path. Example: map/lvl_1.cub"
# define ERRTOOHIGH "Too many arguments. Please enter only one map path"


//numerical errors
# define MALLOC_ERROR 1

typedef struct s_vec
{
	int	x;
	int	y;
}	t_vec;

typedef struct s_line
{
	char			*line;
	int				size;
	struct s_line	*next;
}	t_line;

typedef struct	s_img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}	t_img_data;

typedef struct	s_keys
{
	char	W;
	char	A;
	char	S;
	char	D;
	char	L_rot;
	char	R_rot;
}	t_keys;

typedef struct s_player
{
	char	is_set;
	double	pos_x;
	double	pos_y;
	double	view_dir;
	double	move_y;
	double	move_x;
	double	motion_y;
	double	motion_x;
	double	motion_view_dir;
	//t_keys	keys;
	double	render_x;
	double	render_y;
}	t_player;

typedef struct s_shape
{
	int			x;
	int			y;
	int			width;
	int			height;
	t_img_data	*img;
}	t_shape;

typedef struct s_rot
{
	double		angle;
	double		cos;
	double		sin;
}	t_rot;

typedef struct		s_ray {
	double			st_cos_x;
	double			st_cos_y;
	double			st_sin_x;
	double			st_sin_y;
	double			ln_cos;
	double			ln_sin;
}					t_ray;

typedef struct s_trace
{
	t_shape	line;
	double	newa;
	t_rot	rot;
	double	ref_x;
	double	ref_y;
	t_ray	ray;
	t_ray	step;
	int		i;
	t_vec	pos;
	char	side;
	double	len;
	double	offset;


}	t_trace;

typedef struct s_map
{
	int	x;
	int	y;
	char	*map;
}	t_map;



typedef struct s_textures
{
	t_img_data	NO;
	t_img_data	SO;
	t_img_data	WE;
	t_img_data	EA;
	int			F;
	int			C;
}	t_textures;

typedef struct s_free
{
	char	**srgb;
	char	*check;
}	t_free;

typedef struct s_all_data
{
	t_img_data	img;
	void		*mlx;
	void		*win;
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		time;
	double		oldTime;
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	int			mapX;
	int			mapY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
	int			color;
	double		frameTime;
	double		moveSpeed;
	double		rotSpeed;
	double		oldDirX;
	double		oldPlaneX;

	t_player	player;
	t_keys		keys;
	t_textures	textures;
	t_map		map;
	double		fov;
	double		*depth;
	t_line		*list;
	t_free		free;
}	t_all_data;




int				create_trgb(int t, int r, int g, int b);
unsigned char	get_separate_trgb(int trgb, char color);
void			img_paint_floor_ceiling(t_all_data *data);
void			img_paint_rectangle(t_img_data *img, int *coordinates4, int color);
void			my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
int				img_get_color(t_img_data *data, int x, int y);
void			img_paint_noise(t_img_data *data, int delta);

#endif
