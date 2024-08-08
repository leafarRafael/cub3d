/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 07:48:30 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/08 14:53:10 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <../../lib/MLX42/include/MLX42/MLX42.h>

// #define WIDTH 800
// #define HEIGHT 400

// static mlx_image_t* image;

// int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

// void ft_randomize(void* param)
// {
// 	(void)param;
// 	for (uint32_t i = 0; i < image->width; ++i)
// 	{
// 		for (uint32_t y = 0; y < image->height; ++y)
// 		{
// 			uint32_t color = ft_pixel(
// 				rand() % 0xFF, // R
// 				rand() % 0xFF, // G
// 				rand() % 0xFF, // B
// 				rand() % 0xFF  // A
// 			);
// 			mlx_put_pixel(image, i, y, color);
// 		}
// 	}
// }

// void ft_hook(void* param)
// {
// 	mlx_t* mlx = param;

// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_UP))
// 		image->instances[0].y -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
// 		image->instances[0].y += 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
// 		image->instances[0].x -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
// 		image->instances[0].x += 5;
// }

// // -----------------------------------------------------------------------------

// int32_t main(void)
// {
// 	mlx_t* mlx;

// 	// Gotta error check this stuff
// 	if (!(mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true)))
// 	{
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (!(image = mlx_new_image(mlx, 128, 128)))
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}

// 	mlx_loop_hook(mlx, ft_randomize, mlx);
// 	mlx_loop_hook(mlx, ft_hook, mlx);

// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }

// #include "../../lib/lib_get_print/includes/libft.h"
// #include "../../lib/MLX42/include/MLX42/MLX42.h"
// #include <stdlib.h>

// #define mapWidth 24
// #define mapHeight 24
// #define WIDTH 800
// #define HEIGHT 400

// void	ft_hook(void *param)
// {
// 	mlx_t *mlx;

// 	mlx = param;
// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// }

// int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

// int	rendering_floor_and_ceiling(mlx_t *mlx, mlx_image_t *ceiling, mlx_image_t *floor)
// {
// 	ceiling = mlx_new_image(mlx, WIDTH, HEIGHT);
// 	floor = mlx_new_image(mlx, WIDTH, HEIGHT);
// 	if (!ceiling || !floor)
// 	{
// 		ft_putstr_fd((char *) mlx_strerror(mlx_errno), STDERR_FILENO);
// 		return (EXIT_FAILURE);
// 	}
// 	for (uint32_t i = 0; i < ceiling->width; ++i)
// 	{
// 		for (uint32_t y = 0; y < (ceiling->height / 2); ++y)
// 		{
// 			uint32_t color = ft_pixel(
// 				0xFF, // R
// 				0xFF, // G
// 				0xFF, // B
// 				0xFF  // A
// 			);
// 			mlx_put_pixel(ceiling, i, y, color);
// 		}
// 	}
// 	for (uint32_t i = 0; i < floor->width; ++i)
// 	{
// 		for (uint32_t y = (floor->height / 2); y < floor->height; ++y)
// 		{
// 			uint32_t color = ft_pixel(
// 				0x42, // R
// 				0xFF, // G
// 				0x64, // B
// 				0xD9  // A
// 			);
// 			mlx_put_pixel(floor, i, y, color);
// 		}
// 	}
// 	if (mlx_image_to_window(mlx, floor, 0, 0) == -1 || mlx_image_to_window(mlx, ceiling, 0, 0) == -1)
// 	{
// 		mlx_close_window(mlx);
// 		ft_putstr_fd((char *) mlx_strerror(mlx_errno), STDERR_FILENO);
// 		return (EXIT_FAILURE);
// 	}
// 	return (EXIT_SUCCESS);
// }

// int	main(void)
// {
// 	int			worldMap[mapWidth][mapHeight] = {
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
// };
// 	mlx_t		*mlx;
// 	mlx_image_t	*ceiling;
// 	mlx_image_t	*floor;

// 	double posX = 22, posY = 12; // player position
// 	double dirX = -1, dirY = 0; // vetor direção inicial
// 	double planeX = 0, planeY = 0.66; // plano da câmera

