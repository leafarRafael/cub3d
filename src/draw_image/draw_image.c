/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:17:51 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/11 15:47:53 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42.h>
#include "utils.h"
#include "data.h"
#include "libft.h"

static void	draw_pixel(int plaine[2],
				int pos[2], int color, mlx_image_t *image);
static void	define_value(int ptr[2], int value1, int value2);

int	draw_plaine(t_data *data)
{
	int	color;
	int	plaine[2];
	int	pos[2];

	{//zerando as cores da imagem
		define_value(pos, 0, 0);
		define_value(plaine, WIDTH, HEIGHT);
		color = ft_color(0, 0, 0, 0);
		draw_pixel(plaine, pos, color, data->image);
	}
	{//pintando a metade superior da imagem
		define_value(pos, 0, 0);
		define_value(plaine, WIDTH, HEIGHT / 2);
		color = ft_color(data->rgb_cel[0],
				data->rgb_cel[1], data->rgb_cel[2],data->rgb_cel[3]);
		draw_pixel(plaine, pos, color, data->image);
	}
	{//pintando a metade inferior da imagem
		define_value(plaine, WIDTH, HEIGHT / 2);
		define_value(pos, 0, HEIGHT / 2);
		color = ft_color(data->rgb_floor[0],
				data->rgb_floor[1], data->rgb_floor[2], data->rgb_floor[3]);
		draw_pixel(plaine, pos, color, data->image);
	}
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) == -1)
		return (1);
	return (0);
}

static void	define_value(int ptr[2], int pos_x, int pos_y)
{
	ptr[Y] = pos_y;
	ptr[X] = pos_x;
}

static void	draw_pixel(int plaine[2], int pos[2], int color, mlx_image_t *image)
{
	int	y;
	int	x;

	y = 0;
	while (y < plaine[Y])
	{
		x = 0;
		while (x < plaine[X])
		{
			mlx_put_pixel(image, pos[X] + x, pos[Y] + y, color);
			x++;
		}
		y++;
	}
}
