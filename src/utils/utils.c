/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:15:00 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/17 10:21:24 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>
#include <../lib/MLX42/include/MLX42/MLX42.h>

int ft_color(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

int 	error_handler(char *s1, char *s2, char *s3, char *s4)
{
	if (s1)
		printf("%s", s1);
	if (s2)
		printf("%s", s2);
	if (s3)
		printf("%s", s3);
	if (s4)
		printf("%s", s4);
	return (1);
}