// 	double time = 0, oldTime = 0; // Hora do quadro atual e hora do quadro anterior, respectivamente.

// 	mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
// 	if (!mlx)
// 	{
// 		ft_putstr_fd((char *) mlx_strerror(mlx_errno), STDERR_FILENO);
// 		return (EXIT_FAILURE);
// 	}

// 	for (int x = 0; x < WIDTH; x++)
// 	{
// 		double cameraX = 2 * x / WIDTH -1;
// 		double rayDirX = dirX + planeX * cameraX;
// 		double rayDirY = dirY + planeY * cameraX;

// 		int	mapX = (int)posX;
// 		int mapY = (int)posY;

// 		double sideDistX;
// 		double sideDistY;

// 		double deltaDistX = (rayDirX == 0) ? 1e30 : abs(1 / rayDirX);
// 		double deltaDistY = (rayDirX == 0) ? 1e30 : abs(1 / rayDirX);

// 		double perpWallDist;

// 		int	stepX;
// 		int	stepY;

// 		int hit = 0;
// 		int side;

// 		if (rayDirX < 0)
// 		{
// 			stepX = -1;
// 			sideDistX = (posX - mapX) * deltaDistX;
// 		}
// 		else
// 		{
// 			stepX = 1;
// 			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
// 		}
// 		if (rayDirY < 0)
// 		{
// 			stepY = -1;
// 			sideDistY = (posY - mapY) * deltaDistY;
// 		}
// 		else
// 		{
// 			stepY = 1;
// 			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
// 		}
// 		while (hit == 0)
// 		{
// 			if (sideDistX < sideDistY)
// 			{
// 				sideDistX += deltaDistX;
// 				mapX += stepX;
// 				side = 0;
// 			}
// 			else
// 			{
// 				sideDistY += deltaDistY;
// 				mapY += stepY;
// 				side = 1;
// 			}
// 		}
// 		if (worldMap[mapX][mapY] > 0) hit = 1;
// 	}
// 	if (rendering_floor_and_ceiling(mlx, ceiling, floor))
// 		return (EXIT_FAILURE);
// 	mlx_loop_hook(mlx, ft_hook, mlx);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }


/*
Copyright (c) 2004-2021, Lode Vandevenne

All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

	* Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
	* Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

// #include <cmath>
// #include <string>
// #include <vector>
// #include <iostream>

// #include "quickcg.h"
// using namespace QuickCG;

// /*
// g++ *.cpp -lSDL -O3 -W -Wall -ansi -pedantic
// g++ *.cpp -lSDL
// */

// //place the example code below here:

// #define screenWidth 640
// #define screenHeight 480
// #define mapWidth 24
// #define mapHeight 24

// int worldMap[mapWidth][mapHeight]=
// {
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
// };

// void	ft_hook(void *param)
// {
// 	mlx_t *mlx;

// 	mlx = param;
// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_UP))
// 		image->instances[0].y -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
// 		image->instances[0].y += 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
// 		image->instances[0].x -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
// 		image->instances[0].x += 5;
// }

// int main(void)
// {

// 	double posX = 22, posY = 12;  //x and y start position
// 	double dirX = -1, dirY = 0; //initial direction vector
// 	double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

// 	double time = 0; //time of current frame
// 	double oldTime = 0; //time of previous frame

// 	mlx_init(screenWidth, screenHeight, "cub3D", true);
// 	while(!done())
// 	{
// 		for(int x = 0; x < screenWidth; x++)
// 		{
// 			//calculate ray position and direction
// 			double cameraX = 2 * x / (double)screenWidth - 1; //x-coordinate in camera space
// 			double rayDirX = dirX + planeX * cameraX;
// 			double rayDirY = dirY + planeY * cameraX;
// 	  		//which box of the map we're in
// 			int mapX = int(posX);
// 			int mapY = int(posY);

// 			//length of ray from current position to next x or y-side
// 			double sideDistX;
// 			double sideDistY;

