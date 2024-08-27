/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 08:43:37 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/27 12:41:10 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "error.h"
#include "defines.h"
#include "libft.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static int valid_extension(char *file);
static int valid_text_file(char *file);
static int valid_permission_bytes_file(char *file);

int	valid_file(int argc, char *file)
{
	int status;

	if (argc != 2)
		return (E_ARG_INVNUM);
	if (!file)
		return (E_NOT_FOUND);
	if ((status = valid_extension(file)))
		return (status);
	if ((status = valid_permission_bytes_file(file)))
		return (status);
	if ((status = valid_text_file(file)))
		return (status);
	return (E_OK);
}

static int valid_extension(char *file)
{
	int len;

	len = ft_strlen(file);
	if (len < SIZE_EXTEN)
		return (E_ARG_INVEXT);
	if (ft_memcmp(EXTENSION, &file[len - SIZE_EXTEN], SIZE_EXTEN))
		return (E_ARG_INVEXT);
	return (E_OK);	
}

static int valid_text_file(char *file)
{
	int fd;

	fd = open(file, O_DIRECTORY);
	if (fd != FAIL)
	{
		close(fd);
		return (E_FILE_ISDIR);
	}
	return (E_OK);	
}

static int valid_permission_bytes_file(char *file)
{
	int		fd;
	char	c;

	fd = open(file, O_RDONLY);
	if (fd == FAIL)
		return (E_FILE_FAILOPEN);
	if (read(fd, &c, 1) == 0)
	{
		close(fd);
		return (E_FILE_EMPTY);
	}
	close(fd);
	return (E_OK);	
}
