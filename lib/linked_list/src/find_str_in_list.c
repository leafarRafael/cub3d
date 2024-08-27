/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_str_in_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:46:09 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/27 14:54:12 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_lst.h"
#include "libft.h"

int	ft_strlstcmp(t_lst *lst, char *str)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_cpy_lst_to_array(lst);
	i = ft_memcmp(new, str, ft_strlen(str));
	free(new);
	return (i);
}