// 			//length of ray from one x or y-side to next x or y-side
// 			//these are derived as:
// 			//deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX))
// 			//deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY))
// 			//which can be simplified to abs(|rayDir| / rayDirX) and abs(|rayDir| / rayDirY)
// 			//where |rayDir| is the length of the vector (rayDirX, rayDirY). Its length,
// 			//unlike (dirX, dirY) is not 1, however this does not matter, only the
// 			//ratio between deltaDistX and deltaDistY matters, due to the way the DDA
// 			//stepping further below works. So the values can be computed as below.
// 			// Division through zero is prevented, even though technically that's not
// 			// needed in C++ with IEEE 754 floating point values.
// 			double deltaDistX = (rayDirX == 0) ? 1e30 : std::abs(1 / rayDirX);
// 			double deltaDistY = (rayDirY == 0) ? 1e30 : std::abs(1 / rayDirY);

// 			double perpWallDist;

// 			//what direction to step in x or y-direction (either +1 or -1)
// 			int stepX;
// 			int stepY;

// 			int hit = 0; //was there a wall hit?
// 			int side; //was a NS or a EW wall hit?
// 			//calculate step and initial sideDist
// 			if(rayDirX < 0)
// 			{
// 				stepX = -1;
// 				sideDistX = (posX - mapX) * deltaDistX;
// 			}
// 			else
// 			{
// 				stepX = 1;
// 				sideDistX = (mapX + 1.0 - posX) * deltaDistX;
// 			}
// 			if(rayDirY < 0)
// 			{
// 				stepY = -1;
// 				sideDistY = (posY - mapY) * deltaDistY;
// 			}
// 			else
// 			{
// 				stepY = 1;
// 				sideDistY = (mapY + 1.0 - posY) * deltaDistY;
// 			}
// 			//perform DDA
// 			while(hit == 0)
// 			{
// 			//jump to next map square, either in x-direction, or in y-direction
// 				if(sideDistX < sideDistY)
// 				{
// 					sideDistX += deltaDistX;
// 					mapX += stepX;
// 					side = 0;
// 				}
// 				else
// 				{
// 					sideDistY += deltaDistY;
// 					mapY += stepY;
// 					side = 1;
// 				}
// 				//Check if ray has hit a wall
// 				if(worldMap[mapX][mapY] > 0) hit = 1;
// 			}
// 			//Calculate distance projected on camera direction. This is the shortest distance from the point where the wall is
// 			//hit to the camera plane. Euclidean to center camera point would give fisheye effect!
// 			//This can be computed as (mapX - posX + (1 - stepX) / 2) / rayDirX for side == 0, or same formula with Y
// 			//for size == 1, but can be simplified to the code below thanks to how sideDist and deltaDist are computed:
// 			//because they were left scaled to |rayDir|. sideDist is the entire length of the ray above after the multiple
// 			//steps, but we subtract deltaDist once because one step more into the wall was taken above.
// 			if(side == 0) perpWallDist = (sideDistX - deltaDistX);
// 			else          perpWallDist = (sideDistY - deltaDistY);

// 			//Calculate height of line to draw on screen
// 			int lineHeight = (int)(h / perpWallDist);

// 			//calculate lowest and highest pixel to fill in current stripe
// 			int drawStart = -lineHeight / 2 + h / 2;
// 			if(drawStart < 0) drawStart = 0;
// 			int drawEnd = lineHeight / 2 + h / 2;
// 			if(drawEnd >= h) drawEnd = h - 1;

// 			//choose wall color
// 			ColorRGB color;
// 			switch(worldMap[mapX][mapY])
// 			{
// 				case 1:  color = RGB_Red;    break; //red
// 				case 2:  color = RGB_Green;  break; //green
// 				case 3:  color = RGB_Blue;   break; //blue
// 				case 4:  color = RGB_White;  break; //white
// 				default: color = RGB_Yellow; break; //yellow
// 			}

// 			//give x and y sides different brightness
// 			if(side == 1) {color = color / 2;}

// 			//draw the pixels of the stripe as a vertical line
// 			verLine(x, drawStart, drawEnd, color);
// 		}
// 		//timing for input and FPS counter
// 		oldTime = time;
// 		time = getTicks();
// 		double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
// 		print(1.0 / frameTime); //FPS counter
// 		redraw();
// 		cls();

