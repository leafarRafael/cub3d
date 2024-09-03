/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 08:41:57 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/03 11:48:17 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include <stdio.h>

static t_data	*initialize_data(void);

/**
 * @brief Retrieves the main data structure for the program.
 * 
 * This function returns a pointer to the main structure (`t_data`) of the program.
 * The structure is instantiated only once using the singleton pattern, ensuring that 
 * there is a single instance throughout the program's execution.
 * 
 * @return t_data* A pointer to the main game data structure.
 * 
 * Function overview:
 * - `t_data` is a structure containing all elements required to run the program.
 *   Only one instance of this structure should exist, hence the application of the singleton pattern.
 * - If the structure has not been instantiated, the initialization function (`initialize_data`) 
 *   is called to create and return the pointer. If already instantiated, the existing pointer is returned.
 */
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
