/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:25:16 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/02 15:41:21 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "defines.h"
#include "libft.h"

static int	valid_add_rgb(char *color, int rgb[4]);

int	set_rgb(t_data *data)
{
	if (valid_add_rgb(data->args_file[CEILING].str, data->rgb_cel))
		return  (ERROR);
	if (valid_add_rgb(data->args_file[FLOOR].str, data->rgb_floor))
		return  (ERROR);
	return (0);
}

static int	valid_value(int c);
static int	valid_color(char *color);
static int	valid_size(char	**color);

static int	valid_add_rgb(char *color, int rgb[4])
{
	char	**m_color;

	if (valid_color(color))
		return (ERROR);
	m_color = ft_split(color, ',');
	if (ft_mtrxlen(m_color) != 3)
		return (ft_delcmtrx(m_color) + ERROR);
	if (valid_size(m_color))
		return (ft_delcmtrx(m_color) + ERROR);
	rgb[R] = ft_atoi(m_color[R]);
	rgb[G] = ft_atoi(m_color[G]);
	rgb[B] = ft_atoi(m_color[B]);
	rgb[A] = 255;
	if (valid_value(rgb[R]))
		return (ft_delcmtrx(m_color) + ERROR);
	if (valid_value(rgb[G]))
		return (ft_delcmtrx(m_color) + ERROR);
	if (valid_value(rgb[B]))
		return (ft_delcmtrx(m_color) + ERROR);
	ft_delcmtrx(m_color);
	return (0);
}

static int	valid_color(char *color)
{
	int	i;
	int	v;

	i = 0;
	v = 0;
	while (color[i])
	{
		if((color[i] != ',' && !ft_isdigit(color[i])))
			return (ERROR);
		if (color[i] == ',')
			v++;
		i++;
	}
	if (v != 2)
		return (ERROR);
	return (0);
}

static int	valid_size(char	**color)
{
	int	i;
	int	len;

	if (!color)
		return (ERROR);
	i = 0;
	len = 0;
	while (color[i])
	{
		len = ft_strlen(color[i]);
		if (len <= 0 || len > 3) 
			return (ERROR);
		i++;
	}
	return (0);
}

static int	valid_value(int c)
{
	return (c < 0 || c > 255);
}