/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_rgba.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 08:45:17 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/23 08:45:59 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	rearrange_color(unsigned int argb)
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
