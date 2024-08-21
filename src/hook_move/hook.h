/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:51:50 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/21 13:49:36 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

/**
 * @brief Handles user input and updates the game state accordingly.
 * 
 * This function monitors user input via the keyboard and adjusts the game state,
 * including the player's position, camera rotation, and screen rendering.
 * Depending on the keys pressed, the player can move, rotate the camera,
 * or close the game.
 * 
 * @param param A generic pointer (void*), 
 * which in this context is a pointer to the main game structure (`t_data`). 
 * This structure contains the player's coordinates, 
 * map data, graphical library structures, 
 * and other essential game elements.
 * 
 * @details The function performs the following actions:
 *  - MLX_KEY_ESCAPE: Closes the game window.
 *  - MLX_KEY_LEFT: Rotates the camera to the left.
 *  - MLX_KEY_RIGHT: Rotates the camera to the right.
 *  - MLX_KEY_A: Moves the player to the left.
 *  - MLX_KEY_D: Moves the player to the right.
 *  - MLX_KEY_S: Move the player backwards.
 *  - MLX_KEY_W: Move the player forward.
 * 
 * After updating the player's coordinates and camera rotation,
 * the function calls:
 *  - render_ceiling_floor(data):
 * Renders the ceiling and floor based on the updated data.
 * 	- ray_casting(data):
 * Performs raycasting to render the game image with the new data.
 */
void	ft_hook(void *param);

#endif