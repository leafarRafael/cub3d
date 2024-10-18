/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:12:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/04 14:06:29 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "matrix_lst.h"
#include "defines.h"
#include <fcntl.h>
#include <unistd.h>

t_mlst	*read_file(char *file)
{
	int		fd;
	char	*line;
	t_mlst	*mlst;

	fd = open(file, O_RDONLY);
	if (fd == FAIL)
		return (NULL);
	mlst = init_mlst();
	if (!mlst)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		ft_add_list_back(mlst, ft_create_lst_add_str(line));
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (mlst);
}
