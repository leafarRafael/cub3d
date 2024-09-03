/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:18:16 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/03 08:36:34 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_lst.h"
#include "defines.h"
#include <stdio.h>
#include "utils.h"
#include "error_handler.h"

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
	return (0);
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
	return (0);
}

static int	check_is_valid_char(char c)
{
	return (c == 'W'
		|| c == 'S'
		|| c == 'E'
		|| c == 'W'
		|| c == '0'
		|| c == '1'
		|| c == ' '
		|| c == '\t'
		|| c == '\r'
		|| c == '\n');
}
