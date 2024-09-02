/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:49:50 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/02 16:28:34 by rbutzke          ###   ########.fr       */
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

	if (valid_arguments(argc, argv))
		exit(error_handler(E_ARGS, 0, 0, 0) + 1);
	data.mlst = read_file(argv[1]);
	if (!data.mlst)
		exit(error_handler(E_MEM, 0, 0, 0) + 1);
	if (data.mlst->size <= 8)
		exit(error_handler(E_F_R_F, 0, 0, 0) + 1);
	if (get_attr(data.mlst, &data))
		exit(error_handler(E_INDEN, 0, 0, 0) + destroy_data(&data) +1);
	if (is_valid_map(data.mlst))
		exit(destroy_data(&data) + error_handler(E_MAP, 0, 0, 0) + 1);
	normalize(data.mlst);
	data.worldmap = ft_cpy_mtrllst_to_cmtrx(data.mlst);
	if (!data.worldmap)
		exit(error_handler(E_MEM, 0, 0, 0) + 1);
	set_player(&data, &coord);
	if (flood_fill_valid(&data, data.mlst))
		exit(destroy_data(&data) + error_handler(E_MAP, 0, 0, 0) + 1);
	if (set_rgb(&data))
		exit(destroy_data(&data) + error_handler(E_COLOR, 0, 0, 0) + 1);
	return (&data);
}
