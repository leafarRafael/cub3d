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

#include "data.h"

void putPixel(int sizeY,int sizeX, int posy, int posx, int rgb[4], mlx_image_t* image);
void init_data(t_data *data);

void pixel(int plaine[2], int pos[2], double angle, mlx_image_t* image)
{
	int collor;
	int	index[2];
	double coordWidth[2];

	collor = ft_pixel(100, 0, 0, 255);
	index[Y] = plaine[Y] +1;
	while (--index[Y] >= 0)
  	{
    	index[X] = plaine[X] +1;
    	while(--index[X] >= 0)
		{
			coordWidth[X] = round((double) (index[X] + pos[X] + index[Y]) * angle);
			coordWidth[Y] = round((double) (index[X] + pos[X] - index[Y] ) * angle);
			mlx_put_pixel(image, coordWidth[X], index[Y] + pos[Y], collor);
			mlx_put_pixel(image, coordWidth[Y], index[Y] + pos[Y], collor);
			coordWidth[X] = round((double) (index[X] + pos[X] + index[Y]) * angle /2);
			coordWidth[Y] = round((double) (index[X] + pos[X] - index[Y] ) * angle / 2);
			mlx_put_pixel(image, coordWidth[X] + (plaine[Y] / 3), index[Y] + pos[Y], collor);
		}
  	}
}

void putline(int plaine[2], int pos[2], mlx_image_t* image)
{
	int collor;
	int y;
	int x;

	y = 0;
	collor = ft_pixel(100, 0, 0, 255);
	while (y < plaine[Y])
	{
		x = 0;
		while(x < plaine[X])
		{
			mlx_put_pixel(image, pos[X] + x, pos[Y] + y, collor);
			x++;
		}
		y++;  
	}
}

void ray(t_data *data);

int main()
{
	t_data data;

	init_data(&data);
	mlx_image_to_window(data.mlx, data.image, 0, 0);
	ray(&data);
	mlx_image_to_window(data.mlx, data.player, (WIDTH / 2) - 200, HEIGHT /2);
  	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
}

void ray(t_data *data)
{
	int	plaine[2] = {150, 2};
	int	pos[2] = {0, 0};

	pixel(plaine, pos, 0.66, data->player);
	pos[X] = 100;
	pos[Y] = 0;
	putline(plaine, pos, data->player);	
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