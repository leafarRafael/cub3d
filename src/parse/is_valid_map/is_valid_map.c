/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:18:16 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/30 18:04:02 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_lst.h"
#include "defines.h"
#include <stdio.h>

static int	check_is_valid_char(char c);
static int	valid_line(t_lst *lst);

int	is_valid_map(t_mlst *mlst)
{
	int		i;
	t_llst	*llst;

	while (mlst->head->lst->is_space == 0)
		ft_remove_lst_front(mlst);
	while (mlst->last->lst->is_space == 0)
		ft_remove_list_back(mlst);
	i = 0;
	llst = mlst->head;
	while (i < mlst->size)
	{
		if (valid_line(llst->lst))
			return (ERROR);
		llst = llst->next;
		if (llst->lst->is_space == 0)
			return (ERROR);
		i++;
	}
	return (0);
}

static int	valid_line(t_lst *lst)
{
	t_node	*node;
	int		i;

	i = 0;
	node = lst->head;
	while (i < lst->size)
	{
		if (!check_is_valid_char(node->c))
			return (1);
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
		|| c == '\n');
}
