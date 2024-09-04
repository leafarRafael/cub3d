/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture_image.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:03:57 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/04 11:28:24 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "ray_casting.h"
#include "defines.h"

void	render_texture_on_image(t_data *data,
		t_ray *ray, int bufercolor[HEIGHT])
{
	while (ray->draw_start < ray->draw_end)
	{
		mlx_put_pixel(data->window.image, ray->index,
			ray->draw_start, bufercolor[ray->draw_start]);
		ray->draw_start++;
	}
}
