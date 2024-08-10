  /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_rafa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:28:25 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/09 20:11:24 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"

void init_data(t_data *data);
void putPixel(int sizeY,int sizeX, int posy, int posx, int rgb[4], mlx_image_t* image);

int main()
{
	t_data data;

	init_data(&data);

	for (int y = 0;y < mapWidth; y++)
	{
		for (int x= 0; x < mapWidth; x++)
			printf("%d ", worldmap[y][x]);
		printf("\n");
	}
/* 	mlx_image_to_window(data.mlx, data.image, 0, 0);





  	mlx_loop(data.mlx);
	mlx_terminate(data.mlx); */
}

void init_data(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->player = mlx_new_image(data->mlx, 200, 200);
	data->pos[X] = 19;
	data->pos[Y] = 21;
	data->dir[X] = -1;
	data->dir[Y] = 0;
	data->plane[X] = 0;
	data->plane[Y] = 0.66;
	data->floor_rgb[0] = 0;
	data->floor_rgb[1] = 100;
	data->floor_rgb[2] = 0;
	data->floor_rgb[3] = 255;
	data->ceiling_rgb[0] = 0;
	data->ceiling_rgb[1] = 0;
	data->ceiling_rgb[2] = 100;
	data->ceiling_rgb[3] = 255;
	data->player_rgb[0] = 100;
	data->player_rgb[1] = 0;
	data->player_rgb[2] = 0;
	data->player_rgb[3] = 255;

	putPixel(HEIGHT /2, WIDTH, 0, 0, data->ceiling_rgb, data->image);
	putPixel(HEIGHT /2, WIDTH, HEIGHT /2, 0, data->floor_rgb, data->image);
}

void putPixel(int sizeY,int sizeX, int posy, int posx, int rgb[4], mlx_image_t* image)
{
	int collor;
	int y;
	int x;

	y = 0;
	collor = ft_pixel(rgb[0], rgb[1], rgb[2], rgb[3]);
	while (y < sizeY)
	{
		x = 0;
		while(x < sizeX)
		{
			mlx_put_pixel(image, posx + x, posy + y, collor);
			x++;
		}
		y++; 
	}
}