/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 08:08:52 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/11 15:35:31 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
 #define DATA_H

#include <MLX42.h>

#define mapWidth 24
#define mapHeight 24
#define HEIGHT 880
#define WIDTH 1024
#define Y 0
#define X 1

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	mlx_image_t	*player;
	char 		**worldmap;
	int			multiplier;
	int			rgb_floor[4];
	int			rgb_cel[4];
	int			player_rgb[4];
  	double  	pos[2];
	double		dir[2];
	double		plane[2];
	double		x_plane;
}	t_data;


#endif