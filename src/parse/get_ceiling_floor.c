/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ceiling_floor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:07:41 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/27 18:19:23 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_lst.h"
#include "utils.h"
#include "error.h"
#include "defines.h"
#include "data.h"
#include "get_ceiling_floor.h"
#include <stdlib.h>
#include <libft.h>
#include <stdio.h>

static char	*get_color(t_mlst *mlst, char *coord);
static int	valid_is_numeric(char **matrix);
static int	convert_to_integer(char *color, int rgba[4]);

int	get_ceiling_floor(t_mlst *mlst, t_data *data)
{
	data->ceiling = get_color(mlst, C);
	if (!data->ceiling)
		return (1);
	if (convert_to_integer(data->ceiling, data->rgb_cel))
		return (1);
	data->floor =  get_color(mlst, F);
	if (!data->floor)
		return (1);
	if (convert_to_integer(data->floor, data->rgb_floor))
		return (1);
	return (0);	
}

static char	*get_color(t_mlst *mlst, char *coord)
{
	t_llst	*llst;
	char	*path;

	if (!mlst)
		return (NULL);
	llst = find_str_in_matrix(mlst, coord);
	if (!llst)
		return (NULL);
	lst_rmv_front(llst->lst);
	lst_rmv_front(llst->lst);
	while (llst->lst->size && is_space(llst->lst->head->c))
		lst_rmv_front(llst->lst);
	while (llst->lst->size && is_space(llst->lst->last->c))
		lst_rmv_back(llst->lst);
	path = ft_cpy_lst_to_array(llst->lst);
	ft_rmv_spcfc_lst_mtrx(mlst, llst);
	llst = find_str_in_matrix(mlst, coord);
	if (llst != NULL)
	{
		ft_delete_matrix(mlst);
		return (NULL);
	}
	if (!path)
		return (NULL);
	return (path);
}

static int	convert_to_integer(char *color, int rgba[4])
{
	char	**rgb;

	if (!color)
		return (1);
	rgb = ft_split(color, ',');
	if (!rgb)
		return (ft_delcmtrx(rgb) + 1);
	if (valid_is_numeric(rgb))
		return (ft_delcmtrx(rgb) + 1);
	rgba[R] = ft_atoi(rgb[R]);
	if (rgba[R] < 0 || rgba[R] > 255)
		return (ft_delcmtrx(rgb) + 1);
	rgba[G] = ft_atoi(rgb[G]);
	if (rgba[G] < 0 || rgba[G] > 255)
		return (ft_delcmtrx(rgb) + 1);
	rgba[B] = ft_atoi(rgb[B]);
	if (rgba[B] < 0 || rgba[B] > 255)
		return (ft_delcmtrx(rgb) + 1);
	rgba[A] = 255;
	ft_delcmtrx(rgb);
	return (0);
}

static int valid_is_numeric(char **matrix)
{
	int	y;
	int	x;

	if (!matrix)
		return (1);
	y = 0;
	while(matrix[y])
	{
		x = 0;
		while (matrix[y][x])
		{
			if (!ft_isdigit(matrix[y][x]))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}