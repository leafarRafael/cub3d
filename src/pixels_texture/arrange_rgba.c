/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_rgba.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 08:45:17 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/04 11:24:30 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	arrange_color(unsigned int argb)
{
	unsigned int	blue;
	unsigned int	green;
	unsigned int	red;
	unsigned int	alpha;

	blue = (argb & 0xFF) << 24;
	green = (argb & 0xFF00) << 8;
	red = (argb & 0xFF0000) >> 8;
	alpha = (argb & 0xFF000000) >> 24;
	return (blue | green | red | alpha);
}
