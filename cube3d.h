/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:59:58 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/01 15:22:14 by ivotints         ###   ########.fr       */
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

# define S_WIDTH 800
# define S_HEIGHT 600
# define ON_KEYDOWN 2
# define ON_DESTROY 17
# define KeyPressMask (1L<<0)


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


//numerical errorc
# define MALLOC_ERROR 1


typedef struct	s_mlx_data
{
	void	*mlx;
	void	*win;
}	t_mlx_data;

typedef struct	s_img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;




#endif
