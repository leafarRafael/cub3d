/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:15:00 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/02 12:20:41 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include <../lib/MLX42/include/MLX42/MLX42.h>
#include "matrix_lst.h"

int is_new_line(char c)
{
	return (c == '\r' || c == '\n' || c == ' ' || c == '\t');
}

int	is_space_tab(int c)
{
	return (c == ' ' || c == '	');
}

int ft_color(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

int	is_coord(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

void put(t_mlst *mlst)
{
	int		i;
	t_llst	*llst;

	i = 0;
	llst = mlst->head;
	while(i < mlst->size)
	{
		ft_putlst_fd(llst->lst, 1, 2);
		llst = llst->next;
		i++;
	}
}
