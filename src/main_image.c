/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 07:48:30 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/07 18:33:40 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utils.h"
#include <../lib/MLX42/include/MLX42/MLX42.h>

#define WIDTH 512
#define HEIGHT 512
#define pos_x 128
#define pos_y 128

int					rgb[4] = {255, 0, 0, 255};
int					rgbflor[4] = {100, 100, 100, 255};
int					rgbceling[4] = {0, 200, 200, 155};

static mlx_image_t* image;

void ft_randomize(void* param)
{
	int	*rgb;

	rgb = (int*)param;
	putpixel(40, 40, rgb, image, 1);
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

void ft_wallleft(mlx_image_t* plain);
void ft_wallRight(mlx_image_t* plain);
void ft_wallback(mlx_image_t* plain);
void ft_line(mlx_image_t* plain);

int32_t main(void)
{
	mlx_t* 			mlx;
	mlx_image_t*	plain;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	image = mlx_new_image(mlx, 80, 80);
	plain = mlx_new_image(mlx, WIDTH, HEIGHT );
	putpixel(WIDTH, HEIGHT / 2, rgbflor, plain, 1);
	putpixel(WIDTH, HEIGHT / 2, rgbceling, plain, 1);
	ft_wallRight(plain);
	ft_wallleft(plain);
	ft_wallback(plain);
	ft_line(plain);
	mlx_image_to_window(mlx, plain, 0, 0);
	mlx_image_to_window(mlx, image, 20, 20);
	mlx_loop_hook(mlx, ft_randomize, (void*)rgb);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

void ft_wallRight(mlx_image_t* plain)
{
	int	rgbwall[4] = {150, 150, 150, 255};
	int color;

	color = ft_pixel(rgbwall[0], rgbwall[1], rgbwall[2], rgbwall[3]);
	for (int i = 0; i < 50; ++i)
	{
		for (int y = 50-i; y < HEIGHT/2 - 50 + i; ++y)
			mlx_put_pixel(plain, (WIDTH - 50) + i, y +100, color);
	}
}

void ft_wallleft(mlx_image_t* plain)
{
	int	rgbwall[4] = {150, 150, 150, 255};
	int color;

	color = ft_pixel(rgbwall[0], rgbwall[1], rgbwall[2], rgbwall[3]);
	for (int i = 0; i < 50 ; i++)
	{
		for (int y = 0 +i; y < HEIGHT/2 - i; y++)
			mlx_put_pixel(plain, i, y +100, color);
	}
}

void ft_wallback(mlx_image_t* plain)
{
	int	rgbwall[4] ={200,200, 100, 255};
	int color;

	color = ft_pixel(rgbwall[0], rgbwall[1], rgbwall[2], rgbwall[3]);
	for (int i = 0; i < WIDTH - 100; ++i)
	{
		for (int y = 0; y < HEIGHT/2 -100; ++y)
			mlx_put_pixel(plain, i + 50, y+150, color);
	}
}

void ft_line(mlx_image_t* plain)
{
	int	rgbwall[4] = {255, 0, 0, 255};
	int color;

	color = ft_pixel(rgbwall[0], rgbwall[1], rgbwall[2], rgbwall[3]);	
	for (int i = 0; i < 90; ++i)
		mlx_put_pixel(plain, i + WIDTH / 2, HEIGHT / 2 + 200 -i, color);
	for (int i = 0; i < 90; ++i)
		mlx_put_pixel(plain, (WIDTH / 2) -i, HEIGHT / 2 + 200 -i, color);
	for (int i = 0; i < 90; ++i)
		mlx_put_pixel(plain, (WIDTH / 2), HEIGHT / 2 + 200 -i, color);
	for (int i = 0; i < pos_x + pos_y; ++i)
		mlx_put_pixel(plain, ((WIDTH / 2) - 135) +i, HEIGHT / 2 + 200, color);

}