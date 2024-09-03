/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:41:59 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/03 12:41:17 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLER_H
# define ERROR_HANDLER_H

#define E_F_R_F "Fail to read file\n"
#define E_INDEN "Invalid indentifier\n"
#define E_RGB "Invalid color\n"
#define E_ARGS "Invalid arguments\n"
#define E_INVALID_MAP "Invalid map\n"
#define E_MEM "Memory error\n"
#define E_MLX "Instances png, window or image\n"
#define NBR_MSG 8

typedef struct s_data t_data;

int	error_handler(int e_error);
int	destroy_data(t_data *data);

typedef enum s_error
{
	E_OK = 0,
	E_ARGUMENTS,
	E_MEMORY,
	E_READ,
	E_IDENTIFIER,
	E_MAP,
	E_COLOR,
	E_MLX42,
	E_EMPYT,
}			t_error;

#endif