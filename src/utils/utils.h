/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:15:00 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/07 09:02:31 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
 #define UTILS_H
#include <../lib/MLX42/include/MLX42/MLX42.h>


void putmsg(char *str);
int ft_pixel(int r, int g, int b, int a);

int putpixel(int height, int width, int rgb[], mlx_image_t* image, int div);

#endif