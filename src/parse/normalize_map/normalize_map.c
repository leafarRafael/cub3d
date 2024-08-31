/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:40:44 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/31 16:12:46 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_lst.h"
#include "defines.h"
#include "utils.h"

static int	get_biggest_line(t_mlst *mlst);
static void	subs(t_lst *lst);
static void	normalize_line(t_lst *lst, int size);
// static void draw_bounds(t_mlst *mlst);

int	normalize(t_mlst *mlst)
{
	int		i;
	t_llst	*llst;
	int		size;

	// draw_bounds(mlst);
	size = get_biggest_line(mlst);
	i = 0;
	llst = mlst->head;
	while (i < mlst->size)
	{
		if (llst->lst->size <= size)
			normalize_line(llst->lst, size);
		subs(llst->lst);
		i++;
		llst = llst->next;
	}
	return (0);
}

static int	get_biggest_line(t_mlst *mlst)
{
	t_llst	*llst;
	int		i;
	int		size;

	i = 0;
	llst = mlst->head;
	size = llst->lst->size;
	while (i < mlst->size)
	{
		if (size < llst->lst->size)
			size = llst->lst->size;
		i++;
		llst = llst->next;
	}
	return (size);
}

static void	normalize_line(t_lst *lst, int size)
{
	if (is_new_line(lst->last->c))
		lst->last->c = '#';
	while (lst->size <= size)
		ft_create_node_add_back(lst, '#');

}

static void	subs(t_lst *lst)
{
	int		i;
	t_node	*node;

	i = 0;
	node = lst->head;
	while (i < lst->size)
	{
		if (is_new_line(node->c))
			node->c = '#';
		node = node->next;
		i++;
	}
}

// static void draw_bounds(t_mlst *mlst)
// {
// 	t_llst	*llst;
// 	int		i;

// 	ft_add_list_front(mlst, ft_duplst(mlst->head->lst, ft_cpynode, ft_add_node_back));
// 	ft_add_list_back(mlst, ft_duplst(mlst->head->lst, ft_cpynode, ft_add_node_back));
// 	i = 0;
// 	llst = mlst->head;
// 	while (i < mlst->size)
// 	{
// 		ft_create_add_node_front(llst->lst, '#');
// 		ft_create_node_add_back(llst->lst, '#');
// 		i++;
// 		llst = llst->next;
// 	}
// }