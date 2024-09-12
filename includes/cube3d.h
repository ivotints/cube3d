/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:59:58 by ivotints          #+#    #+#             */
/*   Updated: 2024/09/12 15:34:56 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <fcntl.h> // __O_DIRECTORY
# include <math.h>
# include <X11/keysym.h> // XK_Escape
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

# define PROGRAM_NAME "cube3d"
# define MAP_EXTENSION ".cub"
# define S_WIDTH 800
# define S_HEIGHT 600
# define TEXTURE_SIZE 384
# define TRUE 1
# define FALSE 0
# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_DESTROY 17
# define MAP_EMPTY 'Y'
# define MAP_AIR '0'
# define MAP_BLOCK '1'
# define PI 3.14159265358979323846
# define RENDER_DISTANCE 200
# define FAILURE 0
# define SUCCESS 1

//colors
# define RED "\033[0;31m"
# define RESET "\033[0m"
# define WHITE "\033[1;37m"

//errors
# define ERR_TOO_SHORT_NAME "Too short map path"
# define ERR_EXTENSION "Wrong argument. Extension \".cub\" was not found"
# define ERR_IS_DIR "It is a directory"
# define ERR_FAIL_TO_OPEN_FILE "The file cannot be opened"
# define ERRTOOLOW "Please enter map path. Example: maps/lvl_0.cub"
# define ERRTOOHIGH "Too many arguments. Please enter only one map path"

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

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}	t_img_data;

typedef struct s_keys
{
	char	w;
	char	a;
	char	s;
	char	d;
	char	l_rot;
	char	r_rot;
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

typedef struct s_ray
{
	double	st_cos_x;
	double	st_cos_y;
	double	st_sin_x;
	double	st_sin_y;
	double	ln_cos;
	double	ln_sin;
}	t_ray;

typedef struct s_trace
{
	t_shape	line;
	t_rot	rot;
	t_ray	ray;
	t_ray	step;
	t_vec	pos;
	double	newa;
	double	ref_x;
	double	ref_y;
	int		i;
	char	side;
	double	len;
	double	offset;
}	t_trace;

typedef struct s_map
{
	int		x;
	int		y;
	char	*map;
}	t_map;

typedef struct s_textures
{
	t_img_data	no;
	t_img_data	so;
	t_img_data	we;
	t_img_data	ea;
	int			f;
	int			c;
}	t_textures;

typedef struct s_all_data
{
	t_img_data	img;
	void		*mlx;
	void		*win;
	t_player	player;
	t_keys		keys;
	t_textures	textures;
	t_map		map;
	double		fov;
	double		*depth;
	t_line		*list;
}	t_all_data;

int				create_trgb(int t, int r, int g, int b);
unsigned char	get_separate_trgb(int trgb, char color);
void			img_paint_floor_ceiling(t_all_data *data);
void			img_paint_rectangle(t_img_data *img, int *coord4, int color);
void			my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
int				img_get_color(t_img_data *data, int x, int y);

void			check_data(t_all_data *data);

void			destroy_img(t_all_data *data, t_img_data *img);
void			clean_images(t_all_data *data);
void			clean_data(t_all_data *data, int exit_code);

void			error_msg(char *error1, char *error2, t_all_data *data);
void			check_file(char *path);

void			read_file(char *file, t_line **start);
void			add_line(t_line **list, char *str, int size);

int				handle_destroy(t_all_data *data);
int				is_movement_key(int key);
int				handle_keypress(int key, t_all_data *data);
int				handle_keyrelease(int key, t_all_data *data);

int				is_identifier(char *s1, char *s2, char **result);
int				read_identifier(t_all_data *data, char *line);

void			set_null(t_all_data *data);
void			init_data(t_all_data *data, int ac, char **av);

t_img_data		load_image(void *mlx, char *path);
void			set_texture(t_img_data *img, t_all_data *data, char *path);
void			set_color(int *col, t_all_data *data, char *RGB);
void			load_data(t_all_data *data, char *file);

void			get_map_size(t_line *start, int *x, int *y);
t_map			make_empty(int x, int y);
int				set_map(t_all_data *data, char c, int x, int y);
int				map_flood_fill(t_map *map);
void			load_map(t_all_data *data, t_line *list);

char			get_map_value(t_map *map, int x, int y);

t_player		make_player(void);
int				set_player(t_all_data *data, char c, int x, int y);
void			normalize(double *x, double *y, double scale);
void			update_move_direction(t_all_data *data);

void			collide_x(t_all_data *data);
void			collide_y(t_all_data *data);
void			update_player_condition(t_all_data *data);

int				get_pixel(t_img_data *img, int x, int y);
void			set_img_strip(t_img_data *img, t_shape shape, double offset);
void			cast_forward(t_ray *ray, t_ray step);
void			do_ray(t_all_data *data, t_trace *tr);
void			ray_cast(t_all_data *data);

void			update_view_dir(t_player *player, t_keys *keys);
t_rot			make_rot(double angle);
t_ray			get_init_ray(t_rot *rot, double x, double y);

void			setup_render(t_all_data *data);
int				render_next_frame(t_all_data *data);

t_vec			get_collide_pos(t_trace tr);
char			get_side(t_trace trace);
t_img_data		*get_texture(t_all_data *data, char side);
double			tex_offset(t_trace trace);
void			setup_line(t_all_data *data, t_trace *tr);

void			free_arr(char **arr);
void			trim_from_end(char *str, char c);
int				is_empty(char *str);
void			free_file(t_line *file);

#endif
