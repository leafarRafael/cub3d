/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:49:50 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/03 12:45:40 by myokogaw         ###   ########.fr       */
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

t_data	*parse(int argc, char **argv)
{
	t_data	*data;

	if (valid_arguments(argc, argv))
		exit(error_handler(E_ARGUMENTS));
	data = get_data();
	data->mlst = read_file(argv[1]);
	if (!data->mlst)
		exit(error_handler(E_MEMORY));
	if (data->mlst->size <= 8)
		exit(error_handler(E_READ));
	if (get_attr(data->mlst, data))
		exit(error_handler(E_IDENTIFIER));
	if (is_valid_map(data->mlst))
		exit(error_handler(E_MAP));
	normalize(data->mlst);
	data->worldmap = ft_cpy_mtrllst_to_cmtrx(data->mlst);
	if (!data->worldmap)
		exit(error_handler(E_MEMORY));
	set_player(data);
	if (flood_fill_valid(data, data->mlst))
		exit(error_handler(E_MAP));
	return (data);
}
