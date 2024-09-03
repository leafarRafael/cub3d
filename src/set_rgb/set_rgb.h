/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rgb.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:26:04 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/03 09:38:35 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_RGB_H
# define SET_RGB_H

typedef struct s_data	t_data;

typedef enum s_rgb
{
	R = 0,
	G,
	B,
	A,
}		e_rgb;

int	set_rgb(t_data *data);

#endif
