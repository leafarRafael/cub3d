/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 08:41:57 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/03 09:00:27 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

static t_data	*initialize_data(void);

t_data	*get_data(void)
{
	static t_data	*data = NULL;

	if (!data)
		data = initialize_data();
	return (data);
}

static t_data	*initialize_data(void)
{
	static t_data	data;
	static t_coord	coord;

	data.coord = &coord;
	return (&data);
}