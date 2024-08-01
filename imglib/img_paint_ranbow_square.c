/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_paint_ranbow_square.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:41:00 by ivotints          #+#    #+#             */
/*   Updated: 2024/08/01 22:16:53 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	img_gradient_color(int *col_start, int *col_end, double relation)
{
	int	deltaRGB[3];
	int	resultRGB[3];

	deltaRGB[0] = col_end[0] - col_start[0];
	deltaRGB[1] = col_end[1] - col_start[1];
	deltaRGB[2] = col_end[2] - col_start[2];

	resultRGB[0] = col_start[0] + (int)(deltaRGB[0] * relation);
	resultRGB[1] = col_start[1] + (int)(deltaRGB[1] * relation);
	resultRGB[2] = col_start[2] + (int)(deltaRGB[2] * relation);

	return (resultRGB[0] << 16 | resultRGB[1] << 8 | resultRGB[2]);
}

//j is y_current - y_start
//size is y_last - y_start
int	img_rainbow_color(double j, double size)
{
	int	red[3] = {232, 20, 22};
	int	orange[3] = {255, 165, 0};
	int	yellow[3] = {250, 235, 54};
	int	green[3] = {121, 195, 20};
	int	blue[3] = {72, 125, 231};
	int	indigo[3] = {75, 54, 157};
	int	violet[3] = {112, 54, 157};
	size = size / 6;

	if (j < size)
		return(img_gradient_color(red, orange, j / size));
	if (j < size * 2)
		return(img_gradient_color(orange, yellow, (j - size) / size));
	if (j < size * 3)
		return(img_gradient_color(yellow, green, (j - size * 2) / size));
	if (j < size * 4)
		return(img_gradient_color(green, blue, (j - size * 3) / size));
	if (j < size * 5)
		return(img_gradient_color(blue, indigo, (j - size * 4) / size));
	return(img_gradient_color(indigo, violet, (j - size * 5) / size));
}

void	img_paint_ranbow_square(t_img_data *data, int x, int y, int side)
{
	int	i;
	int	j;

	j = y;
	while (j < y + side)
	{
		i = x;
		while (i < x + side)
		{
			my_mlx_pixel_put(data, i, j, img_rainbow_color(j - y, side));
			i++;
		}
		j++;
	}
}
