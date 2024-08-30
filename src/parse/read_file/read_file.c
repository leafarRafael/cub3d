/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:12:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/30 08:21:37 by rbutzke          ###   ########.fr       */
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

t_mlst *read_file(char *file)
{
	int		fd;
	char	*line;
	t_mlst	*mlst;


	fd = open(file, O_RDONLY);
	if (fd == FAIL)
		exit(error_handler("ERROR\n", strerror(errno), "\n", NULL));
	mlst = init_mlst();
	if (!mlst)
		exit(error_handler("ERROR\n", "fail to alloc\n", NULL, NULL));
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
