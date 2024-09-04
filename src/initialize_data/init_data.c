/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 08:41:57 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/04 14:44:57 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

static t_data	*initialize_data(void);

t_data	*get_data(void)
{
	static t_data	*data = NULL;

	if (!data)
		data = initialize_data();
	return (data);
}

/**
 * @brief Initializes the program's main data structure.
 * 
 * This function initializes the `t_data` structure and sets up the necessary 
 * substructures, such as `t_coord`. It ensures that the main data structure 
 * is properly configured before being used by the program.
 * 
 * @return t_data* A pointer to the initialized game data structure (`t_data`).
 */
static t_data	*initialize_data(void)
{
	static t_data	data;
	static t_coord	coord;

	data.coord = &coord;
	return (&data);
}
