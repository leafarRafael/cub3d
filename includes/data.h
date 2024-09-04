/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 08:08:52 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/04 11:08:52 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
 #define DATA_H

#include <MLX42.h>

typedef struct s_matrix_list t_mlst;

typedef enum s_texture
{
	NORTH = 0,
	SOUTH,
	WEST,
	EAST,
	FLOOR,
	CEILING,
}			t_texture_index;

typedef	struct s_components_mlx
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	mlx_texture_t	*wall[4];
}		t_comp_mlx;

typedef struct s_coordinates
{
	double	pos[2];
	double	dir[2];
	double	plane[2];
}	t_coord;

typedef struct s_atributes
{
	char	*str;
	int		status;
}		t_atr;

typedef struct s_data
{
	t_mlst		*mlst;
	t_comp_mlx	window;
	t_atr		args_file[6];
	t_coord		*coord;
	char 		**worldmap;
	char		identifier;
	int			rgb_floor[4];
	int			rgb_cel[4];
	int			atr;
}	t_data;

/**
 * @brief Retrieves the main data structure for the program.
 * 
 * This function returns a pointer to the
 * main structure (`t_data`) of the program.
 * The structure is instantiated only once using the singleton pattern,
 * ensuring that there is a single instance throughout the program's execution.
 * 
 * @return t_data* A pointer to the main game data structure.
 * 
 * Function overview:
 * - `t_data` is a structure containing all elements required to run the program.
 *   Only one instance of this structure should exist,
 *   hence the application of the singleton pattern.
 * 
 * - If the structure has not been instantiated,
 *   the initialization function (`initialize_data`) 
 *   is called to create and return the pointer.
 *   If already instantiated, the existing pointer is returned.
 */
t_data	*get_data(void);

#endif