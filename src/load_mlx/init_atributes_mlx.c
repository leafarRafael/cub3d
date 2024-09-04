/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_atributes_mlx.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:16:22 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/04 14:45:20 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "data.h"
#include "defines.h"

static int	loadpng(mlx_texture_t **wall, char *path_to_png);

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
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	if (!data->window.image)
		return (ERROR);
	if (!data->window.mlx)
		return (ERROR);
	return (SUCCESS);
}

/**
 * @brief Loads a PNG texture into the provided MLX texture pointer.
 * 
 * @param wall A pointer to a mlx_texture_t structure
 *             where the texture will be loaded.
 * 
 * @param path_to_png Path to the PNG image file.
 * 
 * @return int ERROR if loading fails or if path_to_png is NULL,
 *         otherwise returns SUCCESS.
 * 
 * Function overview:
 * - If path_to_png is valid, the function loads the
 *   texture into the wall pointer using mlx_load_png.
 *
 * - The function then checks if the loading was
 *   successful and returns the appropriate status.
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
