/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:12:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/03 08:35:25 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "defines.h"
#include <string.h>
#include <errno.h>
#include "matrix_lst.h"
#include "error_handler.h"

t_mlst *read_file(char *file)
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
	close (fd);
	return (mlst);
}
