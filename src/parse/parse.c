/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:49:50 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/02 15:28:50 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "data.h"
#include <MLX42.h>
#include "defines.h"
#include "parse.h"
#include "matrix_lst.h"
#include "get_attr.h"
#include "is_valid_map.h"
#include "normalize_map.h"
#include "set_player.h"
#include "flood_fill.h"
#include "error_handler.h"
#include "valid_arguments.h"
#include "read_file.h"
#include "set_rgb.h"

t_data *parse(int argc, char **argv)
{
	static t_data	data;
	static t_coord	coord;

	valid_arguments(argc, argv);
	data.mlst = read_file(argv[1]);
	if (data.mlst->size <= 8)
		exit(error_handler(E_F_R_F, 0, 0, 0) + 1);
	get_attr(data.mlst, &data);
	if (is_valid_map(data.mlst))
		exit(destroy_data(&data) + error_handler(E_MAP, 0, 0, 0) + 1);
	normalize(data.mlst);
	data.worldmap = ft_cpy_mtrllst_to_cmtrx(data.mlst);
	set_player(&data, &coord);
	if (flood_fill_valid(&data, data.mlst))
		exit(destroy_data(&data) + error_handler(E_MAP, 0, 0, 0) + 1);
	if (set_rgb(&data))
		exit(destroy_data(&data) + error_handler("INVALID COLOR\n", 0, 0, 0) + 1);
	return (&data);
}
