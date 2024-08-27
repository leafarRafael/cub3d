/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:15:00 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/27 15:17:08 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>
#include <../lib/MLX42/include/MLX42/MLX42.h>
#include "matrix_lst.h"

int ft_color(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_putmtrx(t_mlst *mlst)
{
	int		i;
	t_llst	*temp;

	i = 0;
	temp = mlst->head;
	while (i < mlst->size)
	{
		ft_putlst_fd(temp->lst, 1, 2);
		temp = temp->next;
		i++;
	}
}

int	is_space(char c)
{
	return (c == '	' || c == ' ' || c == '\n' );
}