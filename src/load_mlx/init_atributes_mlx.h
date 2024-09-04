/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_atributes_mlx.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:20:20 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/04 11:10:00 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_ATRIBUTES_MLX_H
# define INIT_ATRIBUTES_MLX_H

typedef struct s_data	t_data;

/**
 * @brief Initializes the structures of the MLXCodan graphics library.
 * 
 * This function initializes the
 * structures corresponding to the window, 
 * the images that will be rendered,
 * and the loading of textures for the game.
 * 
 * @param data A pointer to the main game data structure (t_data).
 * 
 * @return int ERROR if an error occurs
 * 		   during initialization, otherwise SUCCESS.
 * 
 * Function overview:
 * - The function instantiates the following MLX structures:
 * - data->window.wall[] (NORTH, SOUTH, WEST, EAST): 
 *   Pointers to mlx_texture_t, where the game textures are loaded.
 * - data->args_file[].str (NORTH, SOUTH, WEST, EAST):
 *   Strings containing the path to the PNG images to be loaded.
 * - data->window.mlx: 
 *   A pointer to the mlx_t structure, which contains data about the window.
 * - data->window.image: 
 *   A pointer to the mlx_image_t structure, which holds data about the image 
 *   that will be rendered later.
 * - The function initializes these structures
 *  by calling appropriate functions from the MLXCodan graphics library.
 *  If any error occurs, the function returns ERROR.
 */
int	init_atributes_mlx(t_data *data);

#endif