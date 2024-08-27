/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:39:28 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/27 12:35:15 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_lst.h"

int	ft_delete_list(t_lst *lst)
{
	if (lst == NULL)
		return (-1);
	while (lst->size > 0)
		lst_rmv_front(lst);
	free(lst);
	lst = NULL;
	return (0);
}
