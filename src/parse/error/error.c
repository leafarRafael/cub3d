/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 08:57:14 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/27 11:01:39 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "color.h"

const char	*msg_error(int error)
{
	static const char *msg[] = {"",
	"\nInvalid number of arguments.\n",
	"\nInvalid file extension.\n",
	"\nA text file is expected.\n",
	"\nFailed to open the configuration file.\n",
	"\nThe file is empty.\n"
	};
	return (msg[error]);
}

int	error_handler(const char *s1, const char *s2, const char *s3, const char *s4)
{
	if (s1)
		ft_putstr_fd(s1, 2);
	if (s2)
	{
		ft_putstr_fd(RED, 2);
		ft_putstr_fd(s2, 2);	
		ft_putstr_fd(RESET, 2);
	}
	if (s3)
		ft_putstr_fd(s3, 2);
	if (s4)
		ft_putstr_fd(s4, 2);
	return (1);
}