/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 08:40:50 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/30 10:46:07 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_lst.h"
#include "data.h"
#include "defines.h"
#include "utils.h"
#include <stdio.h>

static int	set_path(t_atr *atr, t_lst *lst, t_data *data);
static int	get_coord(char c1, char c2);

int	set_path_texture(t_lst *lst, t_data *data)
{
	int	coord;

	if (!is_space_tab(lst->head->next->next->c))
		return (ERROR);
	coord = get_coord(lst->head->c, lst->head->next->c);
	if (coord == NORTH && &data->args_file[NORTH])
		return (set_path(&data->args_file[NORTH], lst, data));
	if (coord == SOUTH)
		return (set_path(&data->args_file[SOUTH], lst, data));
	if (coord == WEST)
		return (set_path(&data->args_file[WEST], lst, data));
	if (coord == EAST)
		return (set_path(&data->args_file[EAST], lst, data));
	return (ERROR);
}

static int	set_path(t_atr *atr, t_lst *lst, t_data *data)
{
	ft_remove_node_front(lst);
	ft_remove_node_front(lst);
	while (lst->size && is_new_line(lst->head->c))
		ft_remove_node_front(lst);
	if (!lst->size)
		return (ERROR);
	if (atr->str)
		return (ERROR);
	atr->str = ft_cpy_lst_to_array(lst);
	if (!atr->str)
		return (ERROR);
	atr->status = 1;
	data->atr--;
	return (0);
}

static int	get_coord(char c1, char c2)
{
	if (c1 == 'N' && c2 == 'O')
		return (NORTH);
	if (c1 == 'S' && c2 == 'O')
		return (SOUTH);
	if (c1 == 'W' && c2 == 'E')
		return (WEST);
	if (c1 == 'E' && c2 == 'A')
		return (EAST);
	return (ERROR);
}