/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:42:02 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/02 12:05:57 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "data.h"
#include <stdlib.h>
#include "utils.h"
#include "matrix_lst.h"

int	error_handler(char *s1, char *s2, char *s3, char *s4)
{
	ft_putstr_fd("ERROR:\n", 2);
	if (s1)
		ft_putstr_fd(s1, 2);
	if (s2)
		ft_putstr_fd(s2, 2);
	if (s3)
		ft_putstr_fd(s3, 2);
	if (s4)
		ft_putstr_fd(s4, 2);
	return (0);
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
