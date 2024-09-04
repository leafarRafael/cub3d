/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rgb.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:26:04 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/04 11:18:56 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_RGB_H
# define SET_RGB_H

typedef struct s_data	t_data;

enum					e_rgb
{
	R = 0,
	G,
	B,
	A,
};

/**
 * @brief Set rgb color
 * 
 * The function converts the string passed as an argument
 * in the config file into a vector containing an RGB integer.
 * 
 * @param data A pointer to main struct
 * @return int Returns ERROR if an error occurs
 * 			during the conversion; otherwise, returns SUCCESS.
 * - data->args_file[].str:
 * 	A string containing the value taken from the configuration file.
 * 
 * - CEILING, FLOOR:
 * 	There are two macros that define
 *  the args_file index that should be returned.
 *
 * 	- data->rgb_cel and data->rgb_floor:
 * 	Vector of integers to be filled with the converted string values.
 *
 * 	- valid_add_rgb():
 * 	Function validates the formatting of the string,
 *  converts it and fills in the integer vertex.
 */
int	set_rgb(t_data *data);

#endif
