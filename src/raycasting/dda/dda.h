/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 08:54:40 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/22 10:06:11 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_H
 #define DDA_H
#define COLLIDED 1
#define DID_NOT_COLLIDE 0
#define EMPTY_SPACE '0'


typedef struct s_data t_data;
typedef struct s_ray_casting t_ray;

typedef enum s_side
{
	NORTH_UP = -1,
	SOUTH_DOWN = 1,
	WEST_LEFT = -1,
	EAST_RIGHT = 1,
}			t_side;

typedef struct s_dda
{
	int		hit;
	int		side;
	int		step[2];
	int		map[2];
	double	side_dist[2];
	double	delta_dist[2];
}		t_dda;

void	ft_dda(t_data *data, t_ray *ray, t_dda *dda);
void	side(t_data *data, t_dda *dda, t_ray *ray);
void	find_collision(t_data *data, t_dda *dda, t_ray *ray);

#endif