/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 08:08:52 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/13 09:38:50 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
 #define DATA_H

#include <MLX42.h>

#define mapWidth 24
#define mapHeight 24
#define HEIGHT 880
#define WIDTH 1024

typedef enum cord
{
	Y = 0,
	X
}		t_cord;

typedef enum s_time
{
	CURRENT = 0,
	OLD_TIME
}		t_time;

typedef	struct s_components_mlx
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	mlx_image_t		*player;
	mlx_texture_t	*wall[4];
}		t_comp_mlx;

typedef struct s_player
{
	double	pos[2];
	double	dir[2];
	double	plaine[2];
	double	time[2];
}	t_plr;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	mlx_image_t	*player;
	t_comp_mlx	window;
	t_plr		coord;
	char 		**worldmap;
	int			rgb_floor[4];
	int			rgb_cel[4];
	int			player_rgb[4];
}	t_data;

#endif