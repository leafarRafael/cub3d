/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:38:12 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/04 13:53:02 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>

static int	valid_extension(char *file);
static int	valid_empty_and_permission(char *file);

int	valid_arguments(int argc, char **argv)
{
	if (argc != 2)
		return (ERROR);
	if (valid_extension(argv[1]))
		return (ERROR);
	if (valid_empty_and_permission(argv[1]))
		return (ERROR);
	return (SUCCESS);
}

static int	valid_empty_and_permission(char *file)
{
	int		fd;
	char	c;

	fd = open(file, O_RDONLY);
	if (fd == FAIL)
		return (ERROR);
	if (read(fd, &c, 1) == -1)
	{
		close(fd);
		return (ERROR);
	}
	close(fd);
	return (SUCCESS);
}

static int	valid_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < SIZE_EXT)
		return (ERROR);
	if (ft_strnstr(&file[len - SIZE_EXT], EXT, SIZE_EXT) == NULL)
		return (ERROR);
	return (SUCCESS);
}
