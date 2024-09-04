/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:42:02 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/04 11:08:00 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "error_handler.h"
#include "libft.h"
#include "matrix_lst.h"
#include "utils.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>

static const char	*error_msg(int index_msg);

int	error_handler(int e_error)
{
	if (e_error == 0)
		return (0);
	ft_putstr_fd("ERROR:\n", 2);
	if (errno)
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		destroy_data(get_data());
		return (errno);
	}
	ft_putstr_fd((char *)error_msg(e_error), 2);
	destroy_data(get_data());
	return (e_error);
}

int	destroy_data(t_data *data)
{
	ft_free(data->args_file[NORTH].str);
	ft_free(data->args_file[SOUTH].str);
	ft_free(data->args_file[WEST].str);
	ft_free(data->args_file[EAST].str);
	ft_free(data->args_file[FLOOR].str);
	ft_free(data->args_file[CEILING].str);
	if (data->worldmap)
		ft_delcmtrx(data->worldmap);
	if (data->mlst)
		ft_delete_matrix(data->mlst);
	if (data->window.wall[NORTH])
		mlx_delete_texture(data->window.wall[NORTH]);
	if (data->window.wall[SOUTH])
		mlx_delete_texture(data->window.wall[SOUTH]);
	if (data->window.wall[WEST])
		mlx_delete_texture(data->window.wall[WEST]);
	if (data->window.wall[EAST])
		mlx_delete_texture(data->window.wall[EAST]);
	if (data->window.image)
		mlx_delete_image(data->window.mlx, data->window.image);
	if (data->window.mlx)
		mlx_terminate(data->window.mlx);
	return (0);
}

/**
 * @brief Function return a string corresponding to the index.
 *
 * The function instantiates a constant matrix of strings
 * and returns the one that matches the index passed as an argument.
 *
 * @param index_msg The index of the string to be returned.
 *
 * @return const char* The string corresponding.
 *
 * Function overview:
 * - The function instantiates a constant array of strings, where each index
 *   corresponds to a string defined by a macro (e.g., E_ARGS, E_MEM).
 * - It returns the string corresponding to the given index.
 * - If the index is greater than the number of available messages (`NBR_MSG`),
 *   the function returns NULL.
 */
static const char	*error_msg(int index_msg)
{
	const char	*msg[] = {"", E_ARGS, E_MEM, E_F_R_F, E_INDEN, E_INVALID_MAP,
		E_RGB, E_INVALID_MAP, E_MLX};

	if (index_msg > NBR_MSG)
		return (NULL);
	return (msg[index_msg]);
}
