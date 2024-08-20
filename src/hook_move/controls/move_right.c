/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 08:10:30 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/20 09:46:02 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "defines.h"
#include <math.h>
#include "controls.h"

static void	muve_axis_y(t_data *data);
static void	muve_axis_x(t_data *data);

void	muve_right(t_data *data)
{
	muve_axis_x(data);
	muve_axis_y(data);
}

static void	muve_axis_y(t_data *data)
{
	t_ctrl	c;

	c.x = (int)(data->coord->pos[X]);
	c.y = (int)(data->coord->pos[Y] + data->coord->plane[Y] * MOVE_SPPED);
	c.map = data->worldmap;
	if (c.map[c.y][c.x] == '0')
		data->coord->pos[Y] += data->coord->plane[Y] * MOVE_SPPED;
}

static void	muve_axis_x(t_data *data)
{
	t_ctrl	c;

	c.x = (int)(data->coord->pos[X] + data->coord->plane[X] * MOVE_SPPED);
	c.y = (int)data->coord->pos[Y];
	c.map = data->worldmap;
	if (c.map[c.y][c.x] == '0')
		data->coord->pos[X] += data->coord->plane[X] * MOVE_SPPED;
}
