/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:38:12 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/28 14:13:36 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "data.h"
#include "utils.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "defines.h"
#include <string.h>
#include <errno.h>

static void	valid_extension(char *file);
static void	valid_empty_and_permission(char *file);

void	valid_arguments(int argc, char **argv)
{
	if (argc != 2)
		exit (error_handler("ERROR\n", "nbr arguments invalid", "\n", NULL) + 2);
	valid_extension(argv[1]);
	valid_empty_and_permission(argv[1]);
}

static void	valid_empty_and_permission(char *file)
{
	int		fd;
	char	c;

	fd = open(file, O_RDONLY);
	if (fd == FAIL)
		exit(error_handler("ERROR\n", strerror(errno), "\n", NULL));
	if (read(fd, &c, 1) == -1)
		exit(error_handler("ERROR\n", "File is empty.", "\n", NULL) + close(fd) + 2);
	close(fd);
}

static void	valid_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < SIZE_EXT)
		exit(error_handler("ERROR\n", "Invalid file extension\n", "\n", NULL)+  2);
	if (ft_strnstr(&file[len - SIZE_EXT], EXT, SIZE_EXT) == NULL)
		exit(error_handler("ERROR\n", "Invalid file extension\n", "\n", NULL)+  2);
}