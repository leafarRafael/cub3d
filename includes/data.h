/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 08:08:52 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/27 17:35:18 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
 #define DATA_H

#include <MLX42.h>

typedef enum s_texture
{
	NORTH = 0,
	SOUTH,
	WEST,
	EAST,
}			t_texture_index;

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
	double	plane[2];
}	t_plr;

typedef struct s_data
{
	char 		**worldmap;
	char		*path_text[5];
	char		*floor;
	char		*ceiling;
	int			rgb_floor[4];
	int			rgb_cel[4];
	int			player_rgb[4];
	t_plr		*coord;
	t_comp_mlx	window;
}	t_data;


#endif