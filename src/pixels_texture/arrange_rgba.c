/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_rgba.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 08:45:17 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/23 10:27:19 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Arranges the color components of an ARGB value.
 * 
 * This function takes a 32-bit unsigned integer representing a color 
 * in ARGB format and arranges the components into a new order: 
 * Blue, Green, Red, Alpha. 
 * 
 * @param argb The input color value in ARGB.
 * @return unsigned int The arranged color value with the order BGRA.
 */

unsigned int	arrange_color(unsigned int argb)
{
	unsigned int	blue;
	unsigned int	green;
	unsigned int	red;
	unsigned int	alpha;

	blue = (argb & 0xFF) << 24;
	green = (argb & 0xFF00) << 8;
	red = (argb & 0xFF0000) >> 8;
	alpha = (argb & 0xFF000000) >> 24;
	return (blue | green | red | alpha);
}
