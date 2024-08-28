/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_attr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:41:00 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/28 18:32:26 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "matrix_lst.h"
#include "defines.h"
#include "utils.h"

int		add_attr(t_lst *lst, t_data *data);

void	get_attr(t_mlst *mlst, t_data *data)
{
	t_llst			*temp;
	int				iter;
	int				status;

	iter = 0;
	temp = mlst->head;
	status = 0;
	data->atr = 6;
	while (iter < mlst->size)
	{
		status = add_attr(temp->lst, data);
		if (status == 1)
		{
			ft_rmv_spcfc_lst_mtrx(mlst, temp);
			iter = 0;
			temp = mlst->head;
		}
		temp = temp->next;
		iter++;
	}
}

int		add_attr(t_lst *lst, t_data *data)
{
	int	status;
	char	prefix[3];

	status = 0;
	while (lst->size && is_new_line(lst->head->c))
		ft_remove_node_front(lst);
	while (lst->size && is_new_line(lst->head->c))
		lst_rmv_back(lst);
	if (lst->size == 0)
		return (1);
	if (lst->size < 3)
		return (error_handler("ERROR\n", "Invalid identifier\n", NULL, NULL) + 20);
	prefix[0] = lst->head->c;
	prefix[1] = lst->head->next->c;
	prefix[2] = lst->head->next->next->c;
	if (prefix[2] != ' ' || prefix[2] != '\t' )
		return (error_handler("ERROR\n", "Invalid identifier\n", NULL, NULL) + 20);
	if (prefix[1] != ' ' || prefix[1] != '\t')
	{
		if (prefix[0] == F[0])
		{
			ft_remove_node_front(lst);
			ft_remove_node_front(lst);
			data->args_file[FLOOR].str = ft_cpy_lst_to_array(lst);
			data->args_file[FLOOR].status = 1;
		}
		else
		{
			ft_remove_node_front(lst);
			ft_remove_node_front(lst);
			data->args_file[CEILING].str = ft_cpy_lst_to_array(lst);
			data->args_file[CEILING].status = 1;
		}
	}
	return (0);
}
