/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lodev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 07:48:30 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/08 14:09:13 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include <stdio.h>

int worldmap[mapWidth][mapHeight];
int collor = (255 << 24 | 0 << 16 | 0 << 8 | 255);

void init_data(t_data *data);
void ft_pixelTest(t_data *data);
void putPixel(int sizeY,int sizeX, int posy, int posx, int rgb[4], mlx_image_t* image);

int main(void)
{
  t_data  data;
  init_data(&data);
  ft_pixelTest(&data);
  mlx_image_to_window(data.mlx, data.image, 0, 0);
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

void  pixel(t_data *data, int posX, int posY);

void pixel(t_data *data, int posX, int posY)
{
  int x;
  int y;

  y = 0;
  while (y < mapHeight)
  {
    x = 0;
    while (x < mapWidth)
    {
      mlx_put_pixel(data->image, posY+y, posX+x, collor);
      x++;
    }
    y++;
  }  
}

void  ft_pixelTest(t_data *data)
{
  int x;
  int y;

  y = 0;
  while (y <= mapHeight)
  {
    x = 0;
    while (x <= mapWidth)
    {
      if (worldmap[y][x] == 1)
        pixel(data, (HEIGHT / mapHeight) * x, (WIDTH / mapWidth) * y);
      if (worldmap[y][x] == 87)
        printf("%d, %d", y, x);
      x++;
    }
    y++;
  }
}