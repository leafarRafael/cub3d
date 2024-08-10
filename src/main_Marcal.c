/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_Marcal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 07:48:30 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/09 15:15:29 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	{1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
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