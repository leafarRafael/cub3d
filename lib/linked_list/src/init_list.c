/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 09:06:17 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/30 16:29:37 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_lst.h"

t_lst	*ft_init_lst(void)
{
	t_lst	*lst;

	lst = malloc(sizeof(t_lst));
	if (!lst)
		return (NULL);
	lst->head = NULL;
	lst->last = NULL;
	lst->is_space = 0;
	lst->size = 0;
	return (lst);
}
