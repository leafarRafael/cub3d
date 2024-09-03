/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:42:02 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/03 09:11:26 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "data.h"
#include <stdlib.h>
#include "utils.h"
#include "matrix_lst.h"
#include "error_handler.h"
#include <string.h>
#include <errno.h>

const char	*error_msg(int e_error);

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
	ft_putstr_fd((char*)error_msg(e_error), 2);
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
	if (data->window.wall[NORTH])
		mlx_delete_texture(data->window.wall[NORTH]);
	if(data->window.wall[SOUTH])
		mlx_delete_texture(data->window.wall[SOUTH]);
	if(data->window.wall[WEST])
		mlx_delete_texture(data->window.wall[WEST]);
	if (data->window.wall[EAST])
		mlx_delete_texture(data->window.wall[EAST]);
	if (data->window.image)
		mlx_delete_image(data->window.mlx, data->window.image);
	if (data->window.mlx)
		mlx_terminate(data->window.mlx);
	if (data->mlst)
		ft_delete_matrix(data->mlst);
	return (0);
}

const char	*error_msg(int e_error)
{
	const char	*error[] = {"",
	E_ARGS, 
	E_MEM,
	E_F_R_F,
	E_INDEN,
	E_INVALID_MAP,
	E_RGB, 
	E_INVALID_MAP,
	E_MLX
	};
	return (error[e_error]);
}