// 		//speed modifiers
// 		double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
// 		double rotSpeed = frameTime * 3.0; //the constant value is in radians/second
// 		readKeys();
// 		//move forward if no wall in front of you
// 		if(keyDown(SDLK_UP))
// 		{
// 			if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
// 			if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
// 		}
// 		//move backwards if no wall behind you
// 		if(keyDown(SDLK_DOWN))
// 		{
// 			if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
// 			if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
// 		}
// 		//rotate to the right
// 		if(keyDown(SDLK_RIGHT))
// 		{
// 			//both camera direction and camera plane must be rotated
// 			double oldDirX = dirX;
// 			dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
// 			dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
// 			double oldPlaneX = planeX;
// 			planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
// 			planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
// 		}
// 		//rotate to the left
// 		if(keyDown(SDLK_LEFT))
// 		{
// 			//both camera direction and camera plane must be rotated
// 			double oldDirX = dirX;
// 			dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
// 			dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
// 			double oldPlaneX = planeX;
// 			planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
// 			planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
// 		}
// 	}
// }

#include <math.h>
#include <stdlib.h>
#include "../lib/lib_get_print/includes/libft.h"
#include "../lib/MLX42/include/MLX42/MLX42.h"
#define WIDTH 800
#define HEIGHT 600
#define mapWidth 24
#define mapHeight 24

typedef struct s_game {
	// em qual quadrado o player está posicionado no mapa;
	int			mapX, mapY;
	// estrutura principal da mlx
	mlx_t		*mlx;
	// vetor de posição do player
	double		posX, posY;
	// vetor de direção inicial
	double		dirX, dirY;
	// versão 2D raycaster do plano da câmera
	double		planeX, planeY;
	// coordenada x no espaço da câmera
	double		cameraX;
	// direção dos raios X e Y
	double		rayDirX, rayDirY;
	// tempo atual e anterior do frame respectivamente
	double		time, oldtime;
	// comprimento do raio da posição atual até o proximo lado x ou y;
	double		sideDistX, sideDistY;
	// comprimento do raio de um ponto x ou y para o proximo x ponto x ou y;
	double		deltaDistX, deltaDistY;
	// distância da parede
	double		perpWallDist;
	// qual direção do paso para direção x ou y (entre 1 ou -1)
	int			stepX, stepY;
	// valor booleano para saber se atingimos a parede;
	int			hit;
	// qual o lado o raio atingiu a parede
	int			side;
	// calcular altura da linha para se desenhar na tela
	int			lineHeight;
	// variáveis para guardar o resultado do calculo do maior e menor pixel que devemos pintar na faixa atual
	int			drawStart, drawEnd;
	// frameTime
	double		frameTime;
	// modificadores de velocidade
	double		moveSpeed, rotSpeed;
	// estrutura de imagem da mlx
	mlx_image_t *screen_img;
}	t_game;


void	raycasting(t_game *main_struct);

