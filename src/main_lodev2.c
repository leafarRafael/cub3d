/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lodev2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 07:48:30 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/09 13:58:36 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include <stdio.h>
#include <math.h>


int worldmap[mapWidth][mapHeight];
void init_data(t_data *data);
void putPixel(int sizeY,int sizeX, int posy, int posx, int rgb[4], mlx_image_t* image);
void raycasting(t_data *data);

void ft_randomize(void* param)
{
	t_data *data;
	

	data = (t_data*)param;
	raycasting(data);
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}


int main(void)
{
	t_data	data;

	init_data(&data);
	//raycasting(&data);
	mlx_image_to_window(data.mlx, data.image, 0, 0);
	mlx_loop_hook(data.mlx, ft_randomize, (void*)&data);
	mlx_loop_hook(data.mlx, ft_hook, data.mlx);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}

void init_data(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
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
	putPixel(HEIGHT /2, WIDTH, 0, 0, data->ceiling_rgb, data->image);
	putPixel(HEIGHT /2, WIDTH, HEIGHT /2, 0, data->floor_rgb, data->image);
}

void putPixel(int sizeY,int sizeX, int posy, int posx, int rgb[4], mlx_image_t* image)
{
	int	collor;
	int	y;
	int	x;

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

void	raycasting(t_data *data)
{
	int x;
	int RGB_Red = ft_pixel(255, 0, 0, 255);
/* 	int	RGB_Green = ft_pixel(0, 255, 0, 0);;
	int	RGB_Blue = ft_pixel(0, 0, 255, 0);;
	int	RGB_White = ft_pixel(255, 255, 255, 0);;
	int	RGB_Yellow = ft_pixel(255, 255, 0, 0);; */

	x = 0;
	//mapWidth
	while(x < WIDTH)
	{
		double camera = 2 * x / (double) WIDTH;
		double ray_dirX = data->dir[X] + data->plane[X] * camera;
		double ray_dirY = data->dir[Y] + data->plane[Y] * camera;
		int mapX = (int) data->pos[X];
		int mapY = (int) data->pos[Y];
		double sideDistX;
		double sideDistY;
		double deltaDistX;
		double deltaDistY;
		if (ray_dirX == 0)
			deltaDistX = 1e30;
		else
			deltaDistX = fabs(1 / ray_dirX);
		if (ray_dirY == 0)
			deltaDistY = 1e30;
		else
			deltaDistY = fabs(1 / ray_dirY);

		double	perpWallDist = 0.0;
		int stepX;
		int stepY;
		int hit = 0;
		int side;
		if(ray_dirX < 0)
		{
			stepX = -1;
			sideDistX = (data->pos[X] - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - data->pos[X]) * deltaDistX;
		}
		if(ray_dirY < 0)
		{
			stepY = -1;
			sideDistY = (data->pos[Y] - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - data->pos[Y]) * deltaDistY;
		}
		while(hit == 0)
		{
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if(worldmap[mapX][mapY] > 0)
				hit = 1;
		}
		int lineHeight = (int)(HEIGHT / perpWallDist);
		if(side == 0)
			perpWallDist = (sideDistX - deltaDistX);
     	else
		 	perpWallDist = (sideDistY - deltaDistY);
		int drawStart = -lineHeight / 2 + HEIGHT / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + HEIGHT / 2;
		if(drawEnd >= HEIGHT)
			drawEnd = HEIGHT - 1;
		mlx_put_pixel(data->image, drawStart, drawEnd, RGB_Red);
		x++;
	}
}