/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:25:16 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/03 15:24:44 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "defines.h"
#include "libft.h"
#include "set_rgb.h"

static int	valid_add_rgb(char *color, int rgb[4]);
static int	valid_value(int c);
static int	valid_color(char *color);
static int	check_rgb_length(char **color);
/**
 * @brief Set rgb color
 * 
 * The function converts the string passed as an argument
 * in the config file into a vector containing an RGB integer.
 * 
 * @param data A pointer to main struct
 * @return int Returns `ERROR` if an error occurs during the conversion; otherwise, returns `SUCCESS`.
 * 
 * 	- data->args_file[].str:
 * 		A string containing the value taken from the configuration file.
 * 	- CEILING, FLOOR:
 * 		There are two macros that define the args_file index that should be returned.
 * 	- data->rgb_cel and data->rgb_floor:
 * 		Vector of integers to be filled with the converted string values.
 * 	- valid_add_rgb():
 * 		Function validates the formatting of the string, converts it and fills in the integer vertex.  	
 */
int	set_rgb(t_data *data)
{
	if (valid_add_rgb(data->args_file[CEILING].str, data->rgb_cel))
		return  (ERROR);
	if (valid_add_rgb(data->args_file[FLOOR].str, data->rgb_floor))
		return  (ERROR);
	return (SUCCESS);
}

/**
 * @brief Validates, converts and assigns
 * 
 * The function checks the formatting of the string passed as a parameter.
 * It converts it to integer values and assigns it to the vector passed as a parameter.
 * 
 * @param color A string containing the color data separated into R, G and B.
 * @param rgb The integer vertex that will receive the values of the converted string.
 * @return int  Returns `ERROR` if an error occurs during the conversion; otherwise, returns `SUCCESS`.
 * 
 * Function overview:
 *	- valid_color():
 *		Checks that the string has only the expected elements (commas and numerics)
 * 	- ft_split():
 * 		Separates each element into an indece of a matrix.
 *  - ft_mtrxlen():
 * 		Counts the number of elements in the matrix. We expect 3 elements (R, G and B).
 * 	- check_rgb_length():
 *		Checks the length of each index in the matrix.
 *      We expect a maximum of 3 elements per index (0 to 255).
 * 	- ft_atoi():
 * 		Converts the string into an integer.
 * 	- valid_value(rgb[R]):
 * 		Checks that the converted values are between 0 and 255 per RGB element.
 * 	- ft_delcmtrx():
 * 		After the conversion and in case of error, frees the allocated memory.
 */
static int	valid_add_rgb(char *color, int rgb[4])
{
	char	**m_color;

	if (valid_color(color))
		return (ERROR);
	m_color = ft_split(color, ',');
	if (!m_color && ft_mtrxlen(m_color) != 3)
		return (ft_delcmtrx(m_color) + ERROR);
	if (check_rgb_length(m_color))
		return (ft_delcmtrx(m_color) + ERROR);
	rgb[R] = ft_atoi(m_color[R]);
	rgb[G] = ft_atoi(m_color[G]);
	rgb[B] = ft_atoi(m_color[B]);
	rgb[A] = 255;
	if (valid_value(rgb[R]))
		return (ft_delcmtrx(m_color) + ERROR);
	if (valid_value(rgb[G]))
		return (ft_delcmtrx(m_color) + ERROR);
	if (valid_value(rgb[B]))
		return (ft_delcmtrx(m_color) + ERROR);
	ft_delcmtrx(m_color);
	return (SUCCESS);
}

/**
 * @brief Validates that the color string has the expected elements.
 * 
 * Checks if the color string has only numeric elements and a comma for separation.
 * 
 * @param color A string containing the color data separated into R, G and B.
 * @return ERROR if it finds any character outside the specification, otherwise SUCCESS.
 * 
 */
static int	valid_color(char *color)
{
	int	i;
	int	v;

	i = 0;
	v = 0;
	while (color[i])
	{
		if((color[i] != ',' && !ft_isdigit(color[i])))
			return (ERROR);
		if (color[i] == ',')
			v++;
		i++;
	}
	if (v != 2)
		return (ERROR);
	return (SUCCESS);
}

/**
 * @brief Check the length of each index in the color matrix.
 * 
 * The function goes through each element of the matrix,
 * checking if the length is between 0 and 3 elements.
 * 
 * @param color A matrix 2D.
 * @return int ERROR if the length is not between 0 and 3, otherwise SUCCESS.
 */
static int	check_rgb_length(char	**color)
{
	int	i;
	int	len;

	if (!color)
		return (ERROR);
	i = 0;
	len = 0;
	while (color[i])
	{
		len = ft_strlen(color[i]);
		if (len <= 0 || len > 3) 
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

static int	valid_value(int c)
{
	return (c < 0 || c > 255);
}