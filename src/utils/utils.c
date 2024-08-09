/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:15:00 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/08 15:50:00 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

#include <../lib/MLX42/include/MLX42/MLX42.h>

void putmsg(char *str)
{
	printf("%s\n", str);	
}


int ft_pixel(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

int putpixel(int height, int width, int rgb[], mlx_image_t* image, int div)
{
	int color;

	color = ft_pixel(rgb[0], rgb[1], rgb[2], rgb[3]);
	for (int i = 0; i < height / div; ++i)
	{
		for (int y = 0; y < width / div; ++y)
			mlx_put_pixel(image, height + i, y, color);
	}
	return (0);
}