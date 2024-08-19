/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:57:09 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/19 15:06:49 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORDINATES_H
 #define COORDINATES_H

typedef struct s_player t_plr;
typedef struct s_data t_data;

/**
 * @brief Set the initial coordinates object
 * 
 * @param coord 
 * @param data 
 */

void set_initial_coordinates(t_plr *coord, t_data *data);

#endif