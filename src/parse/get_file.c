/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:05:01 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/27 17:45:58 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_lst.h"
#include "utils.h"
#include <stdlib.h>
#include "error.h"
#include "defines.h"
#include "libft.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

static int	clean_white_line(t_mlst *mlst);

t_mlst	*get_file(char *file)
{
	int		fd;
	char	*str;
	t_mlst	*meta_file;

	fd = open(file, O_RDONLY);
	if (fd == FAIL)
		return (NULL);
	meta_file = init_mlst();
	while ((str = get_next_line(fd)))
	{
		ft_add_list_back(meta_file, ft_create_lst_add_str(str));
		free(str);
	}
	clean_white_line(meta_file);
	if (meta_file->size <= MIN_NBR_OF_ELEMENTS)
	{
		ft_delete_matrix(meta_file);
		return (NULL);
	}
	return (meta_file);
}

static int	clean_white_line(t_mlst *mlst)
{
	t_llst		*lst;
	int			i;

	i = 0;
	lst = mlst->head;
	while (i < mlst->size)
	{
		if (lst->lst->last->c == '\n'
			|| lst->lst->last->c == '\r')
			lst_rmv_back(lst->lst);
		if (lst->lst->size <= 2)
		{
			ft_rmv_spcfc_lst_mtrx(mlst, lst);
			lst = mlst->head;
			i = 0;
		}
		else
		{
			lst = lst->next;
			i++;
		}
	}
	return (0);	
}

