/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ceiling_floor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 08:40:01 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/30 10:44:04 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_lst.h"
#include "data.h"
#include "defines.h"
#include "utils.h"

static int	get_flor_ceiling(char c);
static int	set_atribute(t_atr *atr, t_lst *lst, t_data *data);

int	set_ceiling_floor(t_lst *lst, t_data *data)
{
	int	identifier;

	if (!is_space_tab(lst->head->next->c))
		return (ERROR);
	identifier = get_flor_ceiling(lst->head->c);
	if (identifier == FLOOR)
		return (set_atribute(&data->args_file[FLOOR], lst, data));
	if (identifier == CEILING)
		return (set_atribute(&data->args_file[CEILING], lst, data));
	return (ERROR);
}

static int	set_atribute(t_atr *atr, t_lst *lst, t_data *data)
{
	ft_remove_node_front(lst);
	while (lst->size && is_new_line(lst->head->c))
		ft_remove_node_front(lst);
	if (!lst->size)
		return (ERROR);
	atr->str = ft_cpy_lst_to_array(lst);
	if (!atr->str)
		return (ERROR);
	atr->status = 1;
	data->atr--;
	return (0);
}

static int	get_flor_ceiling(char c)
{
	if (c == 'F')
		return (FLOOR);
	if (c == 'C')
		return (CEILING);
	return (ERROR);
}