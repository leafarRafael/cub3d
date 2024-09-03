/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_atributes_mlx.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:16:22 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/03 15:23:14 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42.h>
#include "data.h"
#include "defines.h"

#include <stdlib.h>


static int	loadpng(mlx_texture_t **wall, char *path_to_png);

/**
 * @brief Initializes the structures of the MLXCodan graphics library.
 * 
 * This function initializes the structures corresponding to the window, 
 * the images that will be rendered, and the loading of textures for the game.
 * 
 * @param data A pointer to the main game data structure (`t_data`).
 * 
 * @return int Returns `ERROR` if an error occurs during initialization, otherwise `SUCCESS`.
 * 
 * Function overview:
 * - The function instantiates the following MLX structures:
 *   - `data->window.wall[]` (NORTH, SOUTH, WEST, EAST): 
 *     Pointers to `mlx_texture_t`, where the game textures are loaded.
 *   - `data->args_file[].str` (NORTH, SOUTH, WEST, EAST):
 *     Strings containing the path to the PNG images to be loaded.
 *   - `data->window.mlx`: 
 *     A pointer to the `mlx_t` structure, which contains data about the window.
 *   - `data->window.image`: 
 *     A pointer to the `mlx_image_t` structure, which holds data about the image 
 *     that will be rendered later.
 * - The function initializes these structures by calling appropriate functions from 
 *   the MLXCodan graphics library. If any error occurs, the function returns `ERROR`.
 */
int	init_atributes_mlx(t_data *data)
{
	if (loadpng(&data->window.wall[NORTH], data->args_file[NORTH].str) == ERROR)
		return (ERROR);
	if (loadpng(&data->window.wall[SOUTH], data->args_file[SOUTH].str) == ERROR)
		return (ERROR);
	if (loadpng(&data->window.wall[WEST], data->args_file[WEST].str) == ERROR)
		return (ERROR);
	if (loadpng(&data->window.wall[EAST], data->args_file[EAST].str) == ERROR)
		return (ERROR);
	data->window.mlx = mlx_init(WIDTH, HEIGHT, GAME, true);
	data->window.image = mlx_new_image(data->window.mlx, WIDTH, HEIGHT);
	if (!data->window.image)
		return (ERROR);
	if (!data->window.mlx)
		return (ERROR);
	return (SUCCESS);
}

/**
 * @brief Loads a PNG texture into the provided MLX texture pointer.
 * 
 * @param wall A pointer to a `mlx_texture_t` structure where the texture will be loaded.
 * @param path_to_png Path to the PNG image file.
 * 
 * @return int Returns `ERROR` if loading fails or if `path_to_png` is NULL, otherwise returns `SUCCESS`.
 * 
 * Function overview:
 * - If `path_to_png` is valid, the function loads the texture into the `wall` pointer using `mlx_load_png`.
 * - The function then checks if the loading was successful and returns the appropriate status.
 */
static int	loadpng(mlx_texture_t **wall, char *path_to_png)
{
	if (!path_to_png)
		return (ERROR);
	(*wall) = mlx_load_png(path_to_png);
	if (!(*wall))
		return (ERROR);
	return (SUCCESS);
}
