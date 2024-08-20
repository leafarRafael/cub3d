/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cam_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 08:10:30 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/20 10:41:47 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42.h>
#include "data.h"
#include "defines.h"
#include <math.h>

static void	rotate_dir(t_data *data);
static void	rotate_plane(t_data *data);

void	rotate_cam_right(t_data *data)
{
	rotate_dir(data);
	rotate_plane(data);
}

static void	rotate_dir(t_data *data)
{
	double	dir;
	double	diry_cos;
	double	dirx_cos;
	double	dirx_sin;

	dir = data->coord->dir[Y];
	diry_cos = data->coord->dir[Y] * cos(-ROT_SPEED);
	dirx_sin = data->coord->dir[X] * sin(-ROT_SPEED);
	data->coord->dir[Y] = diry_cos - dirx_sin;
	dirx_sin = dir * sin(-ROT_SPEED);
	dirx_cos = data->coord->dir[X] * cos(-ROT_SPEED);
	data->coord->dir[X] = dirx_sin + dirx_cos;
}

static void	rotate_plane(t_data *data)
{
	double	pl;
	double	plny_cos;
	double	plnx_cos;
	double	plnx_sin;

	pl = data->coord->plane[Y];
	plny_cos = data->coord->plane[Y] * cos(-ROT_SPEED);
	plnx_sin = data->coord->plane[X] * sin(-ROT_SPEED);
	data->coord->plane[Y] = plny_cos - plnx_sin;
	plnx_cos = data->coord->plane[X] * cos(-ROT_SPEED);
	data->coord->plane[X] = pl * sin(-ROT_SPEED) + plnx_cos;
}
