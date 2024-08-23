/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 08:58:23 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/23 10:32:04 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CASTING_H
 #define RAY_CASTING_H

 #include "defines.h"

typedef struct s_ray_casting
{
	int		index;
	int		buffer[HEIGHT];
	double	ray_dir[2];
	double	distance_wall;
	int		column_height;
	int		draw_start;
	int		draw_end;
}		t_ray;

void	ray_casting(t_data *data);

#endif