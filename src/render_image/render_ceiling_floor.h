/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ceiling_floor.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:34:59 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/04 11:26:30 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_CEILING_FLOOR_H
# define RENDER_CEILING_FLOOR_H

typedef struct s_data	t_data;

/**
 * @brief Draw the ceiling and floor colors on the image.
 * 
 * This function fills the image buffer with the colors for the
 * ceiling and floor by dividing the screen into two sections.
 * The ceiling color is drawn on the upper half,
 * and the floor color is drawn on the lower half. The function uses the 
 * defined color values from the data structure to fill these areas.
 * 
 @param data A pointer to the main game data structure (t_data) that holds:
 *   rgb_cel: An array containing the RGBA values for the ceiling color.
 *   rgb_floor: An array containing the RGBA values for the floor color.
 *   window.image: The image buffer where the pixels will be drawn.
 */
int	render_ceiling_floor(t_data *data);

#endif