int	worldMap[mapWidth][mapHeight] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int	ft_pixel(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

// rendering ceiling and floor
int	rendering_ceiling_and_floor(t_game *game)
{
	game->screen_img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->screen_img)
	{
		ft_putstr_fd((char *) mlx_strerror(mlx_errno), STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	for (uint32_t i = 0; i < game->screen_img->width; ++i)
	{
		for (uint32_t y = 0; y < (game->screen_img->height / 2); ++y)
		{
			uint32_t color = ft_pixel(
				0xFF, // R
				0xFF, // G
				0xFF, // B
				0xFF  // A
			);
			mlx_put_pixel(game->screen_img, i, y, color);
		}
	}
	for (uint32_t i = 0; i < game->screen_img->width; ++i)
	{
		for (uint32_t y = (game->screen_img->height / 2); y < game->screen_img->height; ++y)
		{
			uint32_t color = ft_pixel(
				0x42, // R
				0xFF, // G
				0x64, // B
				0xD9  // A
			);
			mlx_put_pixel(game->screen_img, i, y, color);
		}
	}
	if (mlx_image_to_window(game->mlx, game->screen_img, 0, 0) == -1)
	{
		mlx_close_window(game->mlx);
		ft_putstr_fd((char *) mlx_strerror(mlx_errno), STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}


void	re_rendering_image(t_game *game, keys_t pressed_key)
{
	if (pressed_key == MLX_KEY_W)
	{
		if (worldMap[(int)(game->posX + game->dirX * game->moveSpeed)][(int)game->posY] == false)
			game->posX += game->dirX * game->moveSpeed;
		if (worldMap[(int)game->posX][(int)(game->posY + game->dirY * game->moveSpeed)] == false)
			game->posY += game->dirY * game->moveSpeed;
	}
	else if (pressed_key == MLX_KEY_S)
	{
		if (worldMap[(int)(game->posX - game->dirX * game->moveSpeed)][(int)game->posY] == false)
			game->posX -= game->dirX * game->moveSpeed;
		if (worldMap[(int)game->posX][(int)(game->posY - game->dirY * game->moveSpeed)] == false)
			game->posY -= game->dirY * game->moveSpeed;
	}
	else if (pressed_key == MLX_KEY_A)
	{
		double oldDirX = game->dirX;
		game->dirX = game->dirX * cos(-game->rotSpeed) - game->dirY * sin(-game->rotSpeed);
		game->dirY = oldDirX * sin(-game->rotSpeed) + game->dirY * cos(-game->rotSpeed);
		double oldPlaneX = game->planeX;
		game->planeX = game->planeX * cos(-game->rotSpeed) - game->planeY * sin(-game->rotSpeed);
		game->planeY = oldPlaneX * sin(-game->rotSpeed) + game->planeY * cos(-game->rotSpeed);
	}
	else if (pressed_key == MLX_KEY_D)
	{
		double oldDirX = game->dirX;
		game->dirX = game->dirX * cos(game->rotSpeed) - game->dirY * sin(game->rotSpeed);
		game->dirY = oldDirX * sin(game->rotSpeed) + game->dirY * cos(game->rotSpeed);
		double oldPlaneX = game->planeX;
		game->planeX = game->planeX * cos(game->rotSpeed) - game->planeY * sin(game->rotSpeed);
		game->planeY = oldPlaneX * sin(game->rotSpeed) + game->planeY * cos(game->rotSpeed);
	}
}

// loop hook function
void	loop_hook_function(mlx_key_data_t keydatam, void *param)
{
	t_game *game;

	game = (t_game *)param;
	if (keydatam.key == MLX_KEY_ESCAPE)	
		mlx_close_window(game->mlx);
	else if (keydatam.key == MLX_KEY_A)
		re_rendering_image(game, MLX_KEY_A);
	else if (keydatam.key == MLX_KEY_D)
		re_rendering_image(game, MLX_KEY_D);
	else if (keydatam.key == MLX_KEY_W)
		re_rendering_image(game, MLX_KEY_W);
	else if (keydatam.key == MLX_KEY_S)
		re_rendering_image(game, MLX_KEY_S);
	raycasting(game);
	mlx_image_to_window(game->mlx, game->screen_img, 0, 0);
}

int	first_step(t_game *game)
{
	if (rendering_ceiling_and_floor(game)) return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	instatiation_window(mlx_t *mlx)
{
	mlx_key_hook(mlx, loop_hook_function, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

double	abs_double(double number)
{
	if (number < 0)
		return (-number);
	else
		return (number);
}

// raycasting loop
void	raycasting(t_game *main_struct)
{
	for (int x = 0; x < WIDTH; x++)
	{
		// coordenada x no espaço da câmera
		main_struct->cameraX = 2 * x / (double)WIDTH - 1;
		// direção dos raios X e Y
		main_struct->rayDirX = main_struct->dirX + main_struct->planeX * main_struct->cameraX;
		main_struct->rayDirY = main_struct->dirY + main_struct->planeY * main_struct->cameraX;
		main_struct->mapX = (int) main_struct->posX;
		main_struct->mapY = (int) main_struct->posY;
		
		main_struct->deltaDistX = (main_struct->rayDirX == 0) ? 1e30 : abs_double(1 / main_struct->rayDirX);
		main_struct->deltaDistY = (main_struct->rayDirY == 0) ? 1e30 : abs_double(1 / main_struct->rayDirY);

		main_struct->hit = 0;
		if (main_struct->rayDirX < 0)
		{
			main_struct->stepX = -1;
			main_struct->sideDistX = (main_struct->posX - main_struct->mapX) * main_struct->deltaDistX;
		}
		else
		{
			main_struct->stepX = 1;
			main_struct->sideDistX = (main_struct->mapX + 1.0 - main_struct->posX) * main_struct->deltaDistX;
		}
		if (main_struct->rayDirY < 0)
		{
			main_struct->stepY = -1;
			main_struct->sideDistY = (main_struct->posY - main_struct->mapY) * main_struct->deltaDistY;
		}
		else
		{
			main_struct->stepY = 1;
			main_struct->sideDistY = (main_struct->mapY + 1.0 - main_struct->posY) * main_struct->deltaDistY;
		}
		// perform DDA
		while (main_struct->hit == 0)
		{
			if (main_struct->sideDistX < main_struct->sideDistY)
			{
				main_struct->sideDistX += main_struct->deltaDistX;
				main_struct->mapX += main_struct->stepX;
				main_struct->side = 0;
			}
			else
			{
				main_struct->sideDistY += main_struct->deltaDistY;
				main_struct->mapY += main_struct->stepY;
				main_struct->side = 1;
			}
			if (worldMap[main_struct->mapX][main_struct->mapY] > 0) main_struct->hit = 1;
		}
		if (main_struct->side == 0) main_struct->perpWallDist = (main_struct->sideDistX - main_struct->deltaDistX);
		else main_struct->perpWallDist = (main_struct->sideDistY - main_struct->deltaDistY);
		
		main_struct->lineHeight = (int) (HEIGHT / main_struct->perpWallDist);

		main_struct->drawStart = -main_struct->lineHeight / 2 + HEIGHT / 2;
		if (main_struct->drawStart < 0) main_struct->drawStart = 0;
		main_struct->drawEnd = main_struct->lineHeight / 2 + HEIGHT / 2;
		if (main_struct->drawEnd >= HEIGHT) main_struct->drawEnd = HEIGHT -1;

		// int alpha = 1;
		int red = ft_pixel(255, 0, 0, 1);
		int green = ft_pixel(0, 255, 0, 1);
		int blue = ft_pixel(0, 0, 255, 1);
		int white = ft_pixel(0, 0, 0, 1);
		int	yellow = ft_pixel(255, 255, 224, 1);
		int color;
		switch (worldMap[main_struct->mapX][main_struct->mapY])
		{
			case 1: color = red; break; // red color
			case 2: color = green; break; // green color
			case 3: color = blue; break; // blue color
			case 4: color = white; break; // white color
			default: color = yellow; break; // yellow color
		}
		
		if (main_struct->side == 1) {color = color / 2;}
		int row = main_struct->drawStart;
		while (row < main_struct->drawEnd)
		{
			mlx_put_pixel(main_struct->screen_img, x, row, color);
			row++;
		}
		main_struct->moveSpeed = 100;
		main_struct->rotSpeed = 50;
	}
}
// movement and raycasting
int	main(void)
{
	t_game main_struct;

	main_struct.mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!main_struct.mlx)
		return (EXIT_FAILURE);
	first_step(&main_struct);
	
	// vetor de posição do player
	main_struct.posX = 22, main_struct.posY = 12;
	// vetor de direção inicial
	main_struct.dirX = -1, main_struct.dirY = 0;
	// versão 2D raycaster do plano da câmera
	main_struct.planeX = 0, main_struct.planeY = 0.66;
	
	// tempo atual do frame
	main_struct.time = 0;
	// tempo anterior do frame
	main_struct.oldtime = 0;
	
	// mlx_image_t *render_line = mlx_new_image(mlx, WIDTH, HEIGHT);
	raycasting(&main_struct);
	mlx_image_to_window(main_struct.mlx, main_struct.screen_img, 0, 0);
	instatiation_window(main_struct.mlx);
	return (EXIT_SUCCESS);
}
