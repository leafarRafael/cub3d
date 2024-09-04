/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:18:16 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/04 14:10:54 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "matrix_lst.h"
#include "utils.h"

static int	check_is_valid_char(char c);
static int	valid_line(t_lst *lst, int *nbr);

int	is_valid_map(t_mlst *mlst)
{
	int		i;
	int		nbr_player_pos;
	t_llst	*llst;

	while (mlst->size && mlst->head->lst->is_space == 0)
		ft_remove_lst_front(mlst);
	while (mlst->size && mlst->last->lst->is_space == 0)
		ft_remove_list_back(mlst);
	if (!mlst->size)
		return (ERROR);
	i = 0;
	llst = mlst->head;
	nbr_player_pos = 0;
	while (i < mlst->size)
	{
		if (valid_line(llst->lst, &nbr_player_pos))
			return (ERROR);
		llst = llst->next;
		if (llst->lst->is_space == 0)
			return (ERROR);
		i++;
	}
	if (nbr_player_pos != 1)
		return (ERROR);
	return (SUCCESS);
}

static int	valid_line(t_lst *lst, int *nbr)
{
	t_node	*node;
	int		i;

	i = 0;
	node = lst->head;
	while (i < lst->size)
	{
		if (!check_is_valid_char(node->c))
			return (1);
		if (is_coord(node->c))
			(*nbr)++;
		node = node->next;
		i++;
	}
	return (SUCCESS);
}

static int	check_is_valid_char(char c)
{
	return (is_coord(c) || is_new_line(c) || (c == '0' || c == '1'));
}
