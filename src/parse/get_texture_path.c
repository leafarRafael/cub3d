/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:07:41 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/27 18:09:44 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_lst.h"
#include "utils.h"
#include "error.h"
#include "defines.h"
#include "data.h"
#include "get_texture_path.h"
#include <stdlib.h>
#include <libft.h>
#include <stdio.h>

static char	*get_path_text(t_mlst *mlst, char *coord);

int	get_texture_in_file(t_mlst *mlst, t_data *data)
{
	data->path_text[NORTH] = get_path_text(mlst, NO);
	if (!data->path_text[NORTH])
		return (1);
	data->path_text[SOUTH] =  get_path_text(mlst, SO);
	if (!data->path_text[SOUTH])
		return (1);
	data->path_text[WEST] =  get_path_text(mlst, WE);
	if (!data->path_text[WEST])
		return (1);
	data->path_text[EAST] =  get_path_text(mlst, EA);
	if (!data->path_text[EAST])
		return (1);
	return (0);	
}

static char	*get_path_text(t_mlst *mlst, char *coord)
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
