/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 08:10:30 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/23 07:37:33 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

typedef struct s_data	t_data;

typedef struct s_ctrl
{
	int		x;
	int		y;
	char	**map;
}		t_ctrl;

typedef struct s_ctrl_rotate
{
	int		x;
	int		y;
	double	dir;
	double	pla;
}		t_rotate;

int	muve_up(t_data *data);
int	muve_down(t_data *data);
int	muve_left(t_data *data);
int	muve_right(t_data *data);
int	rotate_cam_left(t_data *data);
int	rotate_cam_right(t_data *data);

#endif