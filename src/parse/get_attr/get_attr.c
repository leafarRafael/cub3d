/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_attr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:41:00 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/04 14:12:38 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "defines.h"
#include "matrix_lst.h"
#include "utils.h"
#include "get_attr.h"

static int	is_floor_ceiling(char c);
int			add_attr(t_lst *lst, t_data *data);

int	get_attr(t_mlst *mlst, t_data *data)
{
	int	status;

	status = 0;
	data->atr = 6;
	while (data->atr > 0 && mlst->size)
	{
		status = add_attr(mlst->head->lst, data);
		if (status == ERROR)
			return (ERROR);
		ft_remove_lst_front(mlst);
	}
	return (SUCCESS);
}

int	add_attr(t_lst *lst, t_data *data)
{
	while (lst->size && is_new_line(lst->head->c))
		ft_remove_node_front(lst);
	while (lst->size && is_new_line(lst->head->c))
		ft_remove_node_back(lst);
	if (lst->size == 0)
		return (1);
	if (lst->size < 3)
		return (ERROR);
	if (is_floor_ceiling(lst->head->c))
		return (set_ceiling_floor(lst, data));
	if (is_coord(lst->head->c))
		return (set_path_texture(lst, data));
	return (ERROR);
}

static int	is_floor_ceiling(char c)
{
	return (c == 'F' || c == 'C');
}
