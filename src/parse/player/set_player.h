/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:44:06 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/04 11:56:11 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_PLAYER_H
# define SET_PLAYER_H

typedef struct s_data	t_data;

/**
 * @brief Initializes player coordinates
 * 		  and updates the game data structure.
 * 
 * This function sets the initial player position,
 * direction, and calculates the camera plane vector
 * based on predefined values. It also updates the main game
 * data structure to include the initialized player coordinates.
 * 
 * @param coord A pointer to the player structure (t_coord) that contains:
 * - pos[2] for storing the player's X and Y coordinates.
 * - dir[2] for storing the direction the player is looking.
 * - plane[2] for calculating the rotation of the camera plane.
 * 	
 * @param data A pointer to the main game data structure (t_data) that holds:
 *  Coordinates, maps, textures, and other game-related data.
 *  The coord field of this structure is updated to point to the coord parameter.
 */
void					set_player(t_data *data);

#endif