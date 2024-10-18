/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:15:00 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/04 15:12:17 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_new_line(char c)
{
	return (c == '\r' || c == '\n' || c == ' ' || c == '\t');
}

int	is_space_tab(int c)
{
	return (c == ' ' || c == '	');
}

int	ft_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	is_coord(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}